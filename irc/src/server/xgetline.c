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
		else if (str[i - 1] == '\n' || str[i - 1] == '\r')
			str[i - 1] = 0;
	}
	return (str);
}

char *xstrcat(char *buff, char *temp)
{
	buff = realloc(buff, sizeof(char) * (strlen(buff) + 1025));
	if (buff == NULL)
		return (NULL);
	buff = strcat(buff, temp);
	if (buff == NULL)
		return (NULL);
	return (buff);
}

char *until_n(char **buff)
{
	char *temp = malloc(sizeof(char) * (strlen(*buff) + 1));
	int i = 0;

	while ((*buff)[0] && (*buff)[0] != '\n') {
		temp[i] = *(buff)[0];
		(*buff)++;
		i++;
	}
	(*buff)++;
	temp[i] = 0;
	strcat(temp, "\n");
	return (temp);
}

char *xgetline(int fd_client)
{
	static char *buff = NULL;
	char *temp = malloc(sizeof(char) * 1025);
	int len;

	if (buff == NULL) {
		buff = malloc(sizeof(char));
		buff[0] = 0;
	}
	if (buff == NULL || temp == NULL)
		return (NULL);
	while (check_n(buff) != 1) {
		memset(temp, 0, 1025);
		len = read(fd_client, temp, 1024);
		if (len < 0)
			return (NULL);
		buff = xstrcat(buff, temp);
		if (buff == NULL)
			return (NULL);
	}
	return (del_carriage(until_n(&buff)));
}
