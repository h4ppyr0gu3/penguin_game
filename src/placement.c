#include "game_params.h"
#include "placement.h"
#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
#include "read_params.h"
#include "read_values.h"
// #include <math.h>

void placement(GameParams *game_params) {
	char *clear = "clear";
	int error_count, x, y;
	ReadParams read_params_struct;
	ReadParams *read_params = &read_params_struct;

	for (int i = 0; i < game_params->penguin_count ; ++i) {
		for (int j = 0; j < game_params->player_count; ++j) {
			do {
				print_stage(game_params);
				printf("Player %d: \n ", (j + 1));
				printf("\t please select a place to put penguins \n\t ie: \"1-3-\": ");
				read_values(read_params);
				// system(clear);

				error_count = 0;
				error_count += validate_x(game_params, read_params);
				error_count += validate_y(game_params, read_params);
				error_count += validate_read_params(read_params);
				error_count += validate_placement(game_params, read_params);

				x = read_params->read_array[0] - 1;
				y = read_params->read_array[1] - 1;

				if (error_count == 0) {
					game_params->board[x][y] = game_params->player_array[j];
				}
			} while (error_count > 0);
		}
	}
}

int validate_read_params(ReadParams *read_params) {
	if(read_params->value_count > 2 || read_params->value_count < 2) {
		printf("\x1B[31minvalid parameters (incorrect number of arguments)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_x(GameParams *game_params, ReadParams *read_params) {
	if (game_params->x_value < read_params->read_array[0] - 1 || 0 > read_params->read_array[0] - 1) {
		printf("\x1B[31minvalid parameters (x out of range)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_y(GameParams *game_params, ReadParams *read_params) {
	if (game_params->x_value < read_params->read_array[1] - 1|| 0 > read_params->read_array[1] - 1) {
		printf("\x1B[31minvalid parameters (y out of range)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_placement(GameParams *game_params, ReadParams *read_params) {
	if (game_params->board[read_params->read_array[0] - 1][read_params->read_array[1] - 1] != 1) {
		printf("\x1B[31minvalid parameters (choose a tile with 1 fish)\033[0m \n");
		return 1;
	}
	return 0;
}