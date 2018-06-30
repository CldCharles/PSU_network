/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "../include/myftp.h"

ptr_t ptr_fct[] =
{
	{"USER", &fct_user},
	{"PASS", &fct_pass},
	{"NOOP", &fct_noop},
	{"HELP", &fct_help},
	{"PWD", &fct_pwd},
	{"CWD", &fct_cwd},
	{"CDUP", &fct_cdup},
	{"QUIT", &fct_quit},
	{NULL, NULL}
};

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
		return (84);
	return (0);
}

int serv_loop(serv_t *serv, struct sockaddr_in binding, usr_t *usr)
{
	int size = sizeof(binding);
	int ret;

	while (1) {
		usr->client_fd = accept(serv->my_socket
					, (struct sockaddr *)&binding
					, (socklen_t *)&size);
		ret = norme(usr);
		if (ret == 84)
			return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
	serv_t serv;
	usr_t usr;
	struct sockaddr_in binding;

	if ((ac == 2 && strcmp(av[1], "-help")) || (ac != 3)) {
		usage();
		return (0);
	}
	usr.usr_status = 0;
	usr.log_status = 0;
	usr.path = strdup(av[2]);
	serv.port = atoi(av[1]);
	if ((manage_socket(binding, &serv) == 84)) {
		printf("socket\n");
		return (84);
	}
	if ((serv_loop(&serv, binding, &usr) == 84)) {
		printf("loop\n");
		return (84);
	}
}
