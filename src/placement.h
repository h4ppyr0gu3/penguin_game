#include "game_params.h"
#include "read_params.h"
#ifndef PLACEMENT_H
#define PLACEMENT_H

void placement(GameParams *game_params);
int validate_read_params(ReadParams *read_params);
int validate_x(GameParams *game_params, ReadParams *read_params);
int validate_y(GameParams *game_params, ReadParams *read_params);
int validate_placement(GameParams *game_params, ReadParams *read_params);

#endif