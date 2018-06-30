/*
** EPITECH PROJECT, 2018
** interact.c
** File description:
** HA my interact.c
*/

#include "server.h"

player_t *get_take(server_t *s, player_t *t, int fd, int *i)
{
	for (t = s->team[*i].player; t; t = t->next) {
		if (t->fd == fd) {
			*i = s->nb_team;
			break;
		}
	}
	return (t);
}

void take(server_t *s, int fd, char *a)
{
	player_t *t;

	for (int i = 0; i < s->nb_team; i++)
		t = get_take(s, t, fd, &i);
	for (int i = 0; i < 7; i++) {
		if (!strcmp(a, res_tab[i]) && s->map[t->x][t->y].loot[i] > 0) {
			s->map[t->x][t->y].loot[i] -= 1;
			t->inv[i] += 1;
			dprintf(t->fd, "ok\n");
			return;
		}
	}
	dprintf(t->fd, "ko\n");
}

player_t *get_set(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void set(server_t *srv, int fd, char *arg)
{
	player_t *tmp;

	for (int i = 0; i < srv->nb_team; i++)
		tmp = get_set(srv, tmp, fd, &i);
	for (int i = 0; i < 7; i++) {
		if (strcmp(arg, res_tab[i]) == 0 && tmp->inv[i] > 0) {
			tmp->inv[i] -= 1;
			srv->map[tmp->x][tmp->y].loot[i] += 1;
			dprintf(tmp->fd, "ok\n");
			return;
		}
	}
	dprintf(tmp->fd, "ko\n");
}
