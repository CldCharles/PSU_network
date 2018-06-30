/*
** EPITECH PROJECT, 2018
** my_pwd
** File description:
** my_pwd.c
*/

#include "../include/myftp.h"

void fct_pwd(int socket_fd, char *full, usr_t *usr)
{
	long size;
	char *buff;
	char *ptr;

	if (usr->log_status == 0)
		dprintf(socket_fd, "530 Please login with USER and PASS.\r\n");
	else {
		(void)full;
		size = pathconf(usr->pwd, 0);
		buff = malloc((size_t)size);
		ptr = getcwd(buff, (size_t)size);
		dprintf(socket_fd, "257 \"%s\"\r\n", ptr);
	}
}
