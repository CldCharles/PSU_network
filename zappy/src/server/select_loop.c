/*
** EPITECH PROJECT, 2018
** select_loop.c
** File description:
** HA my select_loop.c
*/

#include "server.h"

void post_read(server_t *srv, char *rep, int fd)
{
	char **com = malloc(sizeof(char *) * 2);

	rep[strlen(rep) - 1] = 0;
	com = split_first(com, rep, ' ');
	if (check_move_player(srv, fd, com) == 0)
		stack_push(srv, fd, rep);
	free(com[0]);
	free(com[1]);
	free(com);
}

void get_isset(server_t *srv, player_t *tmp, fd_set *readfds)
{
	char rep[1024];

	if (FD_ISSET(tmp->fd, readfds)) {
		memset(rep, '\0', 1024);
		if (read(tmp->fd, &rep, 1024) == 0) {
			printf("client disconnect\n");
			remove_player(srv, tmp->fd);
			close(tmp->fd);
		}
		else
			post_read(srv, rep, tmp->fd);
	}
}

void io_operation(server_t *srv, fd_set *readfds)
{
	player_t *tmp;

	for (int i = 0; i < srv->nb_team + 1; i++) {
		tmp = srv->team[i].player;
		while (tmp) {
			get_isset(srv, tmp, readfds);
			tmp = tmp->next;
		}
	}
}

void accept_co(server_t *srv, int new_socket, struct sockaddr_in serv)
{
	printf("New connection from %s:%d \n", inet_ntoa(serv.sin_addr),
	ntohs(serv.sin_port));
	add_player(srv, new_socket);
}

int select_loop(server_t *srv)
{
	fd_set readfds;
	struct timeval tv;

	while (srv->runtime) {
		define_before_select(srv, &readfds, &tv);
		if (select(srv->max_fd + 1, &readfds, NULL, NULL, &tv) < 0)
			return (84);
		if (FD_ISSET(srv->master_fd, &readfds))
			accept_bis(srv);
		io_operation(srv, &readfds);
		purge_stack(srv);
		life_decay(srv);
		delay_gui(srv);
	}
	return (0);
}
