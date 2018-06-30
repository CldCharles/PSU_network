/*
** EPITECH PROJECT, 2018
** stack.c
** File description:
** HA my stack.c
*/

#include "server.h"

void stack_split(char *rep, sstack_t *new, char c)
{
	int i = 0;
	int u = 0;
	int v = strlen(rep);

	for (i = 0; rep[i] != c && rep[i] != '\0'; i++) {}
	new->cmd = calloc(sizeof(char), (i + 1));
	for (u = 0; u < i; u++)
		new->cmd[u] = rep[u];
	new->cmd[u] = '\0';
	if (rep[u] == '\0')
		new->arg = calloc(sizeof(char), 1);
	else {
		new->arg = calloc(sizeof(char), v - i);
		u++;
		for (i = 0; i < v - (u - i); i++, u++)
			new->arg[i] = rep[u];
	}
}

int get_time_stack(char *cmd)
{
	int i = 0;

	for (i = 0; fptr[i].name; i++) {
		if (strcasecmp(cmd, fptr[i].name) == 0)
			return (fptr[i].tic);
	}
	return (-1);
}

player_t *get_stack_pull(server_t *srv, player_t *tmp, int fd, int *i)
{
	for (tmp = srv->team[*i].player; tmp; tmp = tmp->next) {
		if (tmp->fd == fd) {
			*i = srv->nb_team;
			break;
		}
	}
	return (tmp);
}

void stack_pull(server_t *srv, int fd)
{
	player_t *tmp;
	sstack_t *tmps;
	int i = 0;

	for (i = 0; i < srv->nb_team; i++)
		tmp = get_stack_pull(srv, tmp, fd, &i);
	tmps = tmp->stack;
	tmp->stack = tmp->stack->next;
	free(tmps->cmd);
	free(tmps->arg);
	free(tmps);
}
