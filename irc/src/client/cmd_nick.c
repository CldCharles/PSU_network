/*
** EPITECH PROJECT, 2018
** nick
** File description:
** fct_nick
*/

#include "client.h"

void fct_nick(char *cmd, char *arg, client_t *client)
{
	(void) cmd;
	if (arg == NULL)
		printf("431 :No nickname given\r\n");
	else if (client->name != NULL)
		printf("433 NICK :Nickname already in user\r\n");
	else {
		if (strlen(arg) > 9)
			printf("432 NICK :Erroneous nickname\r\n");
		else {
			dprintf(client->fd_client, "NICK %s\r\n", arg);
			client->name = strdup(arg);
		}
	}
}
