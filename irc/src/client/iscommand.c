/*
** EPITECH PROJECT, 2018
** iscommand
** File description:
** iscommand
*/

int is_command(char *line)
{
	if (line[0] == '/')
		return (1);
	return (0);
}
