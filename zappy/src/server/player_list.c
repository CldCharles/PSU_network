/*
** EPITECH PROJECT, 2018
** player_list.c
** File description:
** HA my player_list.c
*/

#include "server.h"

team_t remove_player_bis(team_t j, player_t *tmp, player_t *tmpp, int fd)
{
	if (tmp->fd == fd) {
		if (tmpp == NULL)
			j.player = tmp->next;
		else
			tmpp->next = tmp->next;
		j.player_inteam--;
		return (j);
	}
	return (j);
}

void remove_player(server_t *srv, int fd)
{
	player_t *tmp;
	player_t *tmpp;

	for (int i = 0; i < srv->nb_team + 1; i++) {
		tmp = srv->team[i].player;
		tmpp = NULL;
		while (tmp) {
			srv->team[i] = remove_player_bis(srv->team[i],
							tmp, tmpp, fd);
			tmpp = tmp;
			tmp = tmp->next;
		}
	}
}

void add_player(server_t *srv, int fd)
{
	player_t *new;
	int i = srv->nb_team;

	if (fd == 0)
		return;
	new = malloc(sizeof(player_t));
	if (new == NULL)
		return;
	new->fd = fd;
	new->lvl = 1;
	new->tic_start = 0;
	new->start_incant = 0;
	new->stack = NULL;
	new->next = srv->team[i].player;
	srv->team[i].player = new;
	srv->team[i].player_inteam++;
	dprintf(fd, "WELCOME\n");
}
