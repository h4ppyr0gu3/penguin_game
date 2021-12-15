#include "game_params.h"
#ifndef MAP_GEN_H
#define MAP_GEN_H

/**
*
* @param game_params 
*/ 

void generate_map(GameParams *game_params); // takes game params and updates board array
int check_board(GameParams *game_params); // checks the array to see if there is any unassigned position 

#endif
