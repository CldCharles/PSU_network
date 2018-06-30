/*
** EPITECH PROJECT, 2018
** joino
** File description:
** ggerjpgierjpgerjpger
*/

void cmd_join(char *cmd, char *arg, client_t *client)
{
	if (arg == NULL)
		printf("461 JOIN :Not enough parameters\r\n");
	else
		dprintf(client.fd_client, "JOIN %s\r\n", arg);
}
