/*
** EPITECH PROJECT, 2018
** user
** File description:
** user
*/

#include "server.h"

int multi_strlen(char **param)
{
	int i = 0;
	int y = 0;

	while (param[i]) {
		y += strlen(param[i]);
		i++;
	}
	return (y);
}

char *concat_real(char **param)
{
	char *new = malloc(sizeof(char) *(multi_strlen(param) + 1));
	int i = 0;

	new[0] = 0;
	while (param[i]) {
		if (i > 0)
			new = strcat(new, " ");
		else
			param[i]++;
		new = strcat(new, param[i]);
		i++;
	}
	return (new);
}

int nb_arg(char *arg)
{
	int i = 0;
	int y = 0;

	while (arg[i]) {
		while (arg[i] && arg[i] != ' ') {
			i++;
		}
		while (arg[i] ==  ' ') {
			i++;
		}
		y += 1;
	}
	return (y);
}

void fct_user(serv_t *serv, char *arg, usr_t *user)
{
	char **param;

	serv = serv;
	if (user != NULL && user->log_status == 1)
		dprintf(user->client_fd
			, "462 :Unauthorized command (already registered\r\n");
	else if (nb_arg(arg) < 4)
		dprintf(user->client_fd, "461 USER :Not enough parameters\r\n");
	else {
		param = my_str_to_wordtab(arg);
		user->realname = concat_real(param + 3);
		dprintf(user->client_fd, "001 Welcome to %s!%s@%s network\r\n"
			, param[0], param[1], param[2]);
		user->log_status = 1;
	}
}
