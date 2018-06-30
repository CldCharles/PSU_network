/*
** EPITECH PROJECT, 2018
** place_player
** File description:
** place_player.c
*/

#include "server.h"

void place_player(server_t *srv, player_t *player, int fd, int i)
{
	player->next = srv->team[i].player;
	srv->team[i].player = player;
	srv->team[i].player_inteam++;
	player_placement(srv, fd, i);
}
