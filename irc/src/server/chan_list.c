
/*
** EPITECH PROJECT, 2018
** chan_lsit
** File description:
** chan_list
*/

#include "server.h"

chan_t *come_back_chan(chan_t *chan)
{
	while (chan->prev != NULL)
		chan = chan->prev;
	return (chan);
}

chan_t *remove_chan(chan_t *chan, char *name)
{
	while (chan->next != NULL && strcmp(chan->next->name, name) != 0)
		chan = chan->next;
	free(chan->next);
	if (chan->next != NULL)
		chan->next = chan->next->next;
	return (chan);
}

chan_t *create_list_chan(char *name, usr_t *usr)
{
	chan_t *chan = malloc(sizeof(struct chan_s));

	chan->prev = NULL;
	chan->next = NULL;
	chan->name = name;
	chan->usr = add_usr(NULL, usr->name, usr->client_fd, usr->realname);
	return (chan);
}

chan_t *add_chan2(chan_t *chan, char *name, usr_t *usr)
{
	chan_t *new = malloc(sizeof(struct chan_s));

	while (chan->next != NULL)
		chan = chan->next;
	chan->next = new;
	chan = chan->next;
	chan->prev = chan;
	chan->next = NULL;
	chan->name = name;
	chan->usr = add_usr(NULL, usr->name, usr->client_fd, usr->realname);
	return (chan);
}

chan_t *add_chan(chan_t *chan, char *name, usr_t *usr)
{
	if (chan == NULL)
		chan = create_list_chan(name, usr);
	else
		chan = add_chan2(chan, name, usr);
	return (chan);
}
