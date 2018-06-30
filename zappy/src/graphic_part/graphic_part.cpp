//
// EPITECH PROJECT, 2018
// graphic_part
// File description:
// graphic_part.cpp
//

#include <time.h>
#include <fcntl.h>
#include "graphic_part.hpp"
#include "Connection.hpp"

Graphic::Graphic()
{
}

Graphic::Graphic(int colum, int line) : checkerboard(colum * line){
	this->total = colum * line;
	this->window.create(sf::VideoMode(1600, 1000), "Zappy");
	this->square_size = 1000 / colum;
	this->colum = colum;
	this->line = line;
	Init_checkerboard();
	Init_sound();
}

Graphic::~Graphic()
{
}

void Graphic::Update_map(int pos, bool charcater, bool mine, bool food)
{
	if (charcater == false)
		checkerboard[pos].character.setTexture(this->transparent);
	else
		checkerboard[pos].character.setTexture(this->character_front);
	if (mine == false)
		checkerboard[pos].mine.setTexture(this->transparent);
	else
		checkerboard[pos].mine.setTexture(this->mine);
	if (food == false)
		checkerboard[pos].food.setTexture(this->transparent);
	else
		checkerboard[pos].food.setTexture(this->food);
}

int Graphic::Init_checkerboard(void)
{
	int y = 1;
	int x = 1;
	int cunt;
	
	srand(time(NULL));
	if (init_texture() == 84)
		return 84;
	for (cunt = 0; cunt < this->total; cunt++) {
		Specific_Init(x, y, cunt, true, true, true);
		y++;
		if (y == this->colum + 1) {
			x++;
			y = 1;
		}
	}
	return 0;
}

int Graphic::Specific_Init(int pos_x, int pos_y, int count, bool mine, bool food, bool chara)
{
	float scale;
	bool flower = true;
	
	checkerboard[count].pos_mine[0] = Random(2);
	checkerboard[count].pos_mine[1] = Random(2);
	checkerboard[count].pos_food[0] = Random(2);
	checkerboard[count].pos_food[1] = Random(2);
	while (checkerboard[count].pos_mine[0] == checkerboard[count].pos_food[0] &&
	       checkerboard[count].pos_mine[1] == checkerboard[count].pos_food[1]) {
		checkerboard[count].pos_food[0] = Random(2);
		checkerboard[count].pos_food[1] = Random(2);
	}
	checkerboard[count].ground.setTexture(this->grass);
	checkerboard[count].ground.setPosition(place(pos_x, this->square_size), place(pos_y, this->square_size));
	checkerboard[count].ground.setScale(this->scale_grass, this->scale_grass);
	if (mine == true) {
		this->scale_mine = find_good_scale_mine(this->square_size, 200, 200);
		checkerboard[count].mine.setTexture(this->mine);
		checkerboard[count].mine.setPosition(place_in_case(square_size, checkerboard[count].pos_mine[0] ,place(pos_x, square_size)),
						     place_in_case(square_size, checkerboard[count].pos_mine[1] ,place(pos_y, square_size)));
		checkerboard[count].mine.setScale(this->scale_mine, this->scale_mine);
	}
	if (food == true) {
		this->scale_food = find_good_scale_food(this->square_size, 50, 50);
		checkerboard[count].food.setTexture(this->food);
		checkerboard[count].food.setPosition(place_in_case(square_size, checkerboard[count].pos_food[0], place(pos_x, square_size)),
						     place_in_case(square_size, checkerboard[count].pos_food[1],place(pos_y, square_size)));
		checkerboard[count].food.setScale(this->scale_food, this->scale_food);
	}
	if (chara == true) {
		this->scale_character = find_good_scale_character(this->square_size, 200, 200);
		checkerboard[count].character.setTexture(this->character_front);
		checkerboard[count].character.setPosition(place(pos_x, square_size), place(pos_y, square_size));
		checkerboard[count].character.setScale(this->scale_character, this->scale_character);
	}
	if (flower == true)
		Init_flower(count, pos_x, pos_y);
	return 0;
}

