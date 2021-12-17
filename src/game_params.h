#ifndef GAME_PARAMS_H
#define GAME_PARAMS_H

typedef struct {
	int x_value;
	int y_value;
	int penguin_count;
	int player_count;
	int** board;
	int* player_array;
	int* scoreboard_array;
	char* phase;
	char* input_file;
	char* output_file;
} GameParams; // Declare game params struct

#endif