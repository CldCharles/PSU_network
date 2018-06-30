/*
** EPITECH PROJECT, 2018
** setteam_player.c
** File description:
** HA my setteam_player.c
*/

#include "server.h"

void fill_coord(server_t *srv, player_t *tmp, int team)
{
	if (srv->team[team].player_inteam <= srv->nb_client) {
		tmp->x = rand() % srv->width;
		tmp->y = rand() % srv->height;
	}
	else {
		tmp->x = srv->team[team].egg->x;
		tmp->y = srv->team[team].egg->y;
		remove_egg(srv, team);
	}
}

void player_placement(server_t *srv, int fd, int team)
{
	player_t *tmp = srv->team[team].player;

	while (tmp) {
		if (tmp->fd == fd)
			break;
	}
	if (tmp == NULL)
		return;
	fill_coord(srv, tmp, team);
	tmp->axe = (rand() % 4) + 1;
	memset(tmp->inv, 0, sizeof(char) * 7);
	tmp->inv[0] = 10;
	tmp->life = 0;
	add_tiles_player(srv, fd, tmp->x, tmp->y);
	dprintf(fd, "%d\n", srv->nb_client
		+ srv->team[team].fork
		- srv->team[team].player_inteam);
	dprintf(fd, "%d %d\n", srv->width, srv->height);
}

player_t *remove_from_root(server_t *srv, int fd)
{
	player_t *tmp;
	player_t *tmpp;

	tmp = srv->team[srv->nb_team].player;
	tmpp = NULL;
	while (tmp) {
		if (tmp->fd == fd) {
			if (tmpp == NULL)
				srv->team[srv->nb_team].player = tmp->next;
			else
				tmpp->next = tmp->next;
			srv->team[srv->nb_team].player_inteam--;
			return (tmp);
		}
		tmpp = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

void graphic_set(server_t *srv, int fd)
{
	srv->gui_fd = fd;
}

int check_move_player(server_t *srv, int fd, char **com)
{
	int i = 0;
	player_t *player;

	if (strcmp(com[0], "graphicGUI") == 0) {
		graphic_set(srv, fd);
		return (1);
	}
	for (i = 0; i < srv->nb_team; i++)
		if (strcmp(srv->team[i].name, com[0]) == 0)
			break;
	if (srv->nb_team == i)
		return (0);
	player = remove_from_root(srv, fd);
	if (player == NULL)
		return (0);
	if (srv->team[i].player_inteam == (srv->nb_client + srv->team[i].fork))
		return (0);
	place_player(srv, player, fd, i);
	return (1);
}
