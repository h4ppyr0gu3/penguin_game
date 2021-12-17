#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interactive.h"

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

	} else if ((strcmp(game_params.phase, "movement") == 0)) {

	}
	
	return 1;
}