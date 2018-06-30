//
// EPITECH PROJECT, 2018
// player.cpp
// File description:
// HA my player.cpp
//

#include "player.hpp"

void Player::go_to_lvl_sup(Connect *connect)
{
	int req[][7] = {{2, 2, 0, 1, 0, 2, 0},
			{4, 1, 1, 2, 0, 1, 0},
			{4, 1, 2, 1, 3, 0, 0},
			{6, 1, 2, 3, 0, 1, 0},
			{6, 2, 2, 2, 2, 2, 1}};
	std::vector<map> view;
	std::string rep;
	std::string bc;
	int i;
	int u;
	int ulvl = this->lvl + 1;
	int axe = 0;

	std::cout << "state=> " << this->state << std::endl;
	if (this->state == 1) { //emet
		view = this->look(connect);
		if (view.empty())
			return;
		if (get_ress("player", view, 0) == req[this->lvl - 3][0]) {
			std::cout << connect->get_cmd("broadcast stoplvl" + std::to_string(this->lvl) +"\n");
			for (i = 1; i < 7; i++) {
				for (u = 0; u < get_ress(sinv[i], view, 0); u++) {
					std::cout << connect->get_cmd("Take " + sinv[i] + "\n") << std::endl;
				}
			}

			for (i = 1; i < 7; i++) {
				for (u = 0; u < req[this->lvl - 3][i]; u++) {
					std::cout << connect->get_cmd("Set " + this->sinv[i] + "\n") << std::endl;
				}
			}	
			rep = connect->get_cmd("Incantation\n");
			std::cout << rep << std::endl;
			if (rep.find(std::to_string(ulvl)) != std::string::npos)
				this->lvl += 1;
			this->state = 0;
		}
		else
			std::cout << connect->get_cmd("broadcast lvl" + std::to_string(this->lvl) + "\n");
	}
	else if (this->state == 2) { //chase
		bc = connect->get_broadcast();
		if (bc.find("message") != std::string::npos
		    && bc.find(" lvl" + std::to_string(this->lvl)) != std::string::npos) {
			bc = bc.substr(8, bc.find(","));
			axe = atoi(bc.c_str());
			if (axe == 0)
				return;
			if (axe == 2 || axe == 3 || axe == 4) {
				std::cout << connect->get_cmd("Left\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
			else if (axe == 6 || axe == 7 || axe == 8) {
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
			else if (axe == 1)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			else {
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
		}
		else if (bc.find("message") != std::string::npos
			 && bc.find("stoplvl" + this->lvl) != std::string::npos) {
			bc = bc.substr(8, bc.find(","));
			axe = atoi(bc.c_str());
			if (axe == 0) {
				rep = connect->get_cmd("");
				std::cout << rep << std::endl;
				if (rep.find(std::to_string(ulvl)) != std::string::npos)
					this->lvl += 1;
			}
			this->state = 0;
		}
	}
	else {
		std::cout << connect->get_cmd("Inventory\n") << std::endl;
		bc = connect->get_broadcast();
		if (bc.find(" lvl" + std::to_string(this->lvl)) != std::string::npos)
			this->state = 2;
		else {
			if (this->inv[1] < req[this->lvl][1]) {
				find_ress(connect, this->sinv[1]);
				return;
			}
			if (this->inv[2] < req[this->lvl][2]) {
				find_ress(connect, this->sinv[2]);
				return;
			}
			if (this->inv[3] < req[this->lvl][3]) {
				find_ress(connect, this->sinv[3]);
				return;
			}
			if (this->inv[4] < req[this->lvl][4]) {
				find_ress(connect, this->sinv[4]);
				return;
			}
			if (this->inv[5] < req[this->lvl][5]) {
				find_ress(connect, this->sinv[5]);
				return;
			}
			if (this->inv[5] < req[this->lvl][5]) {
				find_ress(connect, this->sinv[5]);
				return;
			}
		}
		if (this->state == 0 && this->inv[1] >= req[this->lvl - 3][1]
		    && this->inv[2] >= req[this->lvl - 3][2]
		    && this->inv[3] >= req[this->lvl - 3][3]
		    && this->inv[4] >= req[this->lvl - 3][4]
		    && this->inv[5] >= req[this->lvl - 3][5]
		    && this->inv[6] >= req[this->lvl - 3][6]) {
			state = 1;
		}
	}
}

void Player::go_to_lvl_three(Connect *connect)
{
	int req[] = {1, 1, 1, 0, 0, 0};
	std::vector<map> view;
	std::string rep;
	std::string bc;
	int i;
	int u;
	int axe = 0;

	std::cout << "LOL=> " << this->state << std::endl;
	if (this->state == 1) { //emet
		view = this->look(connect);
		if (view.empty())
			return;
		if (get_ress("player", view, 0) == 2) {
			std::cout << connect->get_cmd("broadcast stoplvl2\n");
			for (i = 1; i < 7; i++) {
				for (u = 0; u < get_ress(sinv[i], view, 0); u++) {
					std::cout << connect->get_cmd("Take " + sinv[i] + "\n") << std::endl;
				}
			}
			std::cout << connect->get_cmd("Set linemate\n") << std::endl;
			std::cout << connect->get_cmd("Set deraumere\n") << std::endl;
			std::cout << connect->get_cmd("Set sibur\n") << std::endl;
			rep = connect->get_cmd("Incantation\n");
			std::cout << rep << std::endl;
			if (rep.find("3") != std::string::npos)
				this->lvl = 3;
			this->state = 0;
		}
		else {
			std::cout << connect->get_cmd("broadcast lvl2\n");
		}
			
	}
	else if (this->state == 2) { //chase

		bc = connect->get_broadcast();
		if (bc.find("message") != std::string::npos
		    && bc.find(" lvl2") != std::string::npos) {
			bc = bc.substr(8, bc.find(","));
			axe = atoi(bc.c_str());
			if (axe == 0)
				return;
			if (axe == 2 || axe == 3 || axe == 4) {
				std::cout << connect->get_cmd("Left\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
			else if (axe == 6 || axe == 7 || axe == 8) {
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
			else if (axe == 1)
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			else {
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Right\n") << std::endl;
				std::cout << connect->get_cmd("Forward\n") << std::endl;
			}
		}
		else if (bc.find("message") != std::string::npos
			 && bc.find("stoplvl2") != std::string::npos) {
			bc = bc.substr(8, bc.find(","));
			axe = atoi(bc.c_str());
			if (axe == 0) {
				rep = connect->get_cmd("");
				std::cout << rep << std::endl;
				if (rep.find("3") != std::string::npos)
					this->lvl = 3;
			}
			this->state = 0;
		}
	}
	else {
		std::cout << connect->get_cmd("Inventory\n") << std::endl;
		bc = connect->get_broadcast();
		if (bc.find(" lvl2") != std::string::npos)
			this->state = 2;
		else {
			if (this->inv[1] < 1) {
				find_ress(connect, this->sinv[1]);
				return;
			}
			if (this->inv[2] < 1) {
				find_ress(connect, this->sinv[2]);
				return;
			}
			if (this->inv[3] < 1) {
				find_ress(connect, this->sinv[3]);
				return;
			}
		}
		if (this->state == 0 && this->inv[1] >= 1 && this->inv[2] >= 1 && this->inv[3] >= 1) {
			state = 1;
		}
	}
}
