/*
** EPITECH PROJECT, 2018
** eejct.c
** File description:
** HA my eject.c
*/

#include "server.h"

player_t *get_eject(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void eject(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++)
		tmp = get_eject(srv, tmp, fd, &i);
	if (tmp == NULL)
		return;
	for (i = 0; srv->map[tmp->x][tmp->y].plr[i] != -1; i++)
		if (srv->map[tmp->x][tmp->y].plr[i] != fd)
			forward(srv, srv->map[tmp->x][tmp->y].plr[i], NULL);
	if (i == 1)
		dprintf(tmp->fd, "ko\n");
	else
		dprintf(tmp->fd, "ok\n");
}
