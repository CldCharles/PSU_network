/*
** EPITECH PROJECT, 2018
** client.c
** File description:
** client.c
*/

#include "../../include/client.h"

char **split_to_tab(char **cmd, char *str, char c)
{
	int i = 0;
	int u = 0;
	int v = 0;

	while (str[i] != '\0' && str[i] != c)
		i++;
	u = strlen(str);
	cmd[0] = malloc(sizeof(char) * (i + 1));
	cmd[1] = malloc(sizeof(char) * u);
	while (v != i) {
		cmd[0][v] = *str;
		v++;
		str++;
	}
	cmd[0][v] = '\0';
	str++;
	cmd[1] = str;
	if (*str == '\n' || *str == '\r' || *str == '\0')
		cmd[1][0] = '\0';
	return (cmd);
}

int manage_cmd(client_t *client)
{
	char *cmd;
	char **param_full;
	char *param;

	cmd = xgetline(0);
	param_full = malloc(sizeof(char *) * 2);
	param_full = split_to_tab(param_full, cmd, ' ');
	param = strdup(param_full[1]);
	if (strcasecmp(param_full[0], "/server") == 0) {
		fct_server(param, client);
		return (0);
	}
	else if (param_full[1])
		dprintf(client->fd_client
			, "%s:%s", param_full[0], param_full[1]);
	else
		dprintf(client->fd_client, "%s", param_full[0]);
	return (0);
}

int read_serv(client_t *client, fd_set *readfd)
{
	char *serv_info;

	(void)readfd;
	printf("lol\n");
	serv_info = xgetline(client->fd_client);
	printf("loll\n");
	printf("->%s\n", serv_info);
	return (0);
}

int main(void)
{
	fd_set readfd;
	int fdmax;
	client_t client;

	client.fd_client = 0;
	client.co_status = 0;
	while (1) {
		printf("->");
		fflush(NULL);
		FD_ZERO(&readfd);
		FD_SET(0, &readfd);
		fdmax = client.fd_client + 1;
		select(fdmax, &readfd, NULL, NULL, NULL);
		if (FD_ISSET(0, &readfd))
			manage_cmd(&client);
		FD_SET(client.fd_client, &readfd);
		if (FD_ISSET(client.fd_client, &readfd)) {
			read_serv(&client, &readfd);
		}
	}
}
