/*
** EPITECH PROJECT, 2018
** incantation_bis
** File description:
** incantation_bis.c
*/

#include "server.h"

int incantation_bis(server_t *srv, player_t *tmp, int fd, int i)
{
	i = 0;
	i += check_res(srv, tmp->x, tmp->y, tmp->lvl);
	i += check_player(srv, tmp->x, tmp->y, tmp->lvl);
	if (i == -1 || i == -2) {
		dprintf(fd, "ko\n");
		set_lvl_stay(srv, tmp->x, tmp->y, tmp->lvl);
		return (1);
	}
	tmp->lvl += 1;
	tmp->start_incant = 0;
	set_lvl_up(srv, tmp->x, tmp->y, tmp->lvl - 1);
	despawn_res(srv, tmp->x, tmp->y, tmp->lvl - 1);
	dprintf(fd, "elevation underway current level: %d\n", tmp->lvl);
	return (0);
}
