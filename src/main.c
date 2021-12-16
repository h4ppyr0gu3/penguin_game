#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "help.h"
#include "game_params.h"
#include "printer.h"
#include "map_gen.h"
#include "avatar.h"
#include "placement.h"
#include "movement.h"
#include "arguments.h"

void print_game_params(GameParams *game_params) {
	printf("\n%d \n%d \n%d \n%d \n%d \n%p \n%p\n", game_params->x_value, game_params->y_value, 
		game_params->penguin_count, game_params->player_count,
		game_params->difficulty, game_params->player_array,
		game_params->board);
}

int main(int argc, char *argv[]) {

	GameParams game_params;
	GameParams *params_ptr = &game_params;

	char *clear = "clear";
	system(clear);

	parse_command_line_arguments(argc, argv, params_ptr);
	collect_remaining_arguments(params_ptr);
	system(clear);

	game_params.board = malloc(game_params.x_value * sizeof(int*));
	for (int i = 0; i < game_params.x_value; ++i) {
		game_params.board[i] = malloc(game_params.y_value * sizeof(int));
	}

	game_params.player_array = (int*)malloc(game_params.player_count * sizeof(int)); 
  
	game_params.scoreboard_array = (int*)malloc(game_params.player_count * sizeof(int)); 

	choose_avatar(params_ptr); 
	system(clear);

	generate_map(params_ptr);

	placement(params_ptr); 

	for (int i = 0; i < game_params.player_count; ++i) {
		game_params.scoreboard_array[i] = game_params.penguin_count;
	}

	print_stage(params_ptr);

	movement(params_ptr);

	for (int i = 0; i < game_params.x_value; ++i) {
		free(game_params.board[i]);
	}
	free(game_params.board);
	free(game_params.player_array);
	free(game_params.scoreboard_array);

	return 1;
}