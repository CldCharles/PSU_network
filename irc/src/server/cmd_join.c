/*
** EPITECH PROJECT, 2018
** joino
** File description:
** ggerjpgierjpgerjpger
*/

#include "server.h"

char **add_user_chan(char **user_chan, char *name)
{
	int i = 0;

	if (user_chan == NULL) {
		user_chan = malloc(sizeof(char *));
		user_chan[0] = NULL;
	}
	while (user_chan[i]) {
		i++;
	}
	user_chan = realloc(user_chan, sizeof(char *) * (i + 2));
	user_chan[i] = name;
	user_chan[i + 1] = NULL;
	return (user_chan);
}

int check_user_chan(chan_t *chan, char *name_chan, usr_t *user)
{
	chan = come_back_chan(chan);
	while (chan != NULL && strcmp(chan->name, name_chan) != 0)
		chan = chan->next;
	while (chan->usr != NULL && strcmp(chan->usr->name, user->name) != 0)
		chan->usr = chan->usr->next;
	if (chan->usr == NULL)
		return (0);
	return (1);
}

void print_all_join(serv_t *serv, char *name_chan, usr_t *user)
{
	fct_names(serv, name_chan, user);
	dprintf(user->client_fd
		, ":%s!~%s@0.0.0.0 JOIN :#%s\r\n"
		, user->name, user->realname, name_chan);
	dprintf(user->client_fd, "331 #%s :No topic is set\r\n", name_chan);
}

void fct_join(serv_t *serv, char *name_chan, usr_t *user)
{
	if (name_chan == NULL) {
		dprintf(user->client_fd, "461 JOIN :Not enough parameters\r\n");
		return;
	}
	if (name_chan[0] == '#')
		name_chan++;
	while (serv->chan != NULL && strcmp(serv->chan->name, name_chan) != 0)
		serv->chan = serv->chan->next;
	if (serv->chan == NULL)
		serv->chan = add_chan(serv->chan, name_chan, user);
	else if (check_user_chan(serv->chan, name_chan, user) == 1) {
		dprintf(user->client_fd, "Already in channel\r\n");
		return;
	}
	else
		serv->chan->usr = add_usr(serv->chan->usr
		, user->name, user->client_fd, user->realname);
	user->client_chan = add_user_chan(user->client_chan, name_chan);
}
