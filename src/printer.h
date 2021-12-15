#include "game_params.h"
#ifndef PRINTER_H
#define PRINTER_H
 
/*
* set the board and print current numbers
* @param game_params set the board and print current scoreboard
*/

void print_stage(GameParams *game_params); // print board array to screen
void print_scoreboard(GameParams *game_params); // print scoreboard to screen

#endif
