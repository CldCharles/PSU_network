/*
** EPITECH PROJECT, 2018
** serv2bis.c
** File description:
** serv2bis.c
*/

#include "server.h"

void print_all(usr_t *user)
{
	user = come_back_usr(user);
	while (user) {
		user = user->next;
	}
}

int usage(void)
{
	printf("USAGE: /server port\n");
	return (0);
}

usr_t *serv_loop3(serv_t *serv, struct sockaddr_in binding, int *i, usr_t *usr)
{
	int client_fd;
	int size = sizeof(binding);

	client_fd = accept(serv->my_socket
			, (struct sockaddr *)&binding
			, (socklen_t *)&size);
	serv->clients[*i] = client_fd;
	serv->client_file[*i] = fdopen(client_fd, "r");
	if (*i > 0)
		usr = add_usr(usr, "anonymous", client_fd, "anonymous");
	else
		usr = add_usr(NULL, "anonymous", client_fd, "anonymous");
	usr = come_back_usr(usr);
	(*i)++;
	return (usr);
}

void init_struct(usr_t *usr, serv_t *serv)
{
	usr->usr_status = 0;
	usr->log_status = 0;
	serv->chan = NULL;
	serv->clients = malloc(sizeof(int) * 30);
	serv->clients = memset(serv->clients, 0, sizeof(int) * 30);
	serv->client_file = malloc(sizeof(FILE *) * 30);
	serv->client_file = memset(serv->client_file, 0, sizeof(FILE *) * 30);
}
