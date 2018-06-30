/*
** EPITECH PROJECT, 2018
** msg.c
** File description:
** msg.c
*/

#include "server.h"

void msg_fd(char *target, usr_t *tmp, char *msg, usr_t *usr)
{
	tmp = come_back_usr(tmp);
	printf("%s\n%s\n", target, msg);
	while (tmp) {
		if (target != NULL && tmp->name != NULL &&
		strcmp(tmp->name, target) == 0) {
			dprintf(tmp->client_fd,
				":%s!~%s@0.0.0.0 PRIVMSG %s :%s\r\n",
				usr->name, usr->realname,
				target, msg + 1);
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		dprintf(usr->client_fd
			, "401 %s :No such nick/channel\r\n", target);
}

void fct_msg(serv_t *serv, char *param, usr_t *usr)
{
	char **args;
	char *target;
	char *msg;
	usr_t *tmp = usr;

	serv = serv;
	args = my_str_to_wordtab(param);
	target = strdup(args[0]);
	msg = strdup(args[1]);
	if (!target)
		dprintf(usr->client_fd
			, "411 :No recipient given (PRIVMSG)\r\n");
	else if (target[0] == '#') {
		target++;
	}
	else
		msg_fd(target, tmp, msg, usr);
}
