/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** help.c
*/

#include "../include/myftp.h"

help_t help[] =
{
	{ "USER", "Specify user for authentication" },
	{ "PASS", "Specify password for authentication" },
	{ "HELP", "List available commands" },
	{ "PWD", "Print working directory" },
	{ "CWD", "Change working directory" },
	{ "CDUP", "Change working directory to parent directory" },
	{ "DELE", "Delete file on the server" },
	{ "NOOP", "Do nothing" },
	{ "QUIT", "Disconnection" },
	{ NULL, NULL }
};

void help_args(int sckt_fd, char *str)
{
	int i = 0;

	while (help[i].name && strcasecmp(help[i].name, str))
		i += 1;
	if (help[i].name)
		dprintf(sckt_fd, "214 %s\r\n" , help[i].message);
	else
		dprintf(sckt_fd, "214 Unknown command\r\n");
}

void fct_help(int sckt_fd, char *full, usr_t *usr)
{
	char **args = malloc(sizeof(char *) * 2);
	int i = 0;

	if (usr->log_status == 1) {
		(void)usr;
		args = split_to_tab(args, full, ' ');
		if (args[1][0] != '\0')
			help_args(sckt_fd, args[1]);
		else {
			dprintf(sckt_fd, "214\r\n");
			while (help[i].name) {
				dprintf(sckt_fd, "%s - %s\r\n"
					, help[i].name, help[i].message);
				i++;
			}
			dprintf(sckt_fd, "214 Help OK.\r\n");
		}
	}
	else
		dprintf(sckt_fd, "530 Please login with USER and PASS.\r\n");
}