int Graphic::Find_pos(int x, int y)
{
	int result;

	result = this->colum * y;
	result = result + x;
	return result;
}

void Graphic::Init_flower(int count, int pos_x, int pos_y)
{
	int random = Random(100);
	int square = this->square_size;

	if (random < 10) {
		checkerboard[count].pos_item[0] = Random(2);
		checkerboard[count].pos_item[1] = Random(2);
		this->scale_flower = find_good_scale_bush(this->square_size, 364, 308);
		checkerboard[count].item.setTexture(this->bush);
		checkerboard[count].item.setPosition(place_in_case(square_size, checkerboard[count].pos_item[0] ,place(pos_x, square_size)),
						     place_in_case(square_size, checkerboard[count].pos_item[1] ,place(pos_y, square_size)));
	}
	else if (random > 10 && random < 40) {
		this->scale_flower = find_good_scale_stone(this->square_size, 200, 200);
		random = Random(4);
		if (random == 1)
			checkerboard[count].item.setTexture(this->stone1);
		else if (random == 2)
			checkerboard[count].item.setTexture(this->stone2);
		else if (random == 13)
			checkerboard[count].item.setTexture(this->stone3);
		else
			checkerboard[count].item.setTexture(this->stone4);
		checkerboard[count].item.setPosition(place(pos_x, square_size),
						     place(pos_y, square_size));
	}
	else if (random > 40 && random < 50) {
		this->scale_flower = find_good_scale_souche(this->square_size, 200, 200);
		checkerboard[count].item.setTexture(this->souche);
		checkerboard[count].item.setPosition(place(pos_x, square_size),
						     place(pos_y, square_size));
	}
	if (random > 50 && random < 70) {
		checkerboard[count].pos_item[0] = Random(2);
		checkerboard[count].pos_item[1] = Random(2);
		this->scale_flower = find_good_scale_bush(this->square_size, 147, 157);
		checkerboard[count].item.setTexture(this->pierre);
		checkerboard[count].item.setPosition(place_in_case(square_size, checkerboard[count].pos_item[0] ,place(pos_x, square_size)),
						     place_in_case(square_size, checkerboard[count].pos_item[1] ,place(pos_y, square_size)));
	}
	checkerboard[count].item.setScale(this->scale_flower, this->scale_flower);
}

void    Graphic::Set_info_sprite()
{
	ground_info.setTexture(this->grass);
	deraumere.setTexture(this->mine1);
	linemate.setTexture(this->mine2);
	mendiane.setTexture(this->mine3);
	phiras.setTexture(this->mine4);
	sibur.setTexture(this->mine5);
	thystame.setTexture(this->mine6);
	info_character.setTexture(this->character_front);
	info_egg.setTexture(this->oeuf);
	info_food.setTexture(this->food);
}

void    Graphic::Init_info_case()
{
	ground_info.setTexture(this->grass);
	ground_info.setPosition(1100, 100);
	ground_info.setScale(0.66, 0.66);
	deraumere.setTexture(this->mine1);
	deraumere.setPosition(1100, 100);
	deraumere.setScale(0.3, 0.3);
	linemate.setTexture(this->mine2);
	linemate.setPosition(1170, 100);
	linemate.setScale(0.3, 0.3);
	mendiane.setTexture(this->mine3);
	mendiane.setPosition(1240, 100);
	mendiane.setScale(0.3, 0.3);
	phiras.setTexture(this->mine4);
	phiras.setPosition(1310, 100);
	phiras.setScale(0.3, 0.3);
	sibur.setTexture(this->mine5);
	sibur.setPosition(1380, 100);
	sibur.setScale(0.3, 0.3);
	thystame.setTexture(this->mine6);
	thystame.setPosition(1450, 100);
	thystame.setScale(0.3, 0.3);
	info_character.setTexture(this->character_front);
	info_character.setPosition(1175, 175);
	info_character.setScale(1.3, 1.3);
	info_food.setTexture(this->food);
	info_food.setPosition(1430, 430);
	info_food.setScale(1.5, 1.5);
	info_egg.setTexture(this->oeuf);
	info_egg.setPosition(1080, 410);
	info_egg.setScale(0.6, 0.6);
}

