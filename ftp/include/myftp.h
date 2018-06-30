/*
** EPITECH PROJECT, 2018
** myftp.h
** File description:
** myftp.h
*/

#ifndef _MYFTP_H
#define _MYFTP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct ret_s
{
	int ret;
	char *msg;
}ret_t;

typedef struct serv_s
{
	int port;
	int my_socket;
} serv_t;

typedef struct usr_s
{
	int usr_socket;
	int fd;
	bool usr_status;
	bool log_status;
	char *user_name;
	char *path;
	char *pwd;
	int client_fd;
} usr_t;

typedef struct ptr_s
{
	char *name;
	void (*ptr)(int, char *, usr_t *);
}ptr_t;

typedef struct help_s
{
	char *name;
	char *message;
}help_t;

extern ptr_t ptr_fct[];

int usr_cmd(int, usr_t *);
void fct_user(int, char *, usr_t *);
void fct_pass(int, char *, usr_t *);
void fct_noop(int, char *, usr_t *);
void fct_help(int, char *, usr_t *);
void fct_pwd(int, char *, usr_t *);
void fct_cwd(int, char *, usr_t *);
void fct_cdup(int, char *, usr_t *);
void fct_quit(int, char *, usr_t *);
void fct_cwdbis(int, char *, usr_t *);
void fct_passbis(int, usr_t *);
char *epure_str(char *);
int norme(usr_t *);
void usage(void);
char **split_to_tab(char **, char *, char);
char *get_path(usr_t *);
void get_cwd(usr_t *, char *);
void ch_di(usr_t *, char *, char *, char *);
void no_arg(int);

#endif
