/*
** EPITECH PROJECT, 2018
** int_max
** File description:
** int_max
*/

#include "server.h"

int int_max(int *tabl)
{
	int ret;
	int i = 0;

	if (tabl != NULL)
		ret = tabl[0];
	while (i < 30) {
		if (tabl[i] > ret)
			ret = tabl[i];
		i++;
	}
	return (ret);
}