int Graphic::Gameloop(client_t *client, data_t *data)
{
	int i;
	sf::Vector2f oldPos;
	bool moving = false;
	sf::View view(window.getDefaultView());
	float zoom{ 1.1f };
	char buffer[100000];
	char **tab;
	char **map_data;
	char **player_data;
	size_t size = 0;
	sf::Event event;

	this->music.play();
	window.setFramerateLimit(60);
	view.move(-200, 0);
	window.setView(view);
	while (window.isOpen()) {
		memset(buffer, 0, 100000);
		size = read(client->socket, buffer, 100000);
		if (size <= 0)
			exit(84);
		tab = my_str_split(buffer, '\n');
		data->height = atoi(tab[0]);
		data->width = atoi(tab[1]);
		map_data = my_str_split(tab[2], '|');
		fill_data(data, map_data);
		if (tab[3][0]) {
			player_data = my_str_split(tab[3], '|');
			fill_player_data(data, player_data);		
		}
		Init_case(data);
		Init_character(data);
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: {
				window.close();
				this->music.stop();
				break;
			}
			case sf::Event::MouseButtonPressed: {
				if (event.mouseButton.button == 0)
					moving = true;
				oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				break;
			}
			case sf::Event::MouseButtonReleased: {
				if (event.mouseButton.button == 0)
					moving = false;
				break;
			}
			case sf::Event::MouseMoved: {
				if (!moving)
					break;
				const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				const sf::Vector2f deltaPos = oldPos - newPos;
				view.setCenter(view.getCenter() + deltaPos);
				window.setView(view);
				oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				break;
			}
			case  sf::Event::MouseWheelScrolled: {
				if (moving)
					break;
				if (event.mouseWheelScroll.delta <= -1)
					zoom = zoom + .08f;
				else if (event.mouseWheelScroll.delta >= 1)
					zoom = zoom - .08f;
				view.setSize(window.getDefaultView().getSize());
				view.zoom(zoom);
				window.setView(view);
				break;

			}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int pos_info;
			static bool init = true;

			if (init == true) {
				Init_info_case();
				init = false;
			}
			sf::Vector2i position = sf::Mouse::getPosition();
			pos_info = Find_square_info(position.x, position.y);
			Set_case_info(pos_info);
			std::cout << pos_info << std::endl;
		}
		window.clear();
		for (i = 0; i < this->total; i++) {
			window.draw(checkerboard[i].ground);
			window.draw(checkerboard[i].item);
			window.draw(checkerboard[i].mine);
			window.draw(checkerboard[i].food);
			window.draw(checkerboard[i].character);
		}
		window.draw(ground_info);
		window.draw(deraumere);
		window.draw(linemate);
		window.draw(mendiane);
		window.draw(phiras);
		window.draw(sibur);
		window.draw(thystame);
		window.draw(info_character);
		window.draw(info_food);
		window.draw(info_egg);
		window.display();
	}
	return (0);
}

void Graphic::Set_false()
{
	for (int i = 0; i < this->total; i++) {
		checkerboard[i].character.setTexture(this->transparent);
		checkerboard[i].number_ofCharacter = 0;
	}
}

