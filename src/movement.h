#include "game_params.h"
#include "placement.h"
#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
#include "read_values.h"
// #include <math.h>

/**
*it changes players and choose penguings
* @param game_params state have to be set move
*/

#ifndef MOVEMENT_H
#define MOVEMENT_H

void movement(GameParams*);
void read_source(GameParams *game_params, int* source, int current_player);
void read_destination(GameParams *game_params, int* source, int* destination);
void perform_move(int* source, int* destination, GameParams *game_params, int current_player);

#endif
