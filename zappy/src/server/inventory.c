/*
** EPITECH PROJECT, 2018
** inventaire.c
** File description:
** HA my inventaire.c
*/

#include "server.h"

void print_inv(player_t *tmp, char *rep, int fd)
{
	sprintf(rep + strlen(rep), "[food %d, linemate %d, ",
		tmp->inv[0], tmp->inv[1]);
	sprintf(rep + strlen(rep), "deraumere %d, sibur %d, ",
		tmp->inv[2], tmp->inv[3]);
	sprintf(rep + strlen(rep), "mendiane %d, phiras %d, ",
		tmp->inv[4], tmp->inv[5]);
	sprintf(rep + strlen(rep), "thystame %d]",
		tmp->inv[6]);
	dprintf(fd, "%s\n", rep);
}

player_t *get_inv_cmd(player_t *tmp, int fd, char *rep)
{
	if (tmp->fd == fd)
		print_inv(tmp, rep, fd);
	tmp = tmp->next;
	return (tmp);
}

void inventory(server_t *srv, int fd, __attribute__((unused)) char *arg)
{
	char *rep = calloc(sizeof(char), 1024);
	player_t *tmp;

	if (rep == NULL)
		return;
	for (int i = 0; i < srv->nb_team; i++) {
		tmp = srv->team[i].player;
		while (tmp)
			tmp = get_inv_cmd(tmp, fd, rep);
	}
	free(rep);
}