void Graphic::Set_case_info(int pos)
{
	if (checkerboard[pos].number_ofCharacter == 0)
		info_character.setTexture(this->transparent);
	else
		info_character.setTexture(this->character_front);

	if (checkerboard[pos].b_food == true)
		info_food.setTexture(this->food);
	else
		info_food.setTexture(this->transparent);

	if (checkerboard[pos].b_mine1 == true)
		deraumere.setTexture(this->mine1);
	else
		deraumere.setTexture(this->transparent);

	if (checkerboard[pos].b_mine2 == true)
		linemate.setTexture(this->mine2);
	else
		linemate.setTexture(this->transparent);

	if (checkerboard[pos].b_mine3 == true)
		mendiane.setTexture(this->mine3);
	else
		mendiane.setTexture(this->transparent);

	if (checkerboard[pos].b_mine4 == true)
		phiras.setTexture(this->mine4);
	else
		phiras.setTexture(this->transparent);

	if (checkerboard[pos].b_mine5 == true)
		sibur.setTexture(this->mine5);
	else
		sibur.setTexture(this->transparent);

	if (checkerboard[pos].b_mine6 == true)
		thystame.setTexture(this->mine6);
	else
		thystame.setTexture(this->transparent);

	if (checkerboard[pos].b_eggs == true)
		info_egg.setTexture(this->oeuf);
	else
		info_egg.setTexture(this->transparent);
}

int Graphic::Init_character(data_t *data)
{
	player_t *tmp = data->player;

	Set_false();
	while (tmp) {
		ChooseSprite(Find_pos(tmp->y, tmp->x), tmp->axe);
		tmp = tmp->next;
	}
	for (int i = 0; i < this->total; i++)
		Check_number_character(i);
	return 0;
}

void Graphic::Check_number_character(int cunt)
{
	if (checkerboard[cunt].number_ofCharacter == 2)
		checkerboard[cunt].character.setTexture(this->character_two);
	if (checkerboard[cunt].number_ofCharacter == 3)
		checkerboard[cunt].character.setTexture(this->character_three);
	if (checkerboard[cunt].number_ofCharacter == 4)
		checkerboard[cunt].character.setTexture(this->character_four);
	if (checkerboard[cunt].number_ofCharacter == 5)
		checkerboard[cunt].character.setTexture(this->character_five);
	if (checkerboard[cunt].number_ofCharacter > 5)
		checkerboard[cunt].character.setTexture(this->character_six);
}

int Graphic::ChooseSprite(int pos_map, int orientation)
{
	if (orientation == 1)
		checkerboard[pos_map].character.setTexture(this->character_back);
	else if (orientation == 2)
		checkerboard[pos_map].character.setTexture(this->character_right);
	else if (orientation == 3)
		checkerboard[pos_map].character.setTexture(this->character_front);
	else
		checkerboard[pos_map].character.setTexture(this->character_left);
	checkerboard[pos_map].number_ofCharacter++;
	return (0);
}

int Graphic::Init_sound()
{
	if (!this->music.openFromFile("src/graphic_part/sound/main_theme.ogg"))
		return -1;

}

int Graphic::init_texture()
{
	if (!this->transparent.loadFromFile("src/graphic_part/picture/tranp.png"))
		return 84;
	if (!this->grass.loadFromFile("src/graphic_part/picture/grass.jpg"))
		return 84;
	if (!this->mine.loadFromFile("src/graphic_part/picture/stone.png"))
		return 84;
	if (!this->food.loadFromFile("src/graphic_part/picture/food.png"))
		return 84;
	if (!this->bush.loadFromFile("src/graphic_part/picture/bush1.png"))
		return 84;
	if (!this->souche.loadFromFile("src/graphic_part/picture/souche1.png"))
		return 84;
	if (!this->stone1.loadFromFile("src/graphic_part/picture/stone1.png"))
		return 84;
	if (!this->stone2.loadFromFile("src/graphic_part/picture/stone2.png"))
		return 84;
	if (!this->stone3.loadFromFile("src/graphic_part/picture/stone3.png"))
		return 84;
	if (!this->stone4.loadFromFile("src/graphic_part/picture/stone4.png"))
		return 84;
	if (!this->character_back.loadFromFile("src/graphic_part/picture/back.png"))
		return 84;
	if (!this->character_front.loadFromFile("src/graphic_part/picture/front.png"))
		return 84;
	if (!this->character_right.loadFromFile("src/graphic_part/picture/right.png"))
		return 84;
	if (!this->character_left.loadFromFile("src/graphic_part/picture/left.png"))
		return 84;
	if (!this->character_two.loadFromFile("src/graphic_part/picture/two.png"))
		return 84;
	if (!this->character_three.loadFromFile("src/graphic_part/picture/three.png"))
		return 84;
	if (!this->character_four.loadFromFile("src/graphic_part/picture/four.png"))
		return 84;
	if (!this->character_five.loadFromFile("src/graphic_part/picture/five.png"))
		return 84;
	if (!this->character_six.loadFromFile("src/graphic_part/picture/six.png"))
		return 84;
	if (!this->pierre.loadFromFile("src/graphic_part/picture/caillou1.png"))
		return 84;
	if (!this->mine1.loadFromFile("src/graphic_part/picture/deraumere.png"))
		return 84;
	if (!this->mine2.loadFromFile("src/graphic_part/picture/linemate.png"))
		return 84;
	if (!this->mine3.loadFromFile("src/graphic_part/picture/mendiane.png"))
		return 84;
	if (!this->mine4.loadFromFile("src/graphic_part/picture/phiras.png"))
		return 84;
	if (!this->mine5.loadFromFile("src/graphic_part/picture/sibur.png"))
		return 84;
	if (!this->mine6.loadFromFile("src/graphic_part/picture/thystame.png"))
		return 84;
	if (!this->oeuf.loadFromFile("src/graphic_part/picture/oeuf.png"))
		return 84;
	this->scale_grass = scale_ground(this->square_size, 623, 624);
	return 0;
}

