/*
** EPITECH PROJECT, 2018
** do_stack.c
** File description:
** HA my do_stack.c
*/

#include "server.h"

int new_stack_headbis(int r, server_t *srv, player_t *tmp)
{
	if (strcasecmp(fptr[9].name, tmp->stack->cmd) == 0 &&
	tmp->start_incant == 0) {
		r += check_res(srv, tmp->x, tmp->y, tmp->lvl);
		r += check_player(srv, tmp->x, tmp->y, tmp->lvl);
		if (r < 0)
			dprintf(tmp->fd, "ko\n");
		else
			tmp->start_incant = current_timestamp();
		stack_pull(srv, tmp->fd);
		new_stack_head(srv, tmp);
		return (1);
	}
	else if (strcasecmp(fptr[9].name, tmp->stack->cmd) == 0 &&
		tmp->start_incant != 0) {
		dprintf(tmp->fd, "ko\n");
		stack_pull(srv, tmp->fd);
		new_stack_head(srv, tmp);
		return (1);
	}
	return (0);
}

void new_stack_head(server_t *srv, player_t *tmp)
{
	int i;
	int ret = 0;

	if (tmp->stack) {
		for (i = 0; fptr[i].name != NULL; i++) {
			if ((new_stack_headbis(ret, srv, tmp)) == 1)
				return;
			if (strcasecmp(fptr[i].name, tmp->stack->cmd) == 0)
				tmp->tic_start = current_timestamp();
		}
	}
	else
		tmp->tic_start = 0;
}

void purge_stack(server_t *srv)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++) {
		for (tmp = srv->team[i].player; tmp; tmp = tmp->next) {
			process_tic(srv, tmp);
		}
	}
}
