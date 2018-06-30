/*
** EPITECH PROJECT, 2018
** fill_map.c
** File description:
** HA my fill_map.c
*/

#include "server.h"

int enought_hole_food(server_t *srv)
{
	int i = 0;
	int u = 0;
	int cpt = 0;

	for (i = 0; i < srv->width; i++) {
		for (u = 0; u < srv->height; u++)
			cpt = (srv->map[i][u].loot[0] == 0 ? cpt + 1 : cpt);
	}
	if (cpt < (srv->width * srv->height) / 10 * 9)
		return (0);
	return (1);
}

void fill_food(server_t *srv)
{
	int x = 0;
	int y = 0;
	int cpt = 0;

	while (cpt < (srv->width * srv->height) / 50) {
		x = rand() % srv->width;
		y = rand() % srv->height;
		srv->map[x][y].loot[0] += 1;
		cpt++;
	}
	if (enought_hole_food(srv))
		fill_food(srv);
}

int enought_hole(server_t *srv)
{
	int i = 0;
	int u = 0;
	int cpt = 0;
	char *tmp = calloc(sizeof(char), 6);

	for (i = 0; i < srv->width; i++) {
		for (u = 0; u < srv->height; u++)
			cpt = (strncmp(tmp, (srv->map[i][u].loot) + 1, 6)
			== 0 ? cpt + 1 : cpt);
	}
	free(tmp);
	if (cpt < (srv->width * srv->height) / 10 * 3)
		return (0);
	return (1);
}

void fill_more(server_t *srv)
{
	int i = 0;
	int cpt = 0;
	int y = 0;

	while (cpt < (srv->width * srv->height) / 50) {
		y = rand() % 100;
		for (i = 0; i < 6; i++)
			fill_more_bis(srv, y, i);
		cpt++;
	}
	if (enought_hole(srv))
		fill_more(srv);
}

void fill_map(server_t *srv)
{
	int i = 0;
	int u = 0;
	int x = 0;
	int y = 0;

	for (i = 0; i < srv->width; i++)
		for (u = 0; u < srv->height; u++) {
			srv->map[i][u].plr = NULL;
			memset(srv->map[i][u].loot, 0, 7);
		}
	for (i = 0; i < 6; i++)
		for (u = 0; u < RES(res_count[0][i], srv->nb_team); u++) {
			x = rand() % srv->width;
			y = rand() % srv->height;
			srv->map[x][y].loot[i + 1] += 1;
		}
	fill_more(srv);
	fill_food(srv);
}
