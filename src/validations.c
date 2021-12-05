#include <stdio.h>
#include <stdlib.h>
#include "game_params.h"
#include "validations.h"

int validate_x(GameParams *game_params, int* array) {
	if (game_params->x_value < array[0] || 0 > array[0]) {
		printf("\x1B[31minvalid parameters (x out of range)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_y(GameParams *game_params, int* array) {
	if (game_params->x_value < array[1] || 0 > array[1]) {
		printf("\x1B[31minvalid parameters (y out of range)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_placement(GameParams *game_params, int* array) {
	if (game_params->board[array[0]][array[1]] != 1) {
		printf("\x1B[31minvalid parameters (choose a tile with 1 fish)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_penguin(GameParams *game_params, int current_player, int* array) {
	if (game_params->board[array[0]][array[1]] != game_params->player_array[current_player]) {
		printf("\x1B[31minvalid parameters (choose a tile with your avatar)\033[0m \n");
		return 1;
	}
	return 0;
}

int validate_movement(GameParams *game_params, int* source, int* destination, int error) {
	int constant, lesser, greater;
	if(source[1] == destination[1]) {
		if(source[0] > destination[0]) {
			greater = source[0];
			lesser = destination[0];
			constant = source[1];
			validation_loop(constant, greater, lesser, game_params, 1, error);
		} else if (source[0] < destination[0]) {
			lesser = source[0];
			greater = destination[0];
			constant = source[1];
			validation_loop(constant, greater, lesser, game_params, 1, error);
		} else {
			return 1;
		}
	}	else if (source[0] == destination[0]) {
		if(source[1] > destination[1]) {
			greater = source[1];
			lesser = destination[1];
			constant = source[0];
			validation_loop(constant, greater, lesser, game_params, 0, error);
		} else if (source[1] < destination[1]) {
			lesser = source[1];
			greater = destination[1];
			constant = source[0];
			validation_loop(constant, greater, lesser, game_params, 0, error);
		} else {
			return 1;
		}
	} else {
		printf("\x1B[31minvalid movement please choose valid placement\033[0m \n");
		printf("\x1B[31mthis is else\033[0m \n");
		return 1;
	}
	return 0; 
}

int validation_loop(int constant, int greater, int lesser, GameParams *game_params, int flag, int error) {
	for(int i = lesser; i <= greater; i++) {
		if (flag == 1) { // y constant
			if (game_params->board[i][constant] == 0 || game_params->board[i][constant] > 10) {
				if (error) {
					printf("\x1B[31minvalid movement please avoid other players and ice\033[0m \n");
					printf("\x1B[31minvalid this is the if ice\033[0m \n");
					printf("i: %d, constant: %d\n", i, constant);
				}
				return 1;
			}
		} else if (flag == 0) { // x constant
			if (game_params->board[constant][i] == 0 || game_params->board[constant][i] > 10) {
				if (error) {
					printf("\x1B[31minvalid movement please avoid other players and ice\033[0m \n");
					printf("\x1B[31minvalid this is the else ice\033[0m \n");
					printf("i: %d, constant: %d\n", i, constant);
				}
				return 1;
			}
		}
	}
	return 0;
}

int validate_penguin_can_move(GameParams *game_params, int current_player, int* source) {
	int count = 0;
	int* destination = (int*)malloc(3 * sizeof(int));
	
	for(int i = 0; i < game_params->x_value; i++) {
		if(source[0] - i >= 0) {
			destination[1] = source[1];
			destination[0] = source[0] - i;
			if (!validate_movement(game_params, source, destination, 0)) 
				count++;
		}
		if(source[0] + i <= game_params->x_value) {
			destination[1] = source[1];
			destination[0] = source[0] + i;
			if (!validate_movement(game_params, source, destination, 0)) 
				count++;
		}
	}
	for(int i = 0; i < game_params->y_value; i++) {
		if(source[1] - i >= 0) {
			destination[1] = source[1] - i;
			destination[0] = source[0];
			if (!validate_movement(game_params, source, destination, 0)) 
				count++;
		}
		if(source[0] + i <= game_params->y_value) {
			destination[1] = source[1] + i;
			destination[0] = source[0];
			if (!validate_movement(game_params, source, destination, 0)) 
				count++;
		}
	}
	free(destination);
	return count;
}

int player_can_move(int current_player, GameParams *game_params) {
	int* source = (int*)malloc(3 * sizeof(int));
	int count = 0;
	for (int i = 0; i < game_params->x_value; ++i) {
		for (int j = 0; j < game_params->y_value; ++j) {
			if (game_params->board[i][j] == game_params->player_array[current_player]) {
				source[0] = i; 
				source[1] = j;
				if (validate_penguin_can_move(game_params, current_player, source) == 0) {
					count++;
				}
			}
		}
	}
	if (count == game_params->penguin_count)	{
		return 0;
	}
	return 1;
}