//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// HA my main.cpp
//

#include "connect.hpp"
#include "player.hpp"

int main(int ac, char **av)
{
	Connect connect;
	Player player;

	if (connect.parse(ac, av) == -1)
		return (-1);
	if (connect.init_co() == -1)
		return (-1);
	if (connect.init_welcome() == -1)
		return (-1);
	player.set_map_size(connect.get_x(), connect.get_y());
	player.run_loop(connect);
	return (0);	
}
