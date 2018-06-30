//
// Created by asordel on 05/06/18.
//

#ifndef PSU_ZAPPY_2017_GRAPHIC_PART_HPP
#define PSU_ZAPPY_2017_GRAPHIC_PART_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <netdb.h>
#include <sstream>
#include "scale.hpp"

#define LARGUEUR 1000
#define LONGEUR 1200
#define HAUTEURMINE 166
#define LARGUEURMINE 244

typedef struct split_s
{
	int i;
	int j;
	int k;
} split_t;

typedef struct client_s
{
	int socket;
} client_t;

typedef struct player_s
{
	int x;
	int y;
	char axe; // 1 = back, 2 = right, 3 = front, 4 = left
	int inv[7];
	int lvl;
	struct player_s *next;
} player_t;

typedef struct tiles_s {
	int loot[7];
	char egg;
	int plr;
} tiles_t;

typedef struct data_s
{
	int height;
	int width;
	tiles_t **map;
	player_t *player;
} data_t;

char **my_str_split(char *, char);
struct protoent *get_proto(void);
int create_socket(client_t *, char **);
int init_client(client_t *);
int init_graphic_client(client_t *, int, char **);

class Graphic {
public:
	Graphic();
	Graphic(int, int);
	~Graphic();
	int     Gameloop(client_t *, data_t *);
	int     Init_checkerboard();
	void    Init_scale();
	int     init_texture();
	int     init_grass();
	int     Specific_Init(int, int, int, bool, bool, bool);
	int     Init_sound();
	void    Init_flower(int, int ,int);
	void    Update_map(int , bool, bool, bool);
	int     Find_pos(int, int);
	int     Random(int);
	int	    Init_case(data_t *);
    void    Set_false();
    int     Init_character(data_t *);
    int     ChooseSprite(int, int);
    void	Check_number_character(int);
    void    Init_info_case();
    void    Set_info_sprite();
    int     Find_square_info(int x, int y);
    void    Set_case_info(int pos);
private:
	struct Case {
		sf::Sprite  ground;
		sf::Sprite  food;
		sf::Sprite  mine;
		sf::Sprite  item;
		sf::Sprite 	character;
		int         number_ofCharacter;
		int         pos_mine[2];
		int         pos_food[2];
		int         pos_item[2];
		float       x_ground;
		float       y_ground;
		bool        b_food;
		bool        b_mine1;
		bool        b_mine2;
		bool        b_mine3;
		bool        b_mine4;
		bool        b_mine5;
		bool        b_mine6;
		bool        b_eggs;
	};
	sf::Music music;
	std::vector<Case>   checkerboard;
	sf::RenderWindow    window;
	sf::Texture         grass;
	sf::Texture         mine;
	sf::Texture         food;
	sf::Texture	    	character_back;
	sf::Texture			character_left;
	sf::Texture			character_right;
	sf::Texture			character_front;
	sf::Texture         souche;
	sf::Texture         stone1;
    sf::Texture         stone2;
    sf::Texture         stone3;
    sf::Texture         stone4;
	sf::Texture         bush;
    sf::Texture         mine1;
    sf::Texture         mine2;
    sf::Texture         mine3;
    sf::Texture         mine4;
    sf::Texture         mine5;
    sf::Texture         mine6;
	sf::Texture         transparent;
    sf::Texture         character_two;
    sf::Texture         character_three;
    sf::Texture         character_four;
    sf::Texture         character_five;
    sf::Texture         character_six;
    sf::Texture         pierre;
    sf::Texture         oeuf;
    sf::Sprite 	        ground_info;
    sf::Sprite          deraumere;
    sf::Sprite          linemate;
    sf::Sprite          mendiane;
    sf::Sprite          phiras;
    sf::Sprite          sibur;
    sf::Sprite          thystame;
    sf::Sprite          info_character;
    sf::Sprite          info_food;
    sf::Sprite          info_egg;
	float               scale_grass;
	float               scale_food;
	float               scale_mine;
	float               scale_flower;
	float               scale_character;
	int                 total;
	float               square_size;
	int                 line;
	int                 colum;
};

#endif //PSU_ZAPPY_2017_GRAPHIC_PART_HPP
