/*
** EPITECH PROJECT, 2018
** get_cmd.c
** File description:
** get_cmd.c
*/

#include "../include/myftp.h"

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

char *parse_cmd(char *buff)
{
	int i = 0;
	int j = 0;
	char *temp;

	while (buff[i] != ' ' && buff[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	while (j < i) {
		temp[j] = buff[j];
		j++;
	}
	return (temp);
}

int exec_cmd(char *full, char *cmd, int sckt_fd, usr_t *usr)
{
	int i = 0;

	while (ptr_fct[i].name) {
		if (strcasecmp(ptr_fct[i].name, cmd) == 0) {
			ptr_fct[i].ptr(sckt_fd, full, usr);
			break;
		}
		i++;
	}
	if (ptr_fct[i].name == NULL) {
		if (usr->log_status == 1)
			dprintf(sckt_fd, "500 Unknown command.\r\n");
		else
			dprintf(sckt_fd
			, "530 Please login with USER and PASS.\r\n");
	}
	return (0);
}

char *read_cmd(int fd, usr_t *usr)
{
	char *temp = malloc(sizeof(char) * 1024);
	char *cmd;

	if (temp == NULL)
		return (NULL);
	while (1) {
		memset(temp, 0, 1024);
		if (read(fd, temp, 1024) < 0)
			return (NULL);
		temp[strlen(temp) - 2] = 0;
		cmd = parse_cmd(temp);
		if (exec_cmd(temp, cmd, fd, usr) == -1)
			return (NULL);
	}
	return (temp);
}

int usr_cmd(int fd, usr_t *usr)
{
	char *buff;

	buff = read_cmd(fd, usr);
	if (buff == NULL)
		return (84);
	return (0);
}
