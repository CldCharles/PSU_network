/*
** EPITECH PROJECT, 2018
** misc.c
** File description:
** HA my misc.c
*/

#include  "server.h"

char *pick_res(int i)
{
	switch (i)
	{
	case 0:
		return ("food");
	case 1:
		return ("linemate");
	case 2:
		return ("deraumere");
	case 3:
		return ("sibur");
	case 4:
		return ("mendiane");
	case 5:
		return ("phiras");
	case 6:
		return ("thystame");
	}
	return ("");
}

char *get_look_player(int j, int *aw, char *rep)
{
	if (j != 0 && *aw == 0) {
		sprintf(rep + strlen(rep), "%s", "player");
		(*aw)++;
	}
	else if (j != 0 && *aw != 0) {
		sprintf(rep + strlen(rep), " %s", "player");
		(*aw)++;
	}
	return (rep);
}

char *get_look_rss(int j, int *aw, char *rep, int i)
{
	if (j != 0 && *aw == 0) {
		sprintf(rep + strlen(rep), "%s", pick_res(i));
		(*aw)++;
	}
	else if (j != 0 && *aw != 0) {
		sprintf(rep + strlen(rep), " %s", pick_res(i));
		(*aw)++;
	}
	return (rep);
}

void fill_look(server_t *srv, int x, int y, char *rep)
{
	int aw = 0;

	sprintf(rep + strlen(rep), ",");
	if (srv->map[x][y].plr != NULL) {
		for (int i = 0; srv->map[x][y].plr[i] != -1; i++)
			rep = get_look_player(srv->map[x][y].plr[i], &aw, rep);
	}
	for (int i = 0; i < 7; i++) {
		for (int u = 0; u < srv->map[x][y].loot[i]; u++) {
			rep = get_look_rss(srv->map[x][y].loot[i], &aw, rep, i);
		}
	}
}
