/*
** EPITECH PROJECT, 2018
** regen_food.c
** File description:
** HA my regen_food.c
*/

#include "server.h"

float count_player(server_t *srv)
{
	int i;
	int count = 0.0f;

	for (i = 0; i < srv->nb_team; i++) {
		count += (float)srv->team[i].player_inteam;
	}
	if (count == 0)
		count = 1;
	return (count);
}

void regen_food(server_t *srv)
{
	float tic = 0;
	int x = 0;
	int y = 0;
	float tmp = 0;

	tic = (1.0f / (count_player(srv) / (float)LIFE_UNIT));
	tic = (tic - ((tic / 100)) * 8);
	tic = tic / srv->f;
	tmp = (float)(current_timestamp() - srv->cpt_tic) / 1000.0f;
	if (tmp >= tic) {
		x = rand() % srv->width;
		y = rand() % srv->height;
		srv->map[x][y].loot[0] += 1;
		srv->cpt_tic = current_timestamp();
	}
}
