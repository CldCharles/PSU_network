/*
** EPITECH PROJECT, 2018
** part
** File description:
** part
*/

void cmd_part(char *cmd, char *arg, client_t *client)
{
	if (arg == NULL)
		printf("461 PART :Not enough parameters\r\n");
	else
		dprintf(client.fd_client, "PART %s\r\n", arg);
}
