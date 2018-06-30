/*
** EPITECH PROJECT, 2018
** noop.c
** File description:
** noop.c
*/

#include "../include/myftp.h"

void usage(void)
{
	printf("USAGE: ./server port path\n");
	printf("\tport is the port number on which the server ");
	printf("socket listens\n");
	printf("\tpath is the path to the home ");
	printf("directory for the Anonymous user\n");
}

int norme(usr_t *usr)
{
	pid_t pid;
	int check;

	if (usr->client_fd == -1)
		return (84);
	pid = fork();
	if (pid < 0)
		return (84);
	else if (pid == 0) {
		printf("Connected\n");
		dprintf(usr->client_fd
			, "220 Service ready for new user.\r\n");
		check = usr_cmd(usr->client_fd, usr);
		if (check == 84)
			return (84);
	}
	else
		close(usr->client_fd);
	return (0);
}

char *epure_str(char *str)
{
	int i = strlen(str);

	while (str[i] == ' ') {
		str[i] = 0;
		i--;
	}
	return (str);
}

void fct_noop(int sckt_fd, char *full, usr_t *usr)
{
	(void)full;
	(void)usr;
	if (usr->log_status == 0)
		dprintf(sckt_fd, "530 Please login with USER and PASS.\r\n");
	else
		dprintf(sckt_fd, "200 NOOP ok.\r\n");
}
