#include "automated.h"
#include "arguments.h"
#include "game_params.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int command_line_placement_test(int argc, char *argv[], GameParams *game_params) {
	argc = 5;
	argv[0] = "./penguins";
	argv[1] = "phase=placement";
	argv[2] = "penguins=3";
	argv[3] = "input.txt";
	argv[4] = "out.txt";

	parse_command_line_arguments(argc, argv, game_params);
	assert(strcmp(game_params->phase, "placement") == 0);
	assert(strcmp(game_params->input_file, "input.txt") == 0);
	assert(strcmp(game_params->output_file, "out.txt") == 0);

	return 0;
}

int command_line_movement_test(int argc, char *argv[], GameParams *game_params) {
	argc = 4;
	argv[0] = "./penguins";
	argv[1] = "phase=movement";
	argv[2] = "input.txt";
	argv[3] = "out.txt";

	parse_command_line_arguments(argc, argv, game_params);
	assert(strcmp(game_params->phase, "movement") == 0);
	assert(strcmp(game_params->input_file, "input.txt") == 0);
	assert(strcmp(game_params->output_file, "out.txt") == 0);

	return 0;
}

int read_to_board_test(GameParams *game_params) {
	game_params->input_file = "./read_to_board_test.txt";

	read_to_board(game_params);
	assert(game_params->x_value == 6);
	assert(game_params->y_value == 5);
	assert(game_params->board[0][0] == 0);
	assert(game_params->board[1][1] == 10);
	assert(game_params->board[1][2] == 30);

	return 0;
}

int place_penguin_test(GameParams *game_params) {
	game_params->input_file = "./penguin_placement_test.txt";

	read_to_board(game_params);
	place_penguin(game_params);
	assert(game_params->board[0][0] == 0);
	assert(game_params->board[1][2] == 30);
	assert(game_params->board[1][1] == game_params->me_index);

	return 0;
}



int main(int argc, char *argv[]) {
	printf("TESTING...\n");

	GameParams game_params;
	GameParams* ptr_game_params = &game_params;

	command_line_placement_test(argc, argv, ptr_game_params);
	printf("\tcommand_line_placement_test: \tpassed \n");
	command_line_movement_test(argc, argv, ptr_game_params);
	printf("\tcommand_line_movement_test: \tpassed \n");
	read_to_board_test(ptr_game_params);
	printf("\tread_to_board_test: \tpassed \n");
	place_penguin_test(ptr_game_params);
	printf("\tplace_penguin_test: \tpassed \n");

}