int Graphic::Init_case(data_t *data)
{
	int i = 0;
	bool mine_ok = false;

	for (int x = 0; x < data->height; x++) {
		for (int y = 0; y < data->width; y++) {
			if (data->map[x][y].loot[0] >= 1)
				checkerboard[i].b_food = true;
			else
				checkerboard[i].b_food = false;
			if (data->map[x][y].loot[1] >= 1)
				checkerboard[i].b_mine1 = true;
			else
				checkerboard[i].b_mine1 = false;
			if (data->map[x][y].loot[2] >= 1)
				checkerboard[i].b_mine2 = true;
			else
				checkerboard[i].b_mine2 = false;
			if (data->map[x][y].loot[3] >= 1)
				checkerboard[i].b_mine3 = true;
			else
				checkerboard[i].b_mine3 = false;
			if (data->map[x][y].loot[4] >= 1)
				checkerboard[i].b_mine4 = true;
			else
				checkerboard[i].b_mine4 = false;
			if (data->map[x][y].loot[5] >= 1)
				checkerboard[i].b_mine5 = true;
			else
				checkerboard[i].b_mine5 = false;
			if (data->map[x][y].loot[6] >= 1)
				checkerboard[i].b_mine6 = true;
			else
				checkerboard[i].b_mine6 = false;
			if (data->map[x][y].loot[7] >= 1)
				checkerboard[i].b_eggs = true;
			else
				checkerboard[i].b_eggs = false;
			if (checkerboard[i].b_mine1 == true ||
			    checkerboard[i].b_mine2 == true ||
			    checkerboard[i].b_mine3 == true ||
			    checkerboard[i].b_mine4 == true ||
			    checkerboard[i].b_mine5 == true ||
			    checkerboard[i].b_mine6 == true)
				mine_ok = true;
			else
				mine_ok = false;
			Update_map(i, true, mine_ok, checkerboard[i].b_food);
			i++;
		}
	}
	return 0;
}

int Graphic::Random(int modulo)
{
	int random = rand() % modulo;
	return (random);
}

int Graphic::Find_square_info(int x, int y)
{
	int pos_tmp_x;
	int pos_tmp_y;
	pos_tmp_x = x - 270;
	pos_tmp_y = y - 58;
	std::cout << " x:" << pos_tmp_x << " y: " << pos_tmp_y << std::endl;
	pos_tmp_x = (pos_tmp_x / (int)square_size);
	pos_tmp_y = (pos_tmp_y / (int)square_size);
	std::cout << "x:" << pos_tmp_x << " y: " << pos_tmp_y << std::endl;
	return (Find_pos(pos_tmp_x, pos_tmp_y));
}
