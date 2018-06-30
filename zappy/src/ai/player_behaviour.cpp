//
// EPITECH PROJECT, 2018
// player_behaviour.cpp
// File description:
// HA my player_behaviour.cpp
//

#include "player.hpp"

void Player::go_to_lvl_two(Connect *connect)
{
	std::vector<map> view;
	std::string rep;
	int i;
	int u;

	view = this->look(connect);
	if (view.empty())
		return;
	if (get_ress("linemate", view, 0) != 0) {
		for (i = 1; i < 7; i++) {
			for (u = 0; u < get_ress(sinv[i], view, 0); u++) {
				std::cout << connect->get_cmd("Take " + sinv[i] + "\n") << std::endl;
			}
		}
		std::cout << connect->get_cmd("Set linemate\n") << std::endl;
		rep = connect->get_cmd("Incantation\n");
		std::cout << rep << std::endl;
	}
	else {
		std::cout << connect->get_cmd("Right\n") << std::endl;
		std::cout << connect->get_cmd("Forward\n") << std::endl;
		std::cout << connect->get_cmd("Forward\n") << std::endl;
	}
	if (rep.find("2") != std::string::npos)
		this->lvl = 2;
}

void Player::find_ress(Connect *connect, std::string ress)
{
	bool found = false;
	std::vector<map> view;
	std::string cmd = "Take " + ress + "\n";
	int i;
	int u;
	int cpt;

	view = this->look(connect);
	if (view.empty())
		return;

	if (get_ress(ress, view, 0) != 0) {
		std::cout << connect->get_cmd(cmd) << std::endl;
	}
	else {
		cpt = 0;
		for (i = 0; found == false && i < this->lvl; i++) {
			for (u = 0; found == false && u < ((i + 1) * 2) + 1; u++) {
				cpt++;
				std::cout << cpt << "  " << view[cpt].food << std::endl;
				if (get_ress(ress, view, cpt) != 0)
					found = true;
			}
		}
		i--;
		if (found && u == (((i + 1) * 2) + 1) / 2 + 1) {
			for (cpt = 0; cpt < i + 1; cpt++)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			std::cout << connect->get_cmd(cmd) << std::endl;
		}
		else if (found && u < (((i + 1) * 2) + 1) / 2 + 1) {
			for (cpt = 0; cpt < i + 1; cpt++)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			std::cout << connect->get_cmd("Left\n") << std::endl;
			for (cpt = 0; cpt < ((((i + 1) * 2) + 1) / 2 + 1) - u; cpt++)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			std::cout << connect->get_cmd(cmd) << std::endl;
		}
		else if (found && u > (((i + 1) * 2) + 1) / 2 + 1) {
			for (cpt = 0; cpt < i + 1; cpt++)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			std::cout << connect->get_cmd("Right\n") << std::endl;
			for (cpt = 0; cpt < u - ((((i + 1) * 2) + 1) / 2 + 1); cpt++)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			std::cout << connect->get_cmd(cmd) << std::endl;
		}
		else
			std::cout << connect->get_cmd("Forward\n") << std::endl;

	}	
}

void Player::search_food(Connect *connect)
{
	std::vector<map> view;
	bool found = false;
	int axe = 0;
	int i;
	int u;
	int cpt = 0;
	
	while (this->inv[0] < 13){
		found = false;
		this->inventory(connect);
		view = this->look(connect);
		if (view.empty())
			return;
		if (view[0].food != 0) {
			std::cout << connect->get_cmd("Take food\n") << std::endl;
		}
		else {
			if (view.size() < 2)
				return;
			cpt = 0;
		
			for (i = 0; found == false && i < this->lvl; i++) {
				for (u = 0; found == false && u < ((i + 1) * 2) + 1; u++) {
					cpt++;
					std::cout << cpt << "  " << view[cpt].food << std::endl;
					if (view[cpt].food != 0)
						found = true;
				}
			}
			i--;
			if (found && u == (((i + 1) * 2) + 1) / 2 + 1) {
				for (cpt = 0; cpt < i + 1; cpt++)
					std::cout << connect->get_cmd("Forward\n") << std::endl;
				std::cout << connect->get_cmd("Take food\n") << std::endl;
			}
			else if (found && u < (((i + 1) * 2) + 1) / 2 + 1) {
				for (cpt = 0; cpt < i + 1; cpt++)
					std::cout << connect->get_cmd("Forward\n") << std::endl;
				std::cout << connect->get_cmd("Left\n") << std::endl;
				for (cpt = 0; cpt < ((((i + 1) * 2) + 1) / 2 + 1) - u; cpt++)
					std::cout << connect->get_cmd("Forward\n") << std::endl;
				std::cout << connect->get_cmd("Take food\n") << std::endl;
			}
			else if (found && u > (((i + 1) * 2) + 1) / 2 + 1) {
				for (cpt = 0; cpt < i + 1; cpt++)
					std::cout << connect->get_cmd("Forward\n") << std::endl;
				std::cout << connect->get_cmd("Right\n") << std::endl;
				for (cpt = 0; cpt < u - ((((i + 1) * 2) + 1) / 2 + 1); cpt++)
					std::cout << connect->get_cmd("Forward\n") << std::endl;
				std::cout << connect->get_cmd("Take food\n") << std::endl;
			}
			else {
				if (axe < 3) {
					std::cout << connect->get_cmd("Right\n") << std::endl;
					axe++;
				}
				else {
					axe = 0;
					std::cout << connect->get_cmd("Right\n") << std::endl;
					for (cpt = 0; cpt < this->lvl; cpt++)
						std::cout << connect->get_cmd("Forward\n") << std::endl;
				}
			}
		}
	}
}
