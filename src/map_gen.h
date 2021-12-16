#include "game_params.h"
#ifndef MAP_GEN_H
#define MAP_GEN_H

/**
*set the board between random values from 1 3 
* @param game_params this set board params inside of games param strucks
*/ 

void generate_map(GameParams *game_params); // takes game params and updates board array
int check_board(GameParams *game_params); // checks the array to see if there is any unassigned position 

#endif
