//
// EPITECH PROJECT, 2018
// player.cpp
// File description:
// HA my player.cpp
//

#include "player.hpp"

Player::Player()
{
	this->dead = false;
	this->x = 0;
	this->y = 0;
	this->lvl = 1;
	this->state = 0;
	this->inv = std::vector<int>({0, 0, 0, 0, 0, 0, 0});
	this->sinv = std::vector<std::string>({"food",
				"linemate",
				"deraumere",
				"sibur",
				"mendiane",
				"phiras",
				"thystame"});
}

Player::~Player()
{

}

void Player::set_map_size(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Player::inventory(Connect *connect)
{
	std::string rep;
	std::string inv[14];
	int i = 0;

	rep = connect->get_cmd("Inventory\n");
	std::stringstream ssin(rep);
	while (ssin.good() && i < 14) {
		ssin >> inv[i];
		i++;
	}
	this->inv[0] = atoi(inv[1].substr(0, inv[1].find(",")).c_str());
	this->inv[1] = atoi(inv[3].substr(0, inv[3].find(",")).c_str());
	this->inv[2] = atoi(inv[5].substr(0, inv[5].find(",")).c_str());
	this->inv[3] = atoi(inv[7].substr(0, inv[7].find(",")).c_str());
	this->inv[4] = atoi(inv[9].substr(0, inv[9].find(",")).c_str());
	this->inv[5] = atoi(inv[11].substr(0, inv[11].find(",")).c_str());
	this->inv[6] = atoi(inv[13].substr(0, inv[13].find("]")).c_str());
	std::cout << rep << std::endl;	
}

void Player::run_loop(Connect connect)
{	
	while (dead == false) {
		this->inventory(&connect);
		if (this->lvl == 1)
			go_to_lvl_two(&connect);
		if (this->lvl == 2)
			go_to_lvl_three(&connect);
		if (this->lvl > 2)
			go_to_lvl_sup(&connect);
		if (this->inv[0] < 8) {
			search_food(&connect);
		}
	}
}

std::vector<map> Player::look(Connect *connect)
{
	std::string rep;
	std::vector<std::string> tmp;
	std::vector<map> mmap;
	int i;
	int u;


	rep = connect->get_cmd("Look\n");
	std::cout << "LOOK return = " << rep << std::endl;
	if (rep.compare("ko\n") == 0)
		return (mmap);
	rep = rep.substr(1, rep.size() - 2);
	tmp = split(rep, ",");
	u = tmp.size();
	if (u < 1)
		u = 1;
	for (i = 0; i < u; i++) {
		mmap.push_back({count_key(tmp[i], "player"),
					count_key(tmp[i], "food"),
					count_key(tmp[i], "linemate"),
					count_key(tmp[i], "deraumere"),
					count_key(tmp[i], "sibur"),
					count_key(tmp[i], "mendiane"),
					count_key(tmp[i], "phiras"),
					count_key(tmp[i], "thystame")});
	}
	return mmap;
}
