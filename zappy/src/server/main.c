/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** HA my main.c
*/

#include "server.h"

void help(char *bin)
{
	printf("USAGE: %s -p port -x width", bin);
	printf(" -y height -n name1 name2 ... -c clientsNb -f freq\n");
	printf("\tport\t is the port number\n");
	printf("\twidth\t is the width of the world\n");
	printf("\theight\t is the height of the world\n");
	printf("\tnameX\t is the name of the team X\n");
	printf("\tclientsNb\t is the number of authorized clients per team\n");
	printf("\tfreq\t is the reciprocal of time unit for execution ");
	printf("of actions\n");
}

int main(int ac, char **av)
{
	server_t server;

	signal(SIGPIPE, SIG_IGN);
	if (ac == 2 && !strcmp(av[1], "-help"))
		help(av[0]);
	else if (ac < 13)
		return (-1);
	if (parse_arg(&server, av + 1) == 84)
		return (-1);
	init_team(&server);
	if (create_map(&server) == 84)
		return (-1);
	if (create_socket(&server) == 84)
		return (-1);
	server.runtime = 1;
	srand(time(NULL));
	server.cpt_tic = 0;
	if (select_loop(&server) == 84)
		return (-1);
	return (0);
}
