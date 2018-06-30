/*
** EPITECH PROJECT, 2018
** manage_cmd.c
** File description:
** manage_cmd.c
*/

#include "../../include/server.h"

ptr_t ptr_fct[] =
{
	{"NICK", &fct_nick},
	{"USER", &fct_user},
	{"QUIT", &fct_quit},
	{"JOIN", &fct_join},
	{"PRIVMSG", &fct_msg},
	{NULL, NULL}
};

char **split_to_tab(char **cmd, char *str, char c)
{
	int i = 0;
	int u = 0;
	int v = 0;

	while (str[i] != '\0' && str[i] != c)
		i++;
	u = strlen(str);
	cmd[0] = malloc(sizeof(char) * (i + 1));
	cmd[1] = malloc(sizeof(char) * u);
	while (v != i) {
		cmd[0][v] = *str;
		v++;
		str++;
	}
	cmd[0][v] = '\0';
	str++;
	cmd[1] = str;
	if (*str == '\n' || *str == '\r' || *str == '\0')
		cmd[1][0] = '\0';
	return (cmd);
}

int manage_cmd(char *cmd, int clients, usr_t *usr, serv_t *serv)
{
	char **param_full;
	char *param;
	int i = 0;

	param_full = malloc(sizeof(char *) * 2);
	param_full = split_to_tab(param_full, cmd, ' ');
	cmd = strdup(param_full[0]);
	param = strdup(param_full[1]);
	while (ptr_fct[i].name) {
		if (strcasecmp(ptr_fct[i].name, cmd) == 0) {
			ptr_fct[i].fct(serv, param, usr);
			return (0);
		}
		i++;
	}
	if (ptr_fct[i].name == NULL)
		dprintf(clients, "421 %s :Unknown command.\r\n", cmd);
	return (1);
}
