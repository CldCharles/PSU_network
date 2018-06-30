/*
** EPITECH PROJECT, 2018
** option
** File description:
** option.c
*/

#include "server.h"

void fct_name(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL)
		serv->names = malloc(sizeof(char *));
	else
		exit(84);
	serv->names[0] = NULL;
	while ((*av)[0] != NULL && (*av)[0][0] != '-') {
		serv->names = realloc(serv->names, sizeof(char *) * (i + 2));
		serv->names[i] = (*av)[0];
		i++;
		(*av)++;
	}
	serv->names[i] = NULL;
}

void fct_nb(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->nb_client = atoi((*av)[0]);
		norm_fct_nb(serv, av, i);
		(*av)++;
	}
	else
		exit(84);
}

void fct_freq(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->f = atoi((*av)[0]);
		norm_fct_freq(serv, av, i);
		(*av)++;
	}
	else
		exit(84);
}

void fct_width(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->width = atoi((*av)[0]);
		norm_fct_width(serv, av, i);
		(*av)++;
	}
	else
		exit(84);
}

void fct_height(server_t *serv, char ***av)
{
	int i = 0;

	if ((*av)[0] != NULL) {
		serv->height = atoi((*av)[0]);
		norm_fct_height(serv, av, i);
		(*av)++;
	}
	else
		exit(84);
}
