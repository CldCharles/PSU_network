/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** HA my server.h
*/

#ifndef _SERVER_H_
# define _SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <math.h>
#include <signal.h>

# define PI 3.14159265
# define LIFE_UNIT 126
# define MAX_CONNECT 1000

# define RES(res, x) (res * x) + ((res * x) / 10)

typedef struct sstack_s
{
	char *cmd;
	char *arg;
	int time;
	struct sstack_s *next;
} sstack_t;

typedef struct player_s
{
	int fd;
	int x;
	int y;
	char axe;
	char inv[7];
	long long life;
	int lvl;
	sstack_t *stack;
	long long tic_start;
	long long start_incant;
	struct player_s *next;
} player_t;

typedef struct egg_s
{
	int x;
	int y;
	struct egg_s *next;
} egg_t;

typedef struct team_s
{
	char *name;
	char fork;
	egg_t *egg;
	int player_inteam;
	player_t *player;
} team_t;

typedef struct tiles_s
{
	char loot[7];
	int *plr;
} tiles_t;

typedef struct server_s {
	int runtime;
	int port;
	int width;
	int height;
	char **names;
	int nb_client;
	int nb_team;
	int f;
	int gui;
	tiles_t **map;
	team_t *team;
	int master_fd;
	int gui_fd;
	int max_fd;
	long long cpt_tic;
	long long gui_tic;
} server_t;

typedef struct ptr_s {
	char *name;
	void (*fct)(server_t *, char ***);
} ptr_t;

typedef struct ptr_ss
{
	char *name;
	void (*func)(server_t *, int, char *);
	int tic;
} fptr_t;

extern fptr_t fptr[];
extern int res_count[3][6];
extern char *res_tab[];
extern float orie[10][3];
extern int lvlup[8][7];

void print_player(server_t *);

void inventory(server_t *, int, char *);
void look(server_t *, int, char *);
void connect_nbr(server_t *, int, char *);
void forward(server_t *, int, char *);
void left(server_t *, int, char *);
void right(server_t *, int, char *);
void take(server_t *, int, char *);
void set(server_t *, int, char *);
void broadcast(server_t *, int, char *);
void incantation(server_t *, int, char *);
void ffork(server_t *, int, char *);
void eject(server_t *, int, char *);

int retrieve_lvl_bis(server_t *, int, int);
int retrieve_lvl(server_t *, int);
void set_newlvl_bis(player_t *, int);
void set_newlvl(server_t *, int);
int parse_arg(server_t *, char **);
void add_player(server_t *, int);
void remove_player(server_t *, int);
void init_team(server_t *);
int select_loop(server_t *);
int create_map(server_t *);
int create_socket(server_t *);
char **split_first(char **, char *, char);
void add_tiles_player(server_t *, int, int, int);
void remove_tiles_player(server_t *, int, int, int);
int check_move_player(server_t *, int, char **);
void fill_look(server_t *, int, int , char *);
void fill_map(server_t *);
void fill_loot(server_t *, int, int, char *);
void regen_food(server_t *);
void set_gui(server_t *);
void life_decay(server_t *);
int check_res(server_t *, int, int, int);
int check_player(server_t *, int, int, int);
player_t *get_stack_push(server_t *, player_t *, int, int *);
void stack_push(server_t *, int, char *);
void stack_pull(server_t *, int);
void purge_stack(server_t *);
int check_time(long long, int, int);
long long current_timestamp();
void remove_egg(server_t *, int);
void new_stack_head(server_t *, player_t *);
void delay_gui(server_t *);
void place_player(server_t *, player_t *, int, int);
void player_placement(server_t *, int, int);

void fct_port(server_t *, char ***);
void fct_name(server_t *, char ***);
void fct_nb(server_t *, char ***);
void fct_freq(server_t *, char ***);
void fct_width(server_t *, char ***);
void fct_height(server_t *, char ***);
void fct_gui(server_t *, char ***);

void norm_fct_height(server_t *, char ***, int);
void norm_fct_width(server_t *, char ***, int);
void norm_fct_freq(server_t *, char ***, int);
void norm_fct_nb(server_t *, char ***, int);
void norm_fct_port(server_t *, char ***, int);

void step_one(server_t *, char **);
void second_step(server_t *, char **, char *);
void third_step(server_t *, char **, char *);

void set_lvl_up(server_t *, int, int, int);
void set_lvl_stay(server_t *, int, int, int);
void despawn_res(server_t *, int, int, int);
int incantation_bis(server_t *, player_t *, int, int);
player_t *get_broadcast(server_t *, player_t *, int, int *);

int get_tic_func(server_t *, player_t *, int);
void process_tic(server_t *, player_t *);
void process_ticbis(server_t *, player_t *, int);

void accept_bis(server_t *);
void define_before_bis(server_t *, player_t *);
void define_before_select(server_t *, fd_set *, struct timeval *);
void accept_co(server_t *, int, struct sockaddr_in);
void fill_more_bis(server_t *, int, int);
void t_mort(server_t *, player_t *, int);
void life_decay_bis(server_t *, player_t *, int);
void life_decay(server_t *);

int get_time_stack(char *);
void stack_split(char *, sstack_t *, char);

#endif
