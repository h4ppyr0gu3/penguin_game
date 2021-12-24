#include "game_params.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

	fp = fopen(game_params->input_file, "r");
	assert(fp != NULL);

	while ((read = getline(&line, &len, fp)) != -1) {
    if (line_number == 1) {
    	token = strtok(line, " ");
    	game_params->y_value = atoi(token);
    	token = strtok(NULL, " ");
    	game_params->x_value = atoi(token);
	    printf(" x  = %d y =  %d  \n", game_params->x_value, game_params->y_value);
	    game_params->board = malloc(game_params->y_value * sizeof(int*));
			for (int i = 0; i < game_params->y_value; ++i) {
				game_params->board[i] = malloc(game_params->x_value * sizeof(int));
			}
    } 
    if (line_number > 1) {
    	if (line_number > (1 + game_params->y_value)) {
    		token = strtok(line, " ");
    		if (strcmp(token, "TEAM_NAME_HERE") == 0)
    			game_params->me_index = line_number - 2 - game_params->y_value;
    		strcpy(game_params->player_name_array[line_number - 2 - game_params->y_value], token);
    		printf("%s\n", token);
    		printf("%s\n", game_params->player_name_array[line_number - 2 - game_params->y_value]);
    		printf("%d\n", line_number - 2 - game_params->y_value);
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

	fclose(fp);
	if (line)
	  free(line);

	return 1;
}

void select_available_positions(GameParams* game_params) {

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

	do {
		fprintf(fp, "%s %d %d\n", 
			game_params->player_name_array[index], 
			game_params->player_array[index], 
			game_params->scoreboard_array[index]
		);
		index++;
	} while (game_params->player_array[index] != 0);

	fclose(fp);

}