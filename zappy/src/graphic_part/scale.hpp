//
// Created by asordel on 05/06/18.
//

#ifndef PSU_ZAPPY_2017_SCALE_HPP
#define PSU_ZAPPY_2017_SCALE_HPP

float scale_ground(float size_case, float size_height_pic, float size_length_pic);
float place_in_case(int square_size, int place, int pos_in_map);
float place(int value,float square_size);
float find_good_scale_food(float size_case, float size_height_pic, float size_length_pic);
float find_good_scale_mine(float size_case, float size_height_pic, float size_length_pic);
float find_good_scale_stone(float size_case, float size_height_pic, float size_length_pic);
float find_good_scale_bush(float size_case, float size_height_pic, float size_length_pic);
float find_good_scale_souche(float size_case, float size_height_pic, float size_length_pic);
float find_good_scale_character(float size_case, float size_height_pic, float size_length_pic);

#endif //PSU_ZAPPY_2017_SCALE_HPP
