/*
** EPITECH PROJECT, 2018
** parse_arg.c
** File description:
** parse_arg.c
*/

#include "server.h"

ptr_t ptr[] = {
	{"-p", &fct_port},
	{"-x", &fct_width},
	{"-y", &fct_height},
	{"-n", &fct_name},
	{"-c", &fct_nb},
	{"-f", &fct_freq},
	{"-q", &fct_gui},
	{NULL, NULL}
};

void fct_port(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->port = atoi((*av)[0]);
		norm_fct_port(serv, av, i);
		(*av)++;
	}
	else
		exit(84);
}

void fct_gui(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->gui = atoi((*av)[0]);
		norm_fct_port(serv, av, i);
		(*av)++;
		if (serv->gui > 10000 || serv->gui < 10) {
			serv->gui = 500;
		}
	}
	else
		exit(84);
}

int parse_arg(server_t *serv, char **av)
{
	int i = 0;

	serv = memset(serv, 0, sizeof(server_t));
	serv->gui_fd = 0;
	serv->gui = 500;
	serv->gui_tic = 0;
	while (*av != NULL) {
		i = 0;
		while (ptr[i].name != NULL && strcmp(*av, ptr[i].name) != 0)
			i++;
		if (ptr[i].name != NULL) {
			av++;
			ptr[i].fct(serv, &av);
		}
		else
			return (84);
	}
	return (0);
}
