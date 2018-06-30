/*
** EPITECH PROJECT, 2018
** my_cwd.c
** File description:
** my_cwd.c
*/

#include "../include/myftp.h"

char *get_path(usr_t *usr)
{
	long size;
	char *buff;
	char *ptr;
	int len;

	size = pathconf(usr->pwd, 0);
	buff = malloc((size_t)size);
	ptr = getcwd(buff, (size_t)size);
	len = strlen(ptr);
	ptr[len++] = '/';
	ptr[len] = '\0';
	return (ptr);
}

void get_cwd(usr_t *usr, char *save)
{
	if ((chdir(usr->pwd)) == -1) {
		free(usr->pwd);
		usr->pwd = strdup(save);
		dprintf(usr->fd, "550 Failed to change directory.\r\n");
	}
	else
		dprintf(usr->fd
			, "250 Requested file action okay, completed.\r\n");
}

void ch_di(usr_t *usr, char *param, char *path, char *save)
{
	path = strcat(path, param);
	free(usr->pwd);
	usr->pwd = strdup(path);
	get_cwd(usr, save);
}

void no_arg(int fd)
{
	dprintf(fd, "550 Failed to change directory.\r\n");
}

void fct_cwd(int sckt_fd, char *full, usr_t *usr)
{
	if (usr->log_status == 1)
		fct_cwdbis(sckt_fd, full, usr);
	else
		dprintf(sckt_fd, "530 Please login with USER and PASS.\r\n");
}
