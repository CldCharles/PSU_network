/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

void no_arg_list(serv_t *serv, usr_t *usr)
{
	serv->chan = come_back_chan(serv->chan);
	while (serv->chan != NULL) {
		serv->chan = serv->chan->next;
		dprintf(usr->client_fd, "%s\n", serv->chan->name);
	}
	serv->chan = come_back_chan(serv->chan);
}

void arg_list(serv_t *serv, char *arg, usr_t *usr)
{
	serv->chan = come_back_chan(serv->chan);
	while (serv->chan != NULL) {
		serv->chan = serv->chan->next;
		if (strstr(serv->chan->name, arg) != NULL)
			dprintf(usr->client_fd, "%s\n", serv->chan->name);
	}
	serv->chan = come_back_chan(serv->chan);
}

void cmd_list(serv_t *serv, char *arg, usr_t *usr)
{
	if (arg == NULL)
		no_arg_list(serv, usr);
	else {
		arg_list(serv, arg, usr);
	}
}
