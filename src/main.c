#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "arguments.h" 
#include "interactive.h"
#include "automated.h"

int main(int argc, char *argv[]) {

	GameParams game_params;
	GameParams *params_ptr = &game_params;
	char *clear = "clear";
	int rtrn = 0;

	parse_command_line_arguments(argc, argv, params_ptr);

	if ((strcmp(game_params.phase, "interactive") == 0)) {
		collect_remaining_arguments(params_ptr);
		system(clear);
		interactive(params_ptr);
	} else if ((strcmp(game_params.phase, "placement") == 0)) {
		read_to_board(params_ptr);
		place_penguin(params_ptr);
		write_to_file(params_ptr);
	} else if ((strcmp(game_params.phase, "movement") == 0)) {
		read_to_board(params_ptr);
		rtrn = move_penguin(params_ptr);
		write_to_file(params_ptr);
	}
	
	return rtrn;
}