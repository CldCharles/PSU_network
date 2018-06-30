/*
** EPITECH PROJECT, 2018
** split_first.c
** File description:
** HA my split_first.c
*/

#include "server.h"

char **split_first(char **com, char *rep, char c)
{
	int i;
	int u;
	int v = strlen(rep);

	for (i = 0; rep[i] != c && rep[i] != '\0'; i++) {}
	com[0] = calloc(sizeof(char), (i + 1));
	for (u = 0; u < i; u++)
		com[0][u] = rep[u];
	com[0][u] = '\0';
	if (rep[u] == '\0')
		com[1] = calloc(sizeof(char), 1);
	else {
		com[1] = calloc(sizeof(char), v - i);
		u++;
		for (i = 0; i < v - (u - i); i++, u++)
			com[1][i] = rep[u];
	}
	return (com);
}
