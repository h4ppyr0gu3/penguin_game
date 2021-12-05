#include <stdio.h>
#include <stdlib.h>
#include "game_params.h"

#ifndef VALIDATIONS_H
#define VALIDATIONS_H

int validate_x(GameParams *game_params, int* array);
int validate_y(GameParams *game_params, int* array);
int validate_placement(GameParams *game_params, int* array);
int validate_penguin(GameParams *game_params, int current_player, int* array);
int validate_movement(GameParams *game_params, int* source, int* destination, int error);
int validation_loop(int constant, int greater, int lesser, GameParams *game_params, int flag, int error);
int validate_penguin_can_move(GameParams *game_params, int current_player, int* source);
int player_can_move(int current_player, GameParams *game_params);

#endif
