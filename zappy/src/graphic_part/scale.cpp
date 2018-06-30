//
// EPITECH PROJECT, 2018
// scale
// File description:
// scale.cpp
//

float scale_ground(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;
	while (result_height > size_case && result_lenght > size_case) {
		scale = scale - 0.001;
		result_height = size_length_pic * scale;
		result_lenght = size_length_pic * scale;
	}
	return (scale / 1.01);
}

float place_in_case(int square_size, int place, int pos_in_map)
{
	float pos;
	if (place == 0)
		return (pos_in_map);
	pos = square_size / 2;
	pos = pos + pos_in_map;
	pos = pos + (square_size * 0.20);
	return (pos);
}

float find_good_scale_mine(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	while (result_height > size_case && result_lenght > size_case) {
		scale = scale - 0.01;
		result_height = size_length_pic * scale;
		result_lenght = size_length_pic * scale;
	}
	return (scale / 4);
}

float find_good_scale_food(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	if (result_height < size_case && result_lenght < size_case) {
		while (result_height < size_case && result_lenght < size_case) {
			scale = scale + 0.01;
			result_height = size_length_pic * scale;    
			result_lenght = size_length_pic * scale;
		}
	}
	else {
		while (result_height > size_case && result_lenght > size_case) {
			scale = scale - 0.01;
			result_height = size_length_pic * scale;
			result_lenght = size_length_pic * scale;
		}
	}
	return (scale / 4);
}


float find_good_scale_character(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	if (result_height < size_case && result_lenght < size_case) {
		while (result_height < size_case && result_lenght < size_case) {
			scale = scale + 0.01;
			result_height = size_length_pic * scale;
			result_lenght = size_length_pic * scale;
		}
	}
	else {
		while (result_height > size_case && result_lenght > size_case) {
			scale = scale - 0.01;
			result_height = size_length_pic * scale;
			result_lenght = size_length_pic * scale;
		}
	}
	return (scale);
}

float find_good_scale_stone(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	while (result_height > size_case && result_lenght > size_case) {
		scale = scale - 0.01;
		result_height = size_length_pic * scale;
		result_lenght = size_length_pic * scale;
	}
	return (scale);
}


float find_good_scale_bush(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	while (result_height > size_case && result_lenght > size_case) {
		scale = scale - 0.01;
		result_height = size_length_pic * scale;
		result_lenght = size_length_pic * scale;
	}
	return (scale / 3);
}

float find_good_scale_souche(float size_case, float size_height_pic, float size_length_pic)
{
	float scale = 1;
	float result_height = size_height_pic;
	float result_lenght = size_length_pic;

	while (result_height > size_case && result_lenght > size_case) {
		scale = scale - 0.01;
		result_height = size_length_pic * scale;
		result_lenght = size_length_pic * scale;
	}
	return (scale / 0.60);
}

float place(int value,float square_size)
{
	float pos;

	value--;
	pos = square_size * value;
	return (pos);
}
