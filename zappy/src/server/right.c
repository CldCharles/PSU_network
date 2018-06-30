/*
** EPITECH PROJECT, 2018
** right
** File description:
** right.c
*/

#include "server.h"

void get_right(player_t *tmp, int fd)
{
	if (tmp->fd == fd) {
		tmp->axe = ((tmp->axe) % 4) + 1;
		dprintf(fd, "ok\n");
	}
}

void right(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			get_right(tmp, fd);
			tmp = tmp->next;
		}
	}
}
