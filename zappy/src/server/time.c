/*
** EPITECH PROJECT, 2018
** time.c
** File description:
** HA my time.c
*/

#include "server.h"

int check_time(long long current, int need, int f)
{
	float tmp = (float)(current_timestamp() - current) / 1000.0f;

	if (tmp < (float)need / (float)f)
		return (0);
	return (1);
}

long long current_timestamp(void)
{
	struct timeval te;
	long long milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}
