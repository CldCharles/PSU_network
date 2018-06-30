/*
** EPITECH PROJECT, 2018
** usr
** File description:
** usr
*/

#include "server.h"

usr_t *go_to_fd(usr_t *user, int fd)
{
	user = come_back_usr(user);
	while (user->next != NULL && user->client_fd != fd) {
		user = user->next;
	}
	return (user);
}

usr_t *go_to_name(usr_t *user, char *name)
{
	come_back_usr(user);
	while (user->next != NULL && strcmp(user->name, name) != 0)
		user = user->next;
	return (user);
}
