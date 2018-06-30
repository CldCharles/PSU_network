/*
** EPITECH PROJECT, 2018
** select_loop_bis
** File description:
** select_loop_bis.c
*/

#include "server.h"

void accept_bis(server_t *srv)
{
	int new_socket = 0;
	struct sockaddr_in serv;
	int addrlen = sizeof(serv);

	if ((new_socket = accept(srv->master_fd, (struct sockaddr *)
				&serv, (socklen_t *)&addrlen)) >= 0) {
		accept_co(srv, new_socket, serv);
	}
}

void define_before_bis(server_t *srv, player_t *tmp)
{
	if (srv->max_fd < tmp->fd)
		srv->max_fd = tmp->fd;
}

void define_before_select(server_t *srv, fd_set *readfds, struct timeval *tv)
{
	player_t *tmp = NULL;
	int i;

	tv->tv_sec = 0;
	tv->tv_usec = 10;
	FD_ZERO(readfds);
	FD_SET(srv->master_fd, readfds);
	srv->max_fd = srv->master_fd;
	for (i = 0; i < srv->nb_team + 1; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			FD_SET(tmp->fd, readfds);
			define_before_bis(srv, tmp);
			tmp = tmp->next;
		}
	}
}
