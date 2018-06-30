/*
** EPITECH PROJECT, 2018
** b
** File description:
** f
*/

#include "client.h"

void fct_user(char *cmd, char *arg, client_t *client)
{
	dprintf(client->fd_client, "NAMES %s\n", arg);
}
