/*
** EPITECH PROJECT, 2018
** set_lvl
** File description:
** set_lvl.c
*/

#include "server.h"

void set_lvl_up(server_t *srv, int x, int y, int lvl)
{
	int i;
	int awaken = 1;

	for (i = 0; srv->map[x][y].plr[i] != -1; i++) {
		if (retrieve_lvl(srv, srv->map[x][y].plr[i]) == lvl
		&& awaken < lvlup[lvl - 1][0]) {
			set_newlvl(srv, srv->map[x][y].plr[i]);
			awaken++;
		}
	}
}

void set_lvl_stay(server_t *srv, int x, int y, int lvl)
{
	int i;
	int awaken = 1;

	for (i = 0; srv->map[x][y].plr[i] != -1; i++) {
		if (retrieve_lvl(srv, srv->map[x][y].plr[i]) == lvl
		&& awaken < lvlup[lvl - 1][0]) {
			dprintf(srv->map[x][y].plr[i],
				"elevation underway current level: %d\n",
				lvl);
			awaken++;
		}
	}
}
