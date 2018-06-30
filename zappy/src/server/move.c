/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** HA my move.c
*/

#include "server.h"

void forwardd(server_t *srv, player_t *tmp, int fd)
{
	if (tmp->axe == 1 || tmp->axe == 3) {
		remove_tiles_player(srv, fd, tmp->x, tmp->y);
		tmp->y = (tmp->y +
			(tmp->axe == 3 ? 1 : -1) +
			srv->height) % srv->height;
		add_tiles_player(srv, fd, tmp->x, tmp->y);
	}
	else if (tmp->axe == 2 || tmp->axe == 4) {
		remove_tiles_player(srv, fd, tmp->x, tmp->y);
		tmp->x = (tmp->x +
			(tmp->axe == 2 ? 1 : -1) +
			srv->width) % srv->width;
		add_tiles_player(srv, fd, tmp->x, tmp->y);
	}
}

player_t *get_forward(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void forward(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++)
		tmp = get_forward(srv, tmp, fd, &i);
	if (tmp == NULL)
		return;
	forwardd(srv, tmp, fd);
	if (arg == NULL)
		dprintf(fd, "eject: %d\n", 5);
	else
		dprintf(fd, "ok\n");
}
