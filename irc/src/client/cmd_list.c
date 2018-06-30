/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

void cmd_list(char *cmd, char *arg, client_t *client)
{
	if (arg != NULL)
		dprintf(client.fd_client, "LIST %s\n", arg);
	else
		dprintf(client.fd_client, "LIST\n");
}
