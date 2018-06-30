/*
** EPITECH PROJECT, 2018
** bis.c
** File description:
** bis.c
*/

#include "../include/myftp.h"

void fct_cwdbis(int sckt_fd, char *full, usr_t *usr)
{
	char *save;
	char *path;
	char **param_full;
	char *param;

	usr->fd = sckt_fd;
	save = strdup(usr->pwd);
	path = get_path(usr);
	param_full = malloc(sizeof(char *) * 2);
	param_full = split_to_tab(param_full, full, ' ');
	param = strdup(param_full[1]);
	if (param[0] == '/') {
		free(usr->pwd);
		usr->pwd = strdup(param);
		get_cwd(usr, save);
	}
	else if (param_full[1][0] == '\0')
		no_arg(sckt_fd);
	else
		ch_di(usr, param, path, save);
}
