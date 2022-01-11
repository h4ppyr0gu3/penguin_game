#include "game_params.h"

#ifndef AUTOMATED_H
#define AUTOMATED_H

int read_to_board(GameParams* game_params);
void place_penguin(GameParams* game_params);
void write_to_file(GameParams* game_params);

#endif