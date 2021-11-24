#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include "game_params.h"

void parse_command_line_arguments(int argc, char *argv[], GameParams *game_params);
void collect_remaining_arguments(GameParams *game_params);

#endif