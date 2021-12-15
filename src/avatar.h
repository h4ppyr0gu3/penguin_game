#ifndef AVATAR_H
#define AVATAR_H

/**
* runs a loob to ask player for an avatar and set it in the game state 
*
* @param game_params game state to be set by a function 
*/

#include "game_params.h"

void choose_avatar(GameParams *game_params); // updates player array in game params struct

#endif
