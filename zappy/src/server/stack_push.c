/*
** EPITECH PROJECT, 2018
** stack_push
** File description:
** stack_push.c
*/

#include "server.h"

player_t *get_stack_push(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void stack_push_bis(player_t *tmp, sstack_t *new)
{
	int i = 0;
	sstack_t *tmps;

	for (i = 0, tmps = tmp->stack; tmps->next;
	i++, tmps = tmps->next) {}
	if (i >= 10) {
		free(new->cmd);
		free(new->arg);
		free(new);
	}
	else {
		new->time = get_time_stack(new->cmd);
		tmps->next = new;
	}
}

void stack_push(server_t *srv, int fd, char *str)
{
	sstack_t *new = malloc(sizeof(sstack_t));
	player_t *tmp;
	int i;

	stack_split(str, new, ' ');
	new->next = NULL;
	new->time = 0;
	for (i = 0; i < srv->nb_team; i++)
		tmp = get_stack_push(srv, tmp, fd, &i);
	if (tmp == NULL)
		return;
	if (tmp->stack == NULL) {
		new->time = get_time_stack(new->cmd);
		tmp->stack = new;
	}
	else
		stack_push_bis(tmp, new);
}
