#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arguments.h"
#include "interactive.h"
#include "automated.h"

int main(int argc, char *argv[]) {

	GameParams game_params;
	GameParams *params_ptr = &game_params;
	char *clear = "clear";

	parse_command_line_arguments(argc, argv, params_ptr);
	if ((strcmp(game_params.phase, "interactive") == 0)) {
		collect_remaining_arguments(params_ptr);
		system(clear);
		interactive(params_ptr);
	} else if ((strcmp(game_params.phase, "placement") == 0)) {
		// auto_placement(params_ptr);
		printf("read");

		int a = read_to_board(params_ptr);
		printf("read: %d", a);
		// select_available_positions(params_ptr);
		write_to_file(params_ptr);
		printf("wrote");
	} else if ((strcmp(game_params.phase, "movement") == 0)) {
		read_to_board(params_ptr);
		write_to_file(params_ptr);
		// auto_movement(params_ptr);
	}
	
	return 1;
}