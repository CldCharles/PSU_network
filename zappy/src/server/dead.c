/*
** EPITECH PROJECT, 2018
** dead
** File description:
** dead.c
*/

#include "server.h"

void t_mort(server_t *srv, player_t *tmp, int i)
{
	if (srv->team[i].fork > 0)
		srv->team[i].fork--;
	remove_player(srv, tmp->fd);
	dprintf(tmp->fd, "dead\n");
	close(tmp->fd);
}
