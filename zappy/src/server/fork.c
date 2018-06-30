/*
** EPITECH PROJECT, 2018
** fork.c
** File description:
** HA mt fork.c
*/

#include "server.h"

void add_egg(server_t *srv, int i, player_t *tmp)
{
	egg_t *new = malloc(sizeof(egg_t));

	new->x = tmp->x;
	new->y = tmp->y;
	new->next = srv->team[i].egg;
	srv->team[i].egg = new;
}

void remove_egg(server_t *srv, int i)
{
	egg_t *tmp = srv->team[i].egg;

	srv->team[i].egg = tmp->next;
	free(tmp);
}

void get_fork(server_t *srv, player_t *tmp, int fd, int i)
{
	if (tmp->fd == fd) {
		add_egg(srv, i, tmp);
		srv->team[i].fork++;
		dprintf(tmp->fd, "ok\n");
	}
}

void ffork(server_t *srv, int fd, char *arg)
{
	int i;
	player_t *tmp;

	(void)arg;
	for (i = 0; i < srv->nb_team; i++) {
		for (tmp = srv->team[i].player; tmp; tmp = tmp->next)
			get_fork(srv, tmp, fd, i);
	}
}
