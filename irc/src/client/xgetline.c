/*
** EPITECH PROJECT, 2018
** getline
** File description:
** getline
*/

#include "client.h"

int check_n(char *buff)
{
	int i = 0;

	while (buff[i]) {
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *del_carriage(char *str)
{
	int i = strlen(str);

	if (i >= 2) {
		if (str[i - 1] == '\n' && str[i - 2] == '\r')
			str[i - 2] = 0;
		else if (str[i - 1] == '\n')
			str[i - 1] = 0;
	}
	return (str);
}

char *xstrcat(char *buff, char *temp, int i)
{
	i++;
	buff = realloc(buff, sizeof(char) * ((i + 1) * 1025));
	if (buff == NULL)
		return (NULL);
	buff = strcat(buff, temp);
	if (buff == NULL)
		return (NULL);
	return (buff);
}

char *xgetline(int fd_client)
{
	char *buff = malloc(sizeof(char));
	char *temp = malloc(sizeof(char) * 1025);
	int len;
	int i = 0;

	if (buff == NULL || temp == NULL)
		return (NULL);
	buff[0] = 0;
	while (1) {
		memset(temp, 0, 1025);
		len = read(fd_client, temp, 1024);
		if (len < 0)
			return (NULL);
		buff = xstrcat(buff, temp, i);
		if (buff == NULL)
			return (NULL);
		if (len == 0 || check_n(buff) == 1)
			break;
	}
	return (del_carriage(buff));
}
