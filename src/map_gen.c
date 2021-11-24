#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "game_params.h"
#include "map_gen.h"

void generate_map(GameParams *game_params) {
	int map_point, one, two, three, ice, flag, random;
	one = game_params->player_count * game_params->penguin_count;
	double safe_ice = 0.1 * (game_params->x_value * game_params->y_value);
	ice = safe_ice;
	two = ceil(((game_params->x_value * game_params->y_value) - (one + ice)) / 2);
	three = (game_params->x_value * game_params->y_value) - (one + ice + two);
	flag = 0;

	// initialize with impossible values to check against

	for (int i = 0; i < game_params->x_value; ++i)	{
		for (int j = 0; j < game_params->y_value; ++j) {
			game_params->board[i][j] = -1;
		}
	}

	srand(time(NULL));

	while(check_board(game_params) == 1) {
		flag = 0;
		int x = rand() % game_params->x_value;
		int y = rand() % game_params->y_value;
		if (game_params->board[x][y] == -1) {
			while (flag == 0) {
				random = rand() % 4;
				switch (random) {
					case 0:
						if(ice > 0) {
							map_point = 0;
							ice--;
							flag++;
							break;
						} else {
							break;
						}
					case 1:
						if(one > 0) {
							map_point = 1;
							one--;
							flag++;
							break;
						} else {
							break;
						}
					case 2:
						if(two > 0) {
							map_point = 2;
							two--;
							flag++;
							break;
						} else {
							break;
						}
					case 3:
						if(three > 0) {
							map_point = 3;
							three--;
							flag++;
							break;
						} else {
							break;
						}
					default:
					break;
				}
			}
			game_params->board[x][y] = map_point;
		}
	}
}

int check_board(GameParams *game_params) {
	for (int i = 0; i < game_params->x_value; ++i)	{
		for (int j = 0; j < game_params->y_value; ++j) {
			if (game_params->board[i][j] == -1) {
				return 1;
			}
		}
	}
	return 0;
}

