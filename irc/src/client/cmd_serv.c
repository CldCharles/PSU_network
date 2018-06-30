/*
** EPITECH PROJECT, 2018
** cmd_serv.c
** File description:
** cmd_serv.c
*/

#include "../../include/client.h"

int create_socket(int port, char *addr, client_t *client)
{
	struct sockaddr_in bind;
	int check_co;
	int sckt;

	sckt = socket(AF_INET, SOCK_STREAM, 0);
	if (sckt < 0)
		return (84);
	bind.sin_family = AF_INET;
	bind.sin_addr.s_addr = inet_addr(addr);
	bind.sin_port = htons(port);
	check_co = connect(sckt, (struct sockaddr *)&bind, sizeof(bind));
	if (check_co < 0)
		return (84);
	else {
		client->co_status = 1;
		printf("%d\n", client->co_status);
	}
	return (sckt);
}

int connect_port(char *param, client_t *client)
{
	int port;
	char *addr;
	char **split;

	(void)client;
	split = malloc(sizeof(char *) * 2);
	split = split_to_tab(split, param, ':');
	addr = strdup(split[0]);
	port = atoi(split[1]);
	client->fd_client = create_socket(port, addr, client);
	if (client->fd_client == 84)
		return (84);
	return (0);
}

int connect_defport(char *param, client_t *client)
{
	int defport = 6697;

	client->fd_client = create_socket(defport, param, client);
	if (client->fd_client == 84)
		return (84);
	return (0);
}

void fct_server(char *param, client_t *client)
{
	if (strchr(param, ':') == NULL)
		connect_defport(param, client);

	else
		connect_port(param, client);
}
