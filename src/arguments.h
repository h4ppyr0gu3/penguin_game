#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include "game_params.h"

/**
* Parses command line arguments and flags and collects all remaining if not defined by CLI
* it then sets game state values to be used throughout the game
* 
* @param argc               number of command line arguments
* @param argv               pointer to array of command line arguments
* @param game_params        Pointer to GameParams Struct 
*/

void parse_command_line_arguments(int argc, char *argv[], GameParams *game_params); // parse arguments
void collect_remaining_arguments(GameParams *game_params); //collect arguments if not defined

#endif
