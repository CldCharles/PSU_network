/*
** EPITECH PROJECT, 2018
** ptr_fct.c
** File description:
** HA my ptr_fct.c
*/

#include "server.h"

fptr_t fptr[] =
{
	{"inventory", &inventory, 1},
	{"look", &look, 7},
	{"connect_nbr", &connect_nbr, 0},
	{"forward", &forward, 7},
	{"left", &left, 7},
	{"right", &right, 7},
	{"take", &take, 7},
	{"set", &set, 7},
	{"broadcast", &broadcast, 7},
	{"incantation", &incantation, 300},
	{"fork", &ffork, 42},
	{"eject", &eject, 7},
	{NULL, NULL, 0}
};

int res_count[3][6] =
{
	{16, 13, 17, 6, 11, 1},
	{0, 25, 45, 72, 81, 98},
	{25, 45, 72, 81, 98, 100}
};

char *res_tab[] =
{
	"food",
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame"
};

int lvlup[8][7] =
{
	{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0},
	{2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0},
	{4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0},
	{6, 2, 2, 2, 2, 2, 1}
};

float orie[10][3] =
{
	{0.0, 18.5, 1.0},
	{18.5f, 71.5f, 8.0f},
	{71.5f, 108.5f, 7.0f},
	{108.5f, 161.5f, 6.0f},
	{161.5f, 198.5f, 5.0f},
	{198.5f, 251.5f, 4.0f},
	{251.5f, 288.5f, 3.0f},
	{288.5f, 341.5f, 2.0f},
	{341.5f, 360.0f, 1.0f},
	{-1.0f, -1.0f, -1.0f}
};
