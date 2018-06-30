/*
** EPITECH PROJECT, 2018
** left
** File description:
** left.c
*/

#include "server.h"

void get_left(player_t *tmp, int fd)
{
	if (tmp->fd == fd) {
		tmp->axe = ((tmp->axe - 2 + 4) % 4) + 1;
		dprintf(fd, "ok\n");
	}
}

void left(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			get_left(tmp, fd);
			tmp = tmp->next;
		}
	}
}
