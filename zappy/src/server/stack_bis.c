/*
** EPITECH PROJECT, 2018
** stack_bis
** File description:
** stack_bis.c
*/

#include "server.h"

int get_tic_func(server_t *srv, player_t *tmp, int i)
{
	for (i = 0; fptr[i].name != NULL; i++) {
		if (strcasecmp(fptr[i].name, tmp->stack->cmd) == 0) {
			fptr[i].func(srv, tmp->fd, tmp->stack->arg);
			stack_pull(srv, tmp->fd);
			new_stack_head(srv, tmp);
			break;
		}
	}
	return (i);
}

void process_ticbis(server_t *srv, player_t *tmp, int i)
{
	if (tmp->stack && check_time(tmp->tic_start,
				tmp->stack->time,
				srv->f) == 1) {
		i = get_tic_func(srv, tmp, i);
	}
	if (fptr[i].name == NULL) {
		dprintf(tmp->fd, "ko\n");
		printf("Unknow command: %s from player %d\n"
		, tmp->stack->cmd, tmp->fd);
		stack_pull(srv, tmp->fd);
		new_stack_head(srv, tmp);
	}
}

void process_tic(server_t *srv, player_t *tmp)
{
	int i = 0;

	if (tmp->stack && tmp->tic_start == 0) {
		if (strcasecmp(tmp->stack->cmd, fptr[9].name) == 0)
			new_stack_head(srv, tmp);
		else
			tmp->tic_start = current_timestamp();
	}
	if (tmp->start_incant != 0 && check_time(tmp->start_incant
						, 300, srv->f) == 1) {
		fptr[9].func(srv, tmp->fd, "\0");
	}
	process_ticbis(srv, tmp, i);
}
