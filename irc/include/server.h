/*
** EPITECH PROJECT, 2018
** server
** File description:
** server_h
*/

#ifndef _SERVER_H
#define _SERVER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>

#define MAX_LONG_CHAN 200
#define MAX_LONG_NAME 9

typedef struct usr_s
{
	char *name;
	char *realname;
	int usr_socket;
	bool usr_status;
	bool log_status;
	int client_fd;
	char **client_chan;
	struct usr_s *next;
	struct usr_s *prev;
} usr_t;

typedef struct chan_s
{
	char *name;
	usr_t *usr;
	struct chan_s *next;
	struct chan_s *prev;
} chan_t;

typedef struct serv_s
{
	int port;
	int fd;
	char *ip;
	chan_t *chan;
	int my_socket;
	int *clients;
	FILE **client_file;
} serv_t;

typedef struct ptr_s {
	char *name;
	void (*fct)(serv_t *, char *, usr_t *);
} ptr_t;


extern ptr_t ptr_fct[];

void print_all(usr_t *);
int usage(void);
usr_t *serv_loop3(serv_t *, struct sockaddr_in, int *, usr_t *);
int int_max(int *);
void init_struct(usr_t *, serv_t *);
char **split_to_tab(char **, char *, char );
int manage_cmd(char *, int , usr_t *, serv_t *);
char *xgetline(int);
void print_all(usr_t *);
void fct_nick(serv_t *, char *, usr_t *);
void fct_quit(serv_t *, char *, usr_t *);
void fct_user(serv_t *, char *, usr_t *);
usr_t *come_back_usr(usr_t *);
usr_t *remove_usr(usr_t *, char *);
usr_t *create_list_usr(char *, int, char *);
usr_t *add_usr2(usr_t *, char *, int, char *);
usr_t *add_usr(usr_t *, char *, int, char *);
usr_t *go_to_fd(usr_t *, int);
usr_t *go_to_name(usr_t *, char *);
char **my_str_to_wordtab(char *);
char **my_str_to_wordtab_n(char *);
char *del_carriage(char *);
int check_user_chan(chan_t *, char *, usr_t *);
void fct_join(serv_t *, char *, usr_t *);
chan_t *come_back_chan(chan_t *);
chan_t *remove_chan(chan_t *, char *);
chan_t *create_list_chan(char *, usr_t *);
chan_t *add_chan2(chan_t *, char *, usr_t *);
chan_t *add_chan(chan_t *, char *, usr_t *);
void fct_msg(serv_t *, char *, usr_t *);
void fct_names(serv_t *, char *, usr_t *);
void msg_chan(serv_t *, char *, usr_t *, char *);

#endif
