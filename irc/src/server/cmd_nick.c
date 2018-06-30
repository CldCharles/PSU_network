/*
** EPITECH PROJECT, 2018
** nick
** File description:
** fct_nick
*/

#include "server.h"

int check_used(usr_t *usr, char *nick)
{
	usr = come_back_usr(usr);
	while (usr != NULL) {
		if (nick != NULL && usr->name != NULL &&
		strcmp(usr->name, nick) == 0)
			return (0);
		usr = usr->next;
	}
	return (1);
}

void fct_nick(serv_t *serv, char *nick, usr_t *usr)
{
	usr_t *tmp;
	char *ancient = usr->name;

	serv = serv;
	if (nick == NULL) {
		dprintf(usr->client_fd, "431 NICK :Nickname not given\n");
		return ;
	}
	tmp = usr;
	if (strlen(nick) > MAX_LONG_NAME)
		dprintf(usr->client_fd, "431 NICK :Nickname not given\n");
	else if (check_used(tmp, nick) == 0)
		dprintf(usr->client_fd
			, "433 NICK :Nickname is already  in user\n");
	else
		usr->name = nick;
	dprintf(usr->client_fd , ":%s!%s@0.0.0.0 NICK :%s\n"
		, ancient, usr->realname, nick);
}
