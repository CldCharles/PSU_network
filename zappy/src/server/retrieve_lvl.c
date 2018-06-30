/*
** EPITECH PROJECT, 2018
** retrieve_lvl
** File description:
** retrieve_lvl.c
*/

#include "server.h"

int retrieve_lvl_bis(server_t *srv, int fd, int i)
{
	player_t *tmp;

	for (tmp = srv->team[i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd)
			return (tmp->lvl);
	}
	return (0);
}

int retrieve_lvl(server_t *srv, int fd)
{
	int i;
	int res;

	for (i = 0; i < srv->nb_team; i++) {
		res = retrieve_lvl_bis(srv, fd, i);
		if (res)
			return (res);
	}
	return (0);
}

void set_newlvl_bis(player_t *tmp, int fd)
{
	if (tmp->fd == fd)
		tmp->lvl += 1;
}

void set_newlvl(server_t *srv, int fd)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		for (; tmp; tmp = tmp->next)
			set_newlvl_bis(tmp, fd);
	}
}
