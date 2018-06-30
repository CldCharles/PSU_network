/*
** EPITECH PROJECT, 2018
** cmd_names
** File description:
** cmd_names
*/

#include "server.h"

void fct_names(serv_t *serv, char *arg, usr_t *usr)
{
	serv->chan = come_back_chan(serv->chan);
	while (serv->chan && strcmp(serv->chan->name, arg) != 0)
		serv->chan = serv->chan->next;
	if (serv->chan == NULL)
		return;
	dprintf(usr->client_fd, "353 %s = #%s" , usr->name, arg);
	serv->chan->usr = come_back_usr(serv->chan->usr);
	while (serv->chan->usr && serv->chan->usr != NULL) {
		dprintf(usr->client_fd, " %s", serv->chan->usr->name);
		serv->chan->usr = serv->chan->usr->next;
	}
	dprintf(usr->client_fd, "\r\n366 %s #%s :End of /NAMES list\r\n",
		usr->name, serv->chan->name);
}
