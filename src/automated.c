#include "game_params.h"
#include "validations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 
#include <time.h> 

char* format_print(int value);
char* itoa(int value, char* result, int base);

int read_to_board(GameParams* game_params) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	char* token;

	game_params->player_array = malloc(9 * sizeof(int));
	game_params->scoreboard_array = malloc(9 * sizeof(int));
	game_params->player_name_array = malloc(9 * sizeof(char*));
	for(int i = 0; i < 9; i++) {
		game_params->player_name_array[i] = malloc(50 * sizeof(char));
	}
	game_params->me_index = 0;

	fp = fopen(game_params->input_file, "r");
	assert(fp != NULL);

	while ((read = getline(&line, &len, fp)) != -1) {
    if (line_number == 1) {
    	token = strtok(line, " ");
    	game_params->y_value = atoi(token);
    	token = strtok(NULL, " ");
    	game_params->x_value = atoi(token);
    	assert(game_params->x_value > 0);
    	assert(game_params->y_value > 0);
	    game_params->board = malloc(game_params->y_value * sizeof(int*));
			for (int i = 0; i < game_params->y_value; ++i) {
				game_params->board[i] = malloc(game_params->x_value * sizeof(int));
			}
    } 
    if (line_number > 1) {
    	if (line_number > (1 + game_params->y_value)) {
    		token = strtok(line, " ");
    		if (strcmp(token, "TEAM_NAME_HERE") == 0) {
    			game_params->me_index = line_number - 1 - game_params->y_value;
    		}
    		strcpy(game_params->player_name_array[line_number - 2 - game_params->y_value], token);
				token = strtok(NULL, " ");
				game_params->player_array[line_number - 2 - game_params->y_value] = atoi(token);
				token = strtok(NULL, " ");
				game_params->scoreboard_array[line_number - 2 - game_params->y_value] = atoi(token);
    	} else {
    		token = strtok(line, " ");
  			game_params->board[line_number - 2][0] = atoi(token);
				token = strtok(NULL, " ");
    		for (int i = 1; i < game_params->x_value; i++) {
    			game_params->board[line_number - 2][i] = atoi(token);
				  token = strtok(NULL, " ");
    		}
    	}
    }
    line_number++;
	}
	if(game_params->me_index == 0) {
		int count = 0;
		while(game_params->player_array[count] != 0 && game_params->player_array[count] < 10) {
			count += 1;
		}
		char token[15] = "TEAM_NAME_HERE";
		game_params->me_index = (count + 1);
    strcpy(game_params->player_name_array[count], token);
    game_params->player_array[count] = (count + 1);
	}

	fclose(fp);
	if (line)
	  free(line);

	return 1;
}

void place_penguin(GameParams* game_params) {
	srand(time(NULL));

	int flag = 0;

	do {
		int x = rand() % game_params->x_value;
		int y = rand() % game_params->y_value;
		if (game_params->board[x][y] == 10) {
			game_params->board[x][y] = game_params->player_array[game_params->me_index - 1];
			game_params->scoreboard_array[game_params->me_index - 1] += 1;
			flag = 0;
		} else {
			flag = 1;
		}
	} while (flag == 1);
}

int move_penguin(GameParams* game_params) {
	int *vector_x, *vector_y;
	int count = 0;

	vector_y = (int*)malloc(100 * sizeof(int));
	vector_x = (int*)malloc(100 * sizeof(int));

	for (int i = 0; i < game_params->x_value; ++i)	{
		for (int j = 0; j < game_params->y_value; ++j) {
			if(game_params->board[i][j] == game_params->me_index) {
				vector_x[count] = i;
				vector_y[count] = j;
				count++;
			}
		}
	}

	game_params->penguin_count = count;
	
	if (i_can_move(game_params, vector_x, vector_y) == 0) {
		srand(time(NULL));

		int error = 0, count = 0;
		while(error == 0) {
			int penguin = rand() % game_params->penguin_count;

			int x = rand() % game_params->x_value;
			int y = rand() % game_params->y_value;
			int source[3] = {vector_x[penguin], vector_y[penguin]};
			int *destination = (int*)malloc(3 * sizeof(int));

			if ((count % 2) == 0) {
				destination[0] = vector_x[penguin];
				destination[1] = y;
			} else {
				destination[0] = x;
				destination[1] = vector_y[penguin];
			}

			if (validate_movement_auto(game_params, source, destination) != 1) {
				if (game_params->board[destination[0]][destination[1]] == 0 || 
						game_params->board[destination[0]][destination[1]] % 10 != 0)
					return 2;
				int add_score = game_params->board[destination[0]][destination[1]] / 10;
				game_params->scoreboard_array[game_params->me_index - 1] += add_score;
				game_params->board[destination[0]][destination[1]] = game_params->me_index;
				game_params->board[source[0]][source[1]] = 0;
				error = 1;
			}
			count++;
		}
	} else {
		return 1;
	}

	return 0;
}

void write_to_file(GameParams* game_params) {
	FILE* fp;

	fp = fopen(game_params->output_file, "w");

	fprintf(fp, "%d %d\n", game_params->y_value, game_params->x_value);
	for (int i = 0; i < game_params->y_value; ++i) {
		for (int j = 0; j < game_params->x_value; ++j) {
			if (game_params->board[i][j] == 0) {
				fprintf(fp, "00 ");
			} else if (game_params->board[i][j] > 0 && game_params->board[i][j] / 10 == 0) {
				fprintf(fp, "0%d ", (game_params->board[i][j]));
			} else {
				fprintf(fp, "%d ", (game_params->board[i][j]));
			}
		}
		fprintf(fp, "\n");
	}

	int index = 0;

	while (game_params->player_array[index] != 0) {
		fprintf(fp, "%s %d %d\n", 
			game_params->player_name_array[index], 
			game_params->player_array[index], 
			game_params->scoreboard_array[index]
		);
		index++;
	} 

	fclose(fp);

}