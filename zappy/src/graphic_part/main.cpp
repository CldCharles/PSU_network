//
// EPITECH PROJECT, 2018
// main
// File description:
// main.cpp
//

#include "graphic_part.hpp"
#include "Connection.hpp"

int usage()
{
	std::cout << "USAGE: ./zappy_graph addr port" << std::endl;
	return 84;
}

int init_data(data_t *data)
{
	data->map = (tiles_t **)malloc(sizeof(tiles_t) * data->width);
	if (data->map == NULL)
		return 84;
	for (int i = 0; i < data->width; i++) {
		data->map[i] = (tiles_t *)malloc(sizeof(tiles_t) * data->height);
		if (data->map[i] == NULL)
			return 84;
	}
	return 0;
}

int fill_player_data(data_t *data, char **player_data)
{
	char **player;
	int nb_player = 0;
	data->player = (player_t *)malloc(sizeof(player_t));
	player_t *tmp = data->player;

	for (nb_player = 0; player_data[nb_player]; nb_player++) {}
	for (int i = 1; i < nb_player; i++) {
		tmp->next = (player_t *)malloc(sizeof(player_t));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp = data->player;
	for (int j = 0; tmp; tmp = tmp->next, j++) {
		player = my_str_split(player_data[j], ' ');
		tmp->x = atoi(player[0]);
		tmp->y = atoi(player[1]);
		tmp->axe = atoi(player[2]);
		tmp->lvl = atoi(player[3]);
		tmp->inv[0] = atoi(player[4]);
		tmp->inv[1] = atoi(player[5]);
		tmp->inv[2] = atoi(player[6]);
		tmp->inv[3] = atoi(player[7]);
		tmp->inv[4] = atoi(player[8]);
		tmp->inv[5] = atoi(player[9]);
		tmp->inv[6] = atoi(player[10]);
	}
	return (0);
}

int fill_data(data_t *data, char **map_data)
{
	char **tiles_data;
	int i = 0;
	
	for (int x = 0; x < data->height; x++) {
		for (int y = 0; y < data->width; y++) {
			tiles_data = my_str_split(map_data[i], ' ');
			data->map[x][y].loot[0] = atoi(tiles_data[0]);
			data->map[x][y].loot[1] = atoi(tiles_data[1]);
			data->map[x][y].loot[2] = atoi(tiles_data[2]);
			data->map[x][y].loot[3] = atoi(tiles_data[3]);
			data->map[x][y].loot[4] = atoi(tiles_data[4]);
			data->map[x][y].loot[5] = atoi(tiles_data[5]);
			data->map[x][y].loot[6] = atoi(tiles_data[6]);
			data->map[x][y].egg = atoi(tiles_data[7]);
			i++;
		}
	}
	return (0);
}

int first_step(client_t *client)
{
	char *buffer = (char *)malloc(100000);
	int size = 0;

	if (buffer == NULL)
		return 84;
	memset(buffer, 0, 100000);
	size = read(client->socket, buffer, 100000);
	if (size == 0)
		exit(0);
	if (size == -1)
		return 84;
	if (strcmp("WELCOME\n", buffer) == 0)
		dprintf(client->socket, "graphicGUI\n");
	return (0);
}

int second_step(client_t *client, data_t *data)
{
	char *buffer;
	size_t size = 0;
	char **tab;
	char **map_data;
	char **player_data;

	buffer = (char *)malloc(100000);
	memset(buffer, 0, 100000);
	size = read(client->socket, buffer, 100000);
	if (size == 0)
		exit(0);
	if (size == -1)
		return 84;
	tab = my_str_split(buffer, '\n');
	data->height = atoi(tab[0]);
	data->width = atoi(tab[1]);
	if (atoi(tab[0]) != atoi(tab[1]))
		exit(84);
	if (atoi(tab[0]) > 40 || atoi(tab[1]) > 40)
		exit(84);
	if (init_data(data) == 84)
		return 84;
	map_data = my_str_split(tab[2], '|');
	fill_data(data, map_data);
	if (tab[3][0]) {
		player_data = my_str_split(tab[3], '|');
		fill_player_data(data, player_data);
	}
	return 0;
}

int get_welcome(client_t *client, data_t *data)
{
	char *buffer = (char *)calloc(sizeof(char), 10);
	size_t size = 0;

	if ((first_step(client)) == 84)
		return 84;
	if ((second_step(client, data)) == 84)
		return 84;
	Graphic *graph = new Graphic(data->width, data->height);
	graph->Gameloop(client, data);
	return 0;
}

int check_main(int ac, char **av)
{
	if ((ac == 2 && !strcmp("-help", av[1])) || ac != 3)
		return usage();
	return 0;
}

int main(int ac, char **av)
{
	client_t client;
	data_t data;

	memset(&client, 0, sizeof(client));
	memset(&data, 0, sizeof(data));
	if (check_main(ac, av) == 84)
		return 84;
	if ((init_graphic_client(&client, ac, av)) == 84)
		return 84;
	if ((get_welcome(&client, &data)) == 84)
		return 84;
	return (0);
}
