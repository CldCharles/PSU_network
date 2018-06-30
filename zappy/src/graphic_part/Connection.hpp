//
// Created by asordel on 18/06/18.
//

#ifndef PSU_ZAPPY_2017_CONNECTION_HPP
#define PSU_ZAPPY_2017_CONNECTION_HPP

int usage();
int init_data(data_t *data);
int fill_player_data(data_t *data, char **player_data);
int fill_data(data_t *data, char **map_data);
int get_welcome(client_t *client, data_t *data);
int check_main(int ac, char **av);

#endif //PSU_ZAPPY_2017_CONNECTION_HPP
