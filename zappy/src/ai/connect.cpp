//
// EPITECH PROJECT, 2018
// connect.cpp
// File description:
// HA my connect.cpp
//

#include "connect.hpp"

Connect::Connect()
{
	this->ip = "127.0.0.1";
	this->port = 4242;
}

Connect::~Connect()
{

}

int Connect::get_x() const
{
	return (this->x);
}

int Connect::get_y() const
{
	return (this->y);
}

int Connect::parse(int ac, char **av)
{
	std::string tmp;
	
	for (int i = 1; i < ac; i++) {
		tmp = av[i];

		if (!tmp.compare("-p")) {
			if (av[i + 1])
				this->port = atoi(av[i + 1]);
			else
				return (-1);
		}
		else if (!tmp.compare("-n")) {
			if (av[i + 1])
				this->team = std::string(av[i + 1]);
			else
				return (-1);
		}
		else if (!tmp.compare("-h")) {
			if (av[i + 1])
				this->ip = av[i + 1];
			else
				return (-1);
		}
	}
}

int Connect::init_co()
{
	struct protoent *pe;
	struct sockaddr_in addr;

	pe = getprotobyname("TCP");
	if (pe == NULL)
		return (-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(this->port);
	addr.sin_addr.s_addr = inet_addr(this->ip.c_str());
	this->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (this->fd == -1)
		return (-1);
	if (connect(this->fd, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
		return (-1);
	return (0);
}

int Connect::init_welcome()
{
	int len;
	std::string reps;
	std::string tmp;

	reps = this->get_welcome();
	
	if (reps.compare("WELCOME") == 0) {
		len = write(this->fd, (this->team.append("\n")).c_str(), this->team.size() + 1);
		if (len == -1)
			return (-1);
		reps = this->get_welcome();
		this->client_remain = atoi(reps.c_str());
	        reps = this->get_welcome();
		tmp = reps;
		reps = reps.substr(0, reps.find(" "));
		this->x = atoi(reps.c_str());
		len = reps.size();
		this->y = atoi(tmp.substr(len + 1, reps.size()).c_str());
	}
	else
		return (-1);
	return (0);
}

std::string Connect::get_welcome()
{
	std::string tmp;

	tmp.resize(1024);
	read(this->fd, (char *)tmp.c_str(), 1024);
	return (tmp.substr(0, tmp.find("\n")));
}

std::string Connect::get_cmd(std::string cmd)
{
	std::string rep;
	fd_set rdfds;
	int len = 0;

	FD_ZERO(&rdfds);
	FD_SET(this->fd, &rdfds);

	if (cmd.size() != 0) {
		std::cout << cmd << std::endl;
		len = write(this->fd, cmd.c_str(), cmd.size());
	}
	if (len == -1)
		std::cout << "error write " << cmd << " cmd" << std::endl;
	else {
		if (select(this->fd + 1, &rdfds, NULL, NULL, NULL) == -1)
			return (NULL);
		rep.resize(8192);
		if (FD_ISSET(this->fd, &rdfds))
			read(this->fd, (char *)rep.c_str(), 8192);
	}
	if (rep.find("dead") != std::string::npos)
		exit (0);
	if (rep.find("message") != std::string::npos) {
		this->last_bc = std::string(rep.substr(0, rep.find("\n")));
		std::cout << this->last_bc << std::endl;
		return (get_cmd(""));
	}
	return (rep.substr(0, rep.find("\n")));
}

std::string Connect::get_broadcast() const
{
	std::string tmp = this->last_bc;
	memset((void *)this->last_bc.c_str(), 0, this->last_bc.size());
	return (tmp);
}
