/*
** EPITECH PROJECT, 2018
** quit.c
** File description:
** quit.c
*/

#include "../include/myftp.h"

void fct_quit(int sckt_fd, char *full, usr_t *usr)
{
	(void)full;
	(void)usr;
	dprintf(sckt_fd, "221 Goodbye.\r\n");
	close(usr->client_fd);
	exit(0);
}
