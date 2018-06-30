/*
** EPITECH PROJECT, 2018
** broadcast.c
** File description:
** HA my broadcast.c
*/

#include "server.h"

int compute_way(int sx, int sy, player_t *tar)
{
	float angle = 0;
	float orig = 0;
	int vx = sx - tar->x;
	int vy = sy - tar->y;

	angle = atan((float)vy / (float)vx) * (180.0f / PI);
	orig = atan(1.0f / 0.0f) * (180.0f / PI);
	angle = angle - orig + 180.f;
	for (vx = 0; orie[vx][0] != -1; vx++) {
		if (angle >= orie[vx][0] && angle < orie[vx][1]) {
			return ((((int)orie[vx][2] - 1 +
				(tar->axe - 1) * 2)) % 8 + 1);
		}
	}
	return (0);
}

int replace_image(server_t *srv, player_t *src, player_t *tar)
{
	int sx = src->x;
	int sy = src->y;

	if (src->x - tar->x < 0 && abs(src->x - tar->x) > srv->width / 2)
		sx = src->x + srv->width;
	if (src->x - tar->x > 0 && abs(src->x - tar->x) > srv->width / 2)
		sx = src->x - srv->width;
	if (src->y - tar->y < 0 && abs(src->y - tar->y) > srv->height / 2)
		sy = src->y + srv->height;
	if (src->y - tar->y > 0 && abs(src->y - tar->y) > srv->height / 2)
		sy = src->y - srv->height;
	return (compute_way(sx, sy, tar));
}

void get_target(server_t *srv, player_t *tmp, player_t *target, char *arg)
{
	int k = 0;

	if (tmp->fd != target->fd) {
		k = replace_image(srv, tmp, target);
		dprintf(target->fd, "message %d, %s\n", k, arg);
	}
}

void per_player(server_t *srv, player_t *tmp, char *arg)
{
	player_t *target;
	int i;

	for (i = 0; i < srv->nb_team; i++) {
		target = srv->team[i].player;
		for (; target; target = target->next) {
			get_target(srv, tmp, target, arg);
		}
	}
}

void broadcast(server_t *srv, int fd, char *arg)
{
	int i;
	player_t *tmp;

	for (i = 0; i < srv->nb_team; i++)
		tmp = get_broadcast(srv, tmp, fd, &i);
	per_player(srv, tmp, arg);
	dprintf(fd, "ok\n");
}
