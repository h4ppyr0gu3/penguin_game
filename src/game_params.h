#ifndef GAME_PARAMS_H
#define GAME_PARAMS_H

/**
* defines stucks to store game state so that it's easily accesible
*/

typedef struct {
	int x_value;
	int y_value;
	int penguin_count;
	int player_count;
	int** board;
	int* player_array;
	char** player_name_array;
	int me_index;
	int* scoreboard_array;
	char* phase;
	char* input_file;
	char* output_file;
} GameParams; // Declare game params struct

#endif
