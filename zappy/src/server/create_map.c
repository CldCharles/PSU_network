/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** HA my create_map.c
*/

#include "server.h"

int get_pos_plr(server_t *srv, int fd, int x, int y)
{
	int i = 0;

	for (i = 0; srv->map[x][y].plr[i] != -1; i++) {
		if (srv->map[x][y].plr[i] == 0) {
			srv->map[x][y].plr[i] = fd;
			return (-1);
		}
	}
	return (i);
}

void add_tiles_player(server_t *srv, int fd, int x, int y)
{
	int i;

	if (srv->map[x][y].plr == NULL) {
		srv->map[x][y].plr = malloc(sizeof(int) * 2);
		srv->map[x][y].plr[0] = fd;
		srv->map[x][y].plr[1] = -1;
	}
	else {
		i = get_pos_plr(srv, fd, x, y);
		if (i == -1)
			return;
		srv->map[x][y].plr = realloc(srv->map[x][y].plr,
					sizeof(int) * (i + 2));
		srv->map[x][y].plr[i] = fd;
		srv->map[x][y].plr[i + 1] = -1;
	}
}

void remove_tiles_player(server_t *srv, int fd, int x, int y)
{
	int i;

	if (srv->map[x][y].plr == NULL)
		return;
	for (i = 0; srv->map[x][y].plr[i] != -1; i++) {
		if (srv->map[x][y].plr[i] == fd)
			srv->map[x][y].plr[i] = 0;
	}
}

int create_map(server_t *srv)
{
	int i;

	srv->map = malloc(sizeof(tiles_t) * srv->width);
	if (srv->map == NULL)
		return (84);
	for (i = 0; i < srv->width; i++) {
		srv->map[i] = malloc(sizeof(tiles_t) * srv->height);
		if (srv->map[i] == NULL)
			return (84);
	}
	fill_map(srv);
	return (0);
}
