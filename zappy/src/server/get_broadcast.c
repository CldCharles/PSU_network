/*
** EPITECH PROJECT, 2018
** get_broadcast.c
** File description:
** get_broadcast.c
*/

#include "server.h"

player_t *get_broadcast(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}
