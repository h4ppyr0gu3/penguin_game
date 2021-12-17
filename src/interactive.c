#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include "help.h"
#include "game_params.h"
#include "printer.h"
#include "map_gen.h"
#include "avatar.h"
#include "placement.h"
#include "movement.h"
#include "arguments.h"

void interactive(GameParams* game_params) {
	char *clear = "clear";

	game_params->board = malloc(game_params->x_value * sizeof(int*));
	for (int i = 0; i < game_params->x_value; ++i) {
		game_params->board[i] = malloc(game_params->y_value * sizeof(int));
	}

	game_params->player_array = (int*)malloc(game_params->player_count * sizeof(int)); 
  
	game_params->scoreboard_array = (int*)malloc(game_params->player_count * sizeof(int)); 

	choose_avatar(game_params); 
	system(clear);

	generate_map(game_params);

	placement(game_params); 

	for (int i = 0; i < game_params->player_count; ++i) {
		game_params->scoreboard_array[i] = game_params->penguin_count;
	}

	print_stage(game_params);

	movement(game_params);

	for (int i = 0; i < game_params->x_value; ++i) {
		free(game_params->board[i]);
	}
	free(game_params->board);
	free(game_params->player_array);
	free(game_params->scoreboard_array);

}

