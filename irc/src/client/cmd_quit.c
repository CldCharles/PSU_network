/*
** EPITECH PROJECT, 2018
** quit
** File description:
** quit
*/

#include "../../include/client.h"

void fct_quit(char *cmd, char *arg, client_t *client)
{
	free(cmd);
	free(arg);
	free(client);
	exit(0);
}
