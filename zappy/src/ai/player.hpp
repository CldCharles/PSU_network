//
// EPITECH PROJECT, 2018
// player.hpp
// File description:
// HA my player.hpp
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

#include "connect.hpp"

class Player
{	
private:
	bool dead;
	int x;
	int y;
	std::vector<int> inv;
	std::vector<std::string> sinv;
	int lvl;
	int state;

public:
	Player();
	~Player();
	void set_map_size(int x, int y);
	void run_loop(Connect connect);
	void inventory(Connect *connect);
	std::vector<map> look(Connect *connect);
	void search_food(Connect *connect);
	void find_ress(Connect *connect, std::string ress);
	void go_to_lvl_two(Connect *connect);
	void go_to_lvl_three(Connect *connect);	
	void go_to_lvl_sup(Connect *connect);
	
};

#endif
