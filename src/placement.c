#include "game_params.h"
#include "placement.h"
#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
#include "read_values.h"
#include "validations.h"

void placement(GameParams *game_params) {
	char *clear = "clear";
	int error_count, x, y;
	int *array = (int*)malloc(3 * sizeof(int));

	for (int i = 0; i < game_params->penguin_count ; ++i) {
		for (int j = 0; j < game_params->player_count; ++j) {
			do {
				print_stage(game_params);
				printf("Player %d: \n ", (j + 1));
				printf("\t please select a place to put penguins \n\t: ");
				read_values(array);
				system(clear);

				error_count = 0;
				error_count += validate_x(game_params, array);
				error_count += validate_y(game_params, array);
				error_count += validate_placement(game_params, array);

				x = array[0];
				y = array[1];

				if (error_count == 0) {
					game_params->board[x][y] = game_params->player_array[j];
				}
			} while (error_count > 0);
		}
	}
}

