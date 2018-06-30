/*
** EPITECH PROJECT, 2018
** creat_socket.c
** File description:
** HA my create_socket.c
*/

#include "server.h"

int create_socket(server_t *srv)
{
	struct protoent *proto;
	struct sockaddr_in serv;

	proto = getprotobyname("TCP");
	if (proto == NULL)
		return (84);
	srv->master_fd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (srv->master_fd == -1)
		return (84);
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(srv->port);
	if ((bind(srv->master_fd, (struct sockaddr *)&serv,
		sizeof((serv)))) < 0)
		return (84);
	if ((listen(srv->master_fd, MAX_CONNECT)) < 0)
		return (84);
	return (0);
}
