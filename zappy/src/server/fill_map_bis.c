/*
** EPITECH PROJECT, 2018
** fill_map_bis
** File description:
** fill_map_bis.c
*/

#include "server.h"

void fill_more_bis(server_t *srv, int j, int i)
{
	int x = 0;
	int y = 0;

	if (j >= res_count[1][i] &&
	j < res_count[2][i]) {
		x = rand() % srv->width;
		y = rand() % srv->height;
		srv->map[x][y].loot[i + 1] += 1;
	}
}
