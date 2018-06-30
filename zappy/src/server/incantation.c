/*
** EPITECH PROJECT, 2018
** incantation.c
** File description:
** HA my incantation.c
*/

#include "server.h"

int check_player(server_t *srv, int x, int y, int lvl)
{
	int pok = 0;
	int i;

	for (i = 0; srv->map[x][y].plr[i] != -1; i++) {
		if (retrieve_lvl(srv, srv->map[x][y].plr[i]) == lvl)
			pok++;
	}
	if (pok != lvlup[lvl - 1][0])
		return (-1);
	return (0);
}

int check_res(server_t *srv, int x, int y, int lvl)
{
	int i;

	for (i = 1; i < 7; i++) {
		if (srv->map[x][y].loot[i] != lvlup[lvl - 1][i])
			return (-1);
	}
	return (0);
}

void despawn_res(server_t *srv, int x, int y, int lvl)
{
	int i;

	for (i = 1; i < 7; i++)
		srv->map[x][y].loot[i] -= lvlup[lvl - 1][i];
}

player_t *get_incant(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void incantation(server_t *srv, int fd, char *arg)
{
	int i = 0;
	player_t *tmp = NULL;

	(void)arg;
	for (i = 0; i < srv->nb_team; i++)
		tmp = get_incant(srv, tmp, fd, &i);
	if (tmp == NULL)
		return;
	if ((incantation_bis(srv, tmp, fd, i)) == 1)
		return;
}
