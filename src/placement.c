#include "game_params.h"
#include "placement.h"
#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

void placement(GameParams *game_params) {
	char position[5];
	char *clear = "clear";
	int error_count, x, y;

	for (int i = 0; i < game_params->penguin_count ; ++i) {
		for (int j = 0; j < game_params->player_count; ++j) {
			do {
				print_stage(game_params);
				printf("Player %d: \n ", (j + 1));
				printf("\t please select a place to put penguins \n\t ie: \"a1\": ");
				scanf(" %s", position);
				system(clear);

				error_count = 0;
				x = position[0] - 97;
				y = atoi(&position[1]) - 1;

				if (x > game_params->x_value && error_count == 0) {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;} 

				if (y > game_params->y_value && error_count == 0) {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;}

				if(game_params->board[x][y] == 1 && error_count == 0) {
					game_params->board[x][y] = game_params->player_array[j];}
				else {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;}

			} while (error_count > 0);
		}
	}
}