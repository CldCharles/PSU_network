/*
** EPITECH PROJECT, 2018
** quit
** File description:
** qui
*/

#include "server.h"

void fct_quit(serv_t *serv, char *arg, usr_t *user)
{
	int y = 0;

	serv = serv;
	arg = arg;
	close(user->client_fd);
	while (serv->clients[y] != user->client_fd)
		y++;
	serv->clients[y] = 0;
	user->client_fd = 0;
}
