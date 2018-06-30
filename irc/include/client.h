/*
** EPITECH PROJECT, 2018
** client
** File description:
** client_h
*/

#ifndef _CLIENT_H
#define _CLIENT_H

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

char *xgetline(int fd);
void exe_cmd(char *line);
int is_command(char *);

typedef struct client_s {
	char *name;
	int fd_client;
	bool co_status;
} client_t;

void fct_server(char *, client_t *);
void fct_nick(char *, char *, client_t *);
void fct_quit(char *, char *, client_t *);
char **my_str_to_wordtab(char *);
char **split_to_tab(char **, char *, char);

#endif
