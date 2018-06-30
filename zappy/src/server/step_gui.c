/*
** EPITECH PROJECT, 2018
** step_gui
** File description:
** step_gui.c
*/

#include "server.h"

void step_one(server_t *srv, char **tiles_data)
{
	char map_size[40] = {0};

	sprintf(map_size, "%d\n%d\n", srv->width, srv->height);
	strcat(*tiles_data, map_size);
}

void second_step(server_t *srv, char **tiles_data, char *src)
{
	for (int x = 0; x < srv->width; x++) {
		for (int y = 0; y < srv->height; y++) {
			fill_loot(srv, x, y, src);
			strcat(*tiles_data, src);
		}
	}
	strcat(*tiles_data, "\n");
}

void third_step(server_t *srv, char **tiles_data, char *src)
{
	player_t *tmp;

	for (int i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			sprintf(src, "%d %d %d %d %d %d %d %d %d %d %d|",
				tmp->x, tmp->y, tmp->axe, tmp->lvl,
				tmp->inv[0], tmp->inv[1], tmp->inv[2],
				tmp->inv[3], tmp->inv[4],
				tmp->inv[5], tmp->inv[6]);
			strcat(*tiles_data, src);
			tmp = tmp->next;
		}
	}
}
