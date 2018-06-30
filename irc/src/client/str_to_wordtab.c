/*
** EPITECH PROJECT, 2018
** str_to_wordtab
** File description:
** str_to_wordtab
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int is_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= 'A' && c <= 'Z')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int count_word(char *line)
{
	int i = 0;
	int y = 0;

	while (line[i] == ' ')
		i++;
	while (line[i]) {
		if (line[i] == ' ')
			y++;
		i++;
	}
	if (line[i - 1] != ' ')
		y++;
	return (y);
}

int len_word(char *line)
{
	int i = 0;

	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}

char **my_str_to_wordtab(char *line)
{
	char **new = malloc(sizeof(char *) * (count_word(line) + 1));
	int i = 0;
	int z = 0;
	int y = 0;

	while (line[i]) {
		new[y] = malloc(sizeof(char) * (len_word(line + i) + 1));
		z = 0;
		for (; line[i] == ' '; i++, z++)
			new[y][z] = line[i];
		for (; line[i] && line [i] != ' '; i++, z++)
			new[y][z] = line[i];
		new[y][z] = 0;
		y++;
		if (line[i] == ' ')
			i++;
	}
	new[y] = NULL;
	return (new);
}
