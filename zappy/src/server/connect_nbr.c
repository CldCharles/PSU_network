/*
** EPITECH PROJECT, 2018
** connect_nbr
** File description:
** connect_nbr.c
*/

#include "server.h"

void get_connect_nbr(server_t *srv, player_t *tmp, int fd, int i)
{
	if (tmp->fd == fd) {
		dprintf(fd, "%d\n", srv->nb_client
			+ srv->team[i].fork
			- srv->team[i].player_inteam);
	}
}

void connect_nbr(server_t *srv, int fd, char *arg)
{
	player_t *tmp = NULL;

	(void)arg;
	for (int i = 0; i < srv->nb_team; i++) {
		for (tmp = srv->team[i].player; tmp; tmp = tmp->next)
			get_connect_nbr(srv, tmp, fd, i);
	}
}
