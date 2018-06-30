/*
** EPITECH PROJECT, 2018
** my_str_to_wordtab
** File description:
** my_str_to_wordtab.c
*/

#include "graphic_part.hpp"

int count_lines(char *str, char c)
{
	int nb = 1;
	int i = 0;

	while (str && str[i]) {
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

int count_word(char *str, char c)
{
	int i = 0;
	int nbr = 0;
	int tmp = 0;

	while (str && str[i]) {
		while (str[i] && str[i] != c) {
			nbr++;
			i++;
		}
		tmp = (nbr > tmp) ? nbr : tmp;
		nbr = 0;
		if (str && str[i])
			i++;
	}
	return (tmp);
}

int check_my_str_split(split_t *split, char **tab, char c, char *str)
{
	tab[split->j] = (char *)malloc(sizeof(char) * (count_word(str, c) + 1));
	if (tab[split->j] == NULL)
		return (84);
	split->k = 0;
	while (str[split->i] && str[split->i] != c) {
		tab[split->j][split->k] = str[split->i];
		split->i++;
		split->k++;
	}
	tab[split->j][split->k] = '\0';
	split->j++;
	if (str && str[split->i])
		split->i++;
	return (0);
}

char **my_str_split(char *str, char c)
{
	char **tab;
	split_t split;

	split.i = 0;
	split.j = 0;
	split.k = 0;
	tab = (char **)malloc(sizeof(char *) * (count_lines(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (str[split.i]) {
		if (check_my_str_split(&split, tab, c, str) == 84)
			return (NULL);
	}
	tab[split.j] = NULL;
	return (tab);
}
