#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "printer.h"
#include "map_gen.h"
#include "avatar.h"

int x_value, y_value , penguin_count , player_count, difficulty, some; 

int parse_command_line_arguments(int, char **);
int collect_remaining_arguments();

int main(int argc, char *argv[]) {
	char *clear = "clear";
	system(clear);

	parse_command_line_arguments(argc, argv);
	collect_remaining_arguments();
	system(clear);

	int** board = (int**)malloc(x_value * sizeof(int*));
	for (int i = 0; i < x_value; ++i) {
		board[i] = (int*)malloc(y_value * sizeof(int));
	}	

	int *player_array;
	player_array = (int *)malloc(player_count * sizeof(int)); 

	choose_avatar(player_count, player_array);
	system(clear);

	generate_map(board, x_value, y_value, difficulty, player_count, penguin_count);
	print_stage(x_value, y_value, board);


	for (int i = 0; i < x_value; ++i) {
		free(board[i]);
	}
	free(board);
	free(player_array);

}
















// Collect arguments and set the global variables

int parse_command_line_arguments(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0)) {
			help_me();
			exit(0);
		} else if (strcmp(argv[i], "-x") == 0) {
		  x_value = atoi(argv[i+1]);
		  i++;
		} else if (strcmp(argv[i], "-y") == 0) {
			y_value = atoi(argv[i+1]);
		  i++;
		} else if (strcmp(argv[i], "--player-count") == 0) {
			player_count = atoi(argv[i+1]);
			i++;
		} else if (strcmp(argv[i], "--penguin-count") == 0) {
			penguin_count = atoi(argv[i+1]);
			i++;
		}  else if ((strcmp(argv[i], "--default") == 0) || (strcmp(argv[i], "-d") == 0)) {
			x_value = 26;
			y_value = 15;
			player_count = 2;
			penguin_count = 5;
			difficulty = 5;
		} else {
			printf("use \"--help\" or \"-h\" flag for help \n");
			break;
		}
	}
	return 0;
}

int collect_remaining_arguments() {
	if(x_value == 0) {
		printf("\nplease enter an integer for x_value: ");
		scanf(" %d", &x_value);
	}	if(y_value == 0) {
		printf("\nplease enter an integer for y_value: ");
		scanf(" %d", &y_value);
	}	if(player_count == 0) {
		printf("\nplease enter an integer for player_count: ");
		scanf(" %d", &player_count);
	}	if(penguin_count == 0) {
		printf("\nplease enter an integer for penguin_count: ");
		scanf(" %d", &penguin_count);
	}	if(difficulty == 0) {
		printf("\nplease enter an integer for difficulty: ");
		scanf(" %d", &difficulty);
	}	
}
