/*
** EPITECH PROJECT, 2018
** life_decay
** File description:
** life_decay.c
*/

#include "server.h"

void life_decay_bis(server_t *srv, player_t *tmp, int i)
{
	if (check_time(tmp->life, LIFE_UNIT, srv->f) ==
	1 && tmp->inv[0] > 0) {
		tmp->life = current_timestamp();
		tmp->inv[0]--;
	}
	else if (check_time(tmp->life, LIFE_UNIT, srv->f) ==
		1 && tmp->inv[0] <= 0) {
		t_mort(srv, tmp, i);
	}
}

void life_decay(server_t *srv)
{
	player_t *tmp;
	int i;

	for (i = 0; i < srv->nb_team; i++) {
		for (tmp = srv->team[i].player; tmp; tmp = tmp->next)
			life_decay_bis(srv, tmp, i);
	}
	regen_food(srv);
}
