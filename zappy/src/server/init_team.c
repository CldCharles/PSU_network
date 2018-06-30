/*
** EPITECH PROJECT, 2018
** init_team.c
** File description:
** HA my init_team.c
*/

#include "server.h"

void init_team(server_t *srv)
{
	int i;
	int u;
	team_t *team;

	for (i = 0; srv->names[i]; i++) {}
	team = malloc(sizeof(team_t) * (i + 1));
	for (u = 0; u < i; u++) {
		team[u].name = srv->names[u];
		team[u].fork = 0;
		team[u].player_inteam = 0;
		team[u].player = NULL;
		team[u].egg = NULL;
	}
	team[u].name = "root";
	team[u].fork = 0;
	team[u].player_inteam = 0;
	team[u].player = NULL;
	team[u].egg = NULL;
	srv->nb_team = i;
	srv->team = team;
}
