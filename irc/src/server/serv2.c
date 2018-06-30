/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

#include "server.h"

int manage_socket(struct sockaddr_in binding, serv_t *serv)
{
	serv->my_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (serv->my_socket == -1)
		return (84);
	binding.sin_family = AF_INET;
	binding.sin_addr.s_addr = INADDR_ANY;
	binding.sin_port = htons(serv->port);
	if ((bind(serv->my_socket,
		(struct sockaddr *)&binding, sizeof(binding)) == -1))
		return (84);
	if (listen(serv->my_socket, 10) == -1)
		return (0);
	return (0);
}

int get_cmd(serv_t *serv, usr_t *usr, int clients)
{
	char *cmd = malloc(sizeof(char) * 1025);
	char **cmd2;
	int i = 0;
	size_t len = 0;

	len = read(clients, cmd, 1024);
	cmd[len] = 0;
	cmd2 = my_str_to_wordtab_n(cmd);
	while (cmd2[i]) {
		cmd2[i] = del_carriage(cmd2[i]);
		manage_cmd(cmd2[i], clients, usr, serv);
		i++;
	}
	return (0);
}

int serv_loop2(serv_t *serv, fd_set readfd, usr_t *usr)
{
	int y = 0;

	while (y != 30) {
		if (serv->clients[y] != 0) {
			if (FD_ISSET(serv->clients[y], &readfd)) {
				usr = go_to_fd(usr, serv->clients[y]);
				if (get_cmd(serv, usr
					, serv->clients[y]) == -1)
					return (84);
			}
		}
		y++;
	}
	return (0);
}

int serv_loop(serv_t *serv, struct sockaddr_in binding, usr_t *usr)
{
	fd_set readfd;
	int fdmax = serv->my_socket + 1;
	int i = 0;

	while (1) {
		FD_ZERO(&readfd);
		FD_SET(serv->my_socket, &readfd);
		for (int z = 0; z != 30; z++)
			if (serv->clients[z] != 0)
				FD_SET(serv->clients[z], &readfd);
		if (select(fdmax, &readfd, NULL, NULL, NULL) == -1)
			return (84);
		if (FD_ISSET(serv->my_socket, &readfd)) {
			usr = serv_loop3(serv, binding, &i, usr);
			fdmax = int_max(serv->clients) + 1;
		}
		if (serv_loop2(serv, readfd, usr) == 84)
			return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
	serv_t serv;
	usr_t usr;
	struct sockaddr_in binding;

	if ((ac == 2 && strcmp(av[1], "-help") == 0) || (ac != 2)) {
		usage();
		return (0);
	}
	serv.port = atoi(av[1]);
	init_struct(&usr, &serv);
	if ((manage_socket(binding, &serv) == 84))
		return (84);
	if ((serv_loop(&serv, binding, &usr) == 84))
		return (84);
}
