/*
** EPITECH PROJECT, 2018
** fct_ptr.c
** File description:
** fct_ptr.c
*/


#include "../include/myftp.h"

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

void pwd_set(usr_t *usr)
{
	char *buff;

	buff = malloc(sizeof(char) * (size_t)4096);
	usr->pwd = getcwd(buff, (size_t)4096);
}

void fct_pass(int sckt_fd, char *full, usr_t *usr)
{
	(void)full;
	if (usr->log_status == 0) {
		if (usr->usr_status == 1) {
			if (strcasecmp(usr->user_name, "anonymous") == 0) {
				usr->log_status = 1;
				dprintf(sckt_fd, "230 Login success.\n");
				if (chdir(usr->path) == -1) {
					usr->path = strdup("/");
					chdir("/");
				}
				pwd_set(usr);
			}
			else
				fct_passbis(sckt_fd, usr);
		}
		else
			dprintf(sckt_fd
				, "530 Please login with USER and PASS.\r\n");
	}
}

void fct_user(int sckt_fd, char *full, usr_t *usr)
{
	char **args;

	(void)full;
	if (usr->log_status == 1)
		dprintf(sckt_fd, "530 Can't change from guest user.\r\n");
	else {
		args = malloc(sizeof(char *) * 2);
		args = split_to_tab(args, full, ' ');
		usr->user_name = strdup(args[1]);
		usr->usr_status = 1;
		dprintf(sckt_fd, "331 Please specify the password.\r\n");
	}
}
