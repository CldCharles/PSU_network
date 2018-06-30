//
// EPITECH PROJECT, 2018
// connect.hpp
// File description:
// HA my connect.hpp
//

#ifndef CONNECT_HPP_
# define CONNECT_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include <sstream>

struct map
{
	int player;
	int food;
	int q1;
	int q2;
	int q3;
	int q4;
	int q5;
	int q6;
};


class Connect
{
private:
	std::string ip;
	std::string team;
	std::string last_bc;
	int port;
	int fd;
	int client_remain;
	int x;
	int y;

public:	
	Connect();
	~Connect();
	int get_x() const;
	int get_y() const;
	int parse(int ac, char **av);
	int init_co();
	int init_welcome();
	std::string get_welcome();
	std::string get_cmd(std::string cmd);
	std::string get_sec();
	std::string get_broadcast() const;
	
};

std::vector<std::string> split(std::string s1, std::string s2);
int count_key(std::string s, std::string key);
int get_ress(std::string ress, std::vector<map> view, int i);

#endif
