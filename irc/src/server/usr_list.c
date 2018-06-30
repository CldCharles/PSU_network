/*
** EPITECH PROJECT, 2018
** chan_lsit
** File description:
** chan_list
*/

#include "server.h"

usr_t *come_back_usr(usr_t *user)
{
	while (user->prev != NULL)
		user = user->prev;
	return (user);
}

usr_t *remove_usr(usr_t *user, char *name)
{
	user = come_back_usr(user);
	while (user->next != NULL && user->next->name != name)
		user = user->next;
	if (user->next != NULL) {
		free(user->next);
		user->next = user->next->next;
	}
	return (user);
}

usr_t *create_list_usr(char *name, int client_fd, char *realname)
{
	usr_t *user = malloc(sizeof(struct usr_s));

	user->prev = NULL;
	user->next = NULL;
	user->log_status = 0;
	user->name = name;
	user->realname = realname;
	user->client_fd = client_fd;
	user->client_chan = NULL;
	return (user);
}

usr_t *add_usr2(usr_t *user, char *name, int client_fd, char *realname)
{
	usr_t *new = malloc(sizeof(struct usr_s));

	while (user->next != NULL)
		user = user->next;
	new->prev = user;
	new->name = name;
	new->client_chan = NULL;
	new->client_fd = client_fd;
	new->realname = realname;
	new->log_status = 0;
	new->next = NULL;
	user->next = new;
	return (user);
}

usr_t *add_usr(usr_t *user, char *name, int client_fd, char *realname)
{
	if (user == NULL)
		user = create_list_usr(name, client_fd, realname);
	else
		user = add_usr2(user, name, client_fd, realname);
	user = come_back_usr(user);
	return (user);
}
