//
// EPITECH PROJECT, 2018
// client
// File description:
// client.cpp
//

#include "graphic_part.hpp"

struct protoent *get_proto(void)
{
	struct protoent *proto;

	proto = getprotobyname("TCP");
	if (proto == NULL)
		return NULL;
	return proto;
}

int create_socket(client_t *client, char **av)
{
	int my_socket;
	struct sockaddr_in server_addr;
	struct protoent *proto;

	proto = get_proto();
	if (proto == NULL)
		return 84;
	my_socket = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (my_socket < 0)
		return 84;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(av[1]);
	server_addr.sin_port = htons(atoi(av[2]));
	if (connect(my_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		std::cout << "Connection failed" << std::endl;
		return 84;
	}
	return my_socket;
}

int init_client(client_t *client)
{
	client->socket = 0;
}

int init_graphic_client(client_t *client, int ac, char **av)
{
	if (init_client(client) == 84)
		return 84;
	client->socket = create_socket(client, av);
	if (client->socket == 84)
		return 84;
	return 0;
}
