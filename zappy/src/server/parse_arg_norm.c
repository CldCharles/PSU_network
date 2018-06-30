/*
** EPITECH PROJECT, 2018
** parse_arg_norm
** File description:
** parse_arg_norm.c
*/

#include "server.h"

void norm_fct_height(server_t *serv, char ***av, int i)
{
	while ((*av)[0][i]) {
		if (!isdigit((*av)[0][i]) || serv->height < 8
		|| serv->height > 1000)
			exit(84);
		i++;
	}
}

void norm_fct_width(server_t *serv, char ***av, int i)
{
	while ((*av)[0][i]) {
		if (!isdigit((*av)[0][i]) || serv->width < 8
		|| serv->width > 1000)
			exit(84);
		i++;
	}
}

void norm_fct_freq(server_t *serv, char ***av, int i)
{
	while ((*av)[0][i]) {
		if (!isdigit((*av)[0][i]) || serv->f <= 0)
			exit(84);
		i++;
	}
}

void norm_fct_nb(server_t *serv, char ***av, int i)
{
	while ((*av)[0][i]) {
		if (!isdigit((*av)[0][i]) || serv->nb_client <= 0)
			exit(84);
		i++;
	}
}

void norm_fct_port(server_t *serv, char ***av, int i)
{
	while ((*av)[0][i]) {
		if (!isdigit((*av)[0][i]) || serv->port <= 0)
			exit(84);
		i++;
	}
}
