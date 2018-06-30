/*
** EPITECH PROJECT, 2018
** str_to_wordtab
** File description:
** str_to_wordtab
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int count_word2(char *line)
{
	int i = 0;
	int y = 0;

	while (line[i] == '\n')
		i++;
	while (line[i]) {
		if (line[i] == '\n')
			y++;
		i++;
	}
	if (line[i - 1] != '\n')
		y++;
	return (y);
}

int len_word2(char *line)
{
	int i = 0;

	while (line[i] == '\n')
		i++;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int pass_n(char *line, int i)
{
	while (line[i] == '\n')
		i++;
	return (i);
}

char **my_str_to_wordtab_n(char *line)
{
	char **new = malloc(sizeof(char *) * (count_word2(line) + 1));
	int i = 0;
	int z = 0;
	int y = 0;

	while (line[i]) {
		i = pass_n(line, i);
		new[y] = malloc(sizeof(char) * (len_word2(line + i) + 1));
		z = 0;
		while (line[i] && line [i] != '\n') {
			new[y][z] = line[i];
			z++;
			i++;
		}
		new[y][z] = 0;
		i = pass_n(line, i);
		y++;
	}
	new[y] = NULL;
	return (new);
}
