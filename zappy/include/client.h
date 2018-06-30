/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/select.h>

typedef struct tile_s
{
	int rss[9];
} tile_t;

typedef struct stacks_s
{
	char *cmd;
	struct stacks_s *next;
}stacks_t;

typedef struct client_s {
	int socket;
	bool run;
	bool loged;
	int port;
	char *name;
	char *machine;
	int elevation;
	tile_t *view;
	int turn;
	stacks_t *stacks;
} client_t;

typedef struct ptr_s
{
	char *name;
	void (*fct)();
} ptr_t;

typedef struct fptr_s
{
	char *name;
	void (*func)();
} fptr_t;

extern fptr_t fptr[];
extern ptr_t ptr[];
extern int need_elevation[8][7];
extern char *minerals[7];

void stack_push(client_t *, char *);

int *get_inventory(char *);
char **split_first(char **, char *, char);
void found_ptr(client_t *, char *, int);
void create_mm(client_t *, char *);
void f_linemate(client_t *, int);
void f_deraumere(client_t *, int);
void f_sibur(client_t *, int);
void f_mendiane(client_t *, int);
void f_thystame(client_t *, int);
void f_phiras(client_t *, int);
void f_sibur(client_t *, int);
void f_food(client_t *, int);
void f_egg(client_t *, int);
void f_player(client_t *, int);

int parse_arg(client_t *, int, char **);

int fct_port(client_t *, char **, int);
int fct_name(client_t *, char **, int);
int fct_machine(client_t *, char **, int);

int my_usage();

int init_zappy_client(client_t *, int, char **);
int init_client(client_t *);

void init_select(client_t *, fd_set *);
int post_select(client_t *, fd_set *);
char *post_select_loop(client_t *, fd_set *);
int running_select(client_t *, fd_set *);
char *running_select_loop(client_t *, fd_set *);

void f_forward(client_t *);
void f_broadcast(client_t *, char *);

struct protoent *get_proto(void);
int create_socket(client_t *);

int main_loop(client_t *);

void f_welcome(client_t *);
void f_dead(client_t *);

char *send_forward(client_t *, fd_set);
char *send_right(client_t *, fd_set);
char *send_left(client_t *, fd_set);
char *send_look(client_t *, fd_set);
char *send_inventory(client_t *, fd_set);
char *send_connect_nbr(client_t *, fd_set);
char *send_fork(client_t *, fd_set);
char *send_eject(client_t *, fd_set);
char *send_incantation(client_t *, fd_set);
void f_set(client_t *, char *);
void f_take(client_t *, char *);

char **split_first(char **, char *, char);

int put_elevation_minerals(client_t *, fd_set);
int empty_case(client_t *);
int do_elevation(client_t *, fd_set);
int got_broadcast();
int search_food(client_t *, fd_set);
int search_minerals(client_t *, fd_set);

int check_elevation(client_t *, int *);
int check_broadcast(char *);

int *get_move_to(client_t *, int);
int move_to(client_t *, int *, fd_set);
void move_to_item(client_t *, int *, char *, fd_set);

#endif
