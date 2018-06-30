/*
** EPITECH PROJECT, 2018
** my_cdup.c
** File description:
** my_cdup.c
*/

#include "../include/myftp.h"

void fct_cdup(int socket_fd, char *full, usr_t *usr)
{
	(void)full;
	(void)usr;
	if (chdir("..") == -1)
		dprintf(socket_fd, "550 Failed to change directory.\r\n");
	else
		dprintf(socket_fd, "200 Command okay.\r\n");
}
