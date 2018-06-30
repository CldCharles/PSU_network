//
// EPITECH PROJECT, 2018
// misc.cpp
// File description:
// HA my misc.cpp
//

#include "player.hpp"

int get_ress(std::string str, std::vector<map> view, int i)
{
	if (str.compare("player") == 0)
		return (view[i].player);
	else if (str.compare("food") == 0)
		return (view[i].food);
	else if (str.compare("linemate") == 0)
		return (view[i].q1);
	else if (str.compare("deraumere") == 0)
		return (view[i].q2);
	else if (str.compare("sibur") == 0)
		return (view[i].q3);
	else if (str.compare("mendiane") == 0)
		return (view[i].q4);
	else if (str.compare("phiras") == 0)
		return (view[i].q5);
	else if (str.compare("thystame") == 0)
		return (view[i].q6);
	else
		return (0);
}

std::vector<std::string> split(std::string str, std::string token)
{
	std::vector<std::string>result;
	int index;
	
	while(str.size()){
		index = str.find(token);
		if(index != std::string::npos){
			result.push_back(str.substr(0,index));
			str = str.substr(index+token.size());
			if(str.size()==0)
				result.push_back(str);
		}
		else {
			result.push_back(str);
			str = "";
		}
	}
	return result;
}

int count_key(std::string s, std::string key)
{
	int count = 0;
	size_t pos = 0;
	
	while ((pos = s.find(key, pos)) != std::string::npos) {
		
		count++;
		pos++;
	}
	return count;
}

