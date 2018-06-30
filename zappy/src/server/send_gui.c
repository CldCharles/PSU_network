/*
** EPITECH PROJECT, 2018
** send_gui.c
** File description:
** HA my send_gui.c
*/

#include <stdbool.h>
#include "server.h"

int count_size(server_t *srv)
{
	player_t *tmp;
	int size = 0;
	int i = 0;
	int j = 0;

	for (int x = 0; x < srv->width; x++)
		for (int y = 0; y < srv->height; y++)
			i++;
	for (int i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			j++;
			tmp = tmp->next;
		}
	}
	size = (i * 40) + (j * 70) + 45;
	return (size);
}

void fill_loot(server_t *srv, int x, int y, char *src)
{
	int loot[7];
	char eggs = 0;

	for (int i = 0; i < 7; i++)
		loot[i] = 0;
	for (int u = 0; u < 7; u++)
		loot[u] = srv->map[x][y].loot[u];
	sprintf(src, "%d %d %d %d %d %d %d %d|",
		loot[0], loot[1], loot[2], loot[3],
		loot[4], loot[5], loot[6], eggs);
}

void set_gui(server_t *srv)
{
	char *tiles_data;
	char *src;
	int size;

	if (srv->gui_fd == 0 || srv->width > 100 || srv->height > 100)
		return;
	size = count_size(srv);
	tiles_data = malloc(size + 1);
	src = malloc(size + 1);
	memset(src, 0, size + 1);
	memset(tiles_data, 0, size + 1);
	step_one(srv, &tiles_data);
	second_step(srv, &tiles_data, src);
	third_step(srv, &tiles_data, src);
	strcat(tiles_data, "\n");
	sprintf(src, "%d\n", size + 1);
	strcat(tiles_data, src);
	write(srv->gui_fd, tiles_data, strlen(tiles_data));
	free(tiles_data);
	free(src);
}

void delay_gui(server_t *srv)
{
	float tmp = 0;
	player_t *tmpp;

	for (int i = 0; i < srv->nb_team; i++) {
		tmpp = srv->team[i].player;
		printf("----------------------------\n");
		while (tmpp) {
			printf("x=%d y=%d lvl=%d food = %d\n",
			tmpp->x, tmpp->y, tmpp->lvl, tmpp->inv[0]);
			tmpp = tmpp->next;
		}
	}
	tmp = (float)(current_timestamp() - srv->gui_tic) / 1000.f;
	if (tmp >= srv->gui / 1000.0f) {
		set_gui(srv);
		srv->gui_tic = current_timestamp();
	}
}
