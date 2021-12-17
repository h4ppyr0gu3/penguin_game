#include "game_params.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void read_to_board(GameParams* game_params) {
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	char* token;

	fp = fopen(game_params->input_file, "r");
	assert(fp != NULL);

	while ((read = getline(&line, &len, fp)) != -1) {
    // printf("%s", line);
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
    		// read players and scores
    		// printf("line number = %d\n", line_number);
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

	for (int i = 0; i < game_params->y_value; ++i)
	{
		for (int j = 0; j < game_params->x_value; ++j)
		{
			printf("%d ", game_params->board[i][j]);
		}
		printf("\n");
	}

	exit(EXIT_SUCCESS);

}

void select_available_positions(GameParams* game_params) {

}

void write_to_file(GameParams* game_params) {

}