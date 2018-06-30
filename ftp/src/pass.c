/*
** EPITECH PROJECT, 2018
** pass.c
** File description:
** pass.c
*/

#include "../include/myftp.h"

void fct_passbis(int sckt_fd, usr_t *usr)
{
	usr->log_status = 0;
	usr->usr_status = 0;
	dprintf(sckt_fd, "530 login inccorect.\r\n");
}
