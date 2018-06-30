/*
** EPITECH PROJECT, 2018
** look.c
** File description:
** HA my look.c
*/

#include "server.h"

void look_horizontal(server_t *srv, player_t *tmp, char b, char *rep)
{
	int i = 0;
	int len = 0;
	int u = 0;
	int x = 0;
	int y = 0;

	fill_look(srv, tmp->x, tmp->y, rep);
	for (i = 1; i < tmp->lvl + 1; i++) {
		len = (i * 2) + 1;
		x = (srv->width + (tmp->x - (i) * b)) % srv->width;
		for (u = 0; u < len; u++) {
			y = ((srv->height +
			(tmp->y - (len / 2) * (b * -1)))
			+ u * (b * -1))	% srv->height;
			fill_look(srv, x, y, rep);
		}
	}
}

void look_vertical(server_t *srv, player_t *tmp, char b, char *rep)
{
	int len = 0;
	int u = 0;
	int x = 0;
	int y = 0;
	int i = 0;

	fill_look(srv, tmp->x, tmp->y, rep);
	for (i = 1; i < tmp->lvl + 1; i++) {
		len = (i * 2) + 1;
		y = (srv->height + (tmp->y - (i) * b)) % srv->height;
		for (u = 0; u < len; u++) {
			x = ((srv->width +
			(tmp->x - (len / 2) * b)) + u * b)
				% srv->width;
			fill_look(srv, x, y, rep);
		}
	}
}

player_t *get_look(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void look(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	player_t *tmp = NULL;
	int casee = 0;
	char rep[4096] = {0};

	for (int i = 0; i < srv->nb_team; i++)
		tmp = get_look(srv, tmp, fd, &i);
	if (tmp == NULL)
		return;
	for (int i = 0; i < tmp->lvl + 1; i++)
		casee += (i * 2) + 1;
	if (tmp->axe == 1 || tmp->axe == 3)
		look_vertical(srv, tmp, (tmp->axe == 1 ? 1 : -1), rep);
	else if  (tmp->axe == 2 || tmp->axe == 4)
		look_horizontal(srv, tmp, (tmp->axe == 2 ? -1 : 1), rep);
	rep[0] = '[';
	dprintf(tmp->fd, "%s]\n", rep);
}
