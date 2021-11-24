#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "help.h"
#include "game_params.h"
#include "printer.h"
#include "map_gen.h"
#include "avatar.h"
#include "placement.h"

int x_value, y_value , penguin_count , player_count, difficulty, some; 

 

int parse_command_line_arguments(int, char **, GameParams *);
int collect_remaining_arguments(GameParams *);
// int movement(int *, int **, int, int, int, int*);

int main(int argc, char *argv[]) {

	GameParams game_params;
	GameParams *params_ptr = &game_params;

	char *clear = "clear";
	system(clear);

	parse_command_line_arguments(argc, argv, params_ptr);
	collect_remaining_arguments(params_ptr);
	system(clear); 

	// game_params.board = malloc(x_value * sizeof(int*));
	// for (int i = 0; i < x_value; ++i) {
	// 	game_params.board[i] = malloc(y_value * sizeof(int));
	// }

	// game_params.board = board;


	game_params.player_array = (int*)malloc(game_params.player_count * sizeof(int)); 
	for (int i = 0; i < game_params.player_count; ++i)
	{
		params_ptr->player_array[i] = 10;
		printf("%d\n", params_ptr->player_array[i]);
	}

	printf("\n%d\n", params_ptr->player_count);
	 // = player_array;
  
	// int *scoreboard_array = (int*)malloc(game_params.player_count * sizeof(int)); 
	// game_params.scoreboard_array = scoreboard_array;

	choose_avatar(params_ptr); 
	// system(clear);

	printf("before map generate_map");


	generate_map(params_ptr);

	placement(params_ptr); 

	print_stage(params_ptr);

	// movement(player_array, board, penguin_count, x_value, y_value, score_board_array); 

	for (int i = 0; i < x_value; ++i) {
		free(game_params.board[i]);
	}
	free(game_params.board);
	free(game_params.player_array);
}

// int movement(int *player_array, int **board, int penguin_count, int x_value, int y_value, int *score_board_array) {
// 	int size = sizeof(player_array) / sizeof(player_array[0]);
// 	char move[10];
// 	char *clear = "clear";
// 	int error_count, x, y;
// 	int count = 0;
// 	int x_source, y_source, x_dest, y_dest;

// 	/* check if player can move */

// 	for (int i = 0; i < penguin_count ; ++i) {
// 		for (int j = 0; j < size; ++j) {
// 			int dest_flag = 0;
// 			do {
// 				print_stage(x_value, y_value, board);
// 				print_scoreboard(score_board_array);
// 				printf("Player %d: \n ", (j + 1));
// 				printf("\t please select a penguin source - destination\n\t ie: \"a1-a2\": ");
// 				scanf(" %s", move);
// 				system(clear);

// 				error_count = 0;

// 				x_source = move[0] - 97;
// 				y_source = atoi(&move[1]) - 1;

// 				if (board[x_source][y_source] != player_array[j]) {
// 					error_count++;
// 					printf("\nPlease select your own penguin\n");
// 				}

// 				for (int k = 0; k < strlen(move); ++k) {
// 					if (move[k] == 45) {
// 						dest_flag++;
// 					}
// 					if (dest_flag == 1) {
// 						x_dest = move[k+1] - 97;
// 						y_dest = atoi(&move[k+2]) - 1;
// 						break;
// 					}
// 				}

// 				if (x_source < 0 || 
// 						x_source > x_value ||
// 						x_dest < 0 ||
// 						x_dest > x_value ||
// 						y_source < 0 || 
// 						y_source > y_value ||
// 						y_dest < 0 ||
// 						y_dest > y_value ) {
// 					error_count++;
// 					printf("invalid parameters");
// 				}

// 				if(x_dest == x_source && y_dest != y_source) {
// 					if (y_source > y_dest) {
// 						for (int i = y_dest; i < y_source; ++i) {
// 							if (board[x_source][i] == 2 || board[x_source][i] == 3) {
// 								continue;
// 							} else {
// 								error_count++;
// 								printf("invalid parameters");
// 							}
// 						}
// 					} else {
// 						for (int i = y_source; i < y_dest; ++i) {
// 							if (board[x_source][i] == 2 || board[x_source][i] == 3) {
// 								continue;
// 							} else {
// 								error_count++;
// 								printf("invalid parameters");
// 							}
// 						}
// 					}
// 				} else if (y_dest == y_source && x_dest != x_source) {
// 					if (x_source > x_dest) {
// 						for (int i = x_dest; i < x_source; ++i)	{
// 							if (board[i][y_source] == 2 || board[i][y_source] == 3) {
// 								continue;
// 							} else {
// 								error_count++;
// 								printf("invalid parameters");
// 							}
// 						}
// 					} else {
// 						for (int i = 0; i < count; ++i) {
// 							if (board[i][y_source] == 2 || board[i][y_source] == 3) {
// 								continue;
// 							} else {
// 								error_count++;
// 								printf("invalid parameters");
// 							}
// 						}
// 					}
//  				} else {
// 					error_count++;
// 					printf("invalid parameters");
// 				}
// 			} while (error_count > 0);
// 	// int source_len = sizeof(source) / sizeof(source[0]);
// 	// int dest_len = sizeof(dest) / sizeof(dest[0]);

// 	// for (int l = 0; l < source_len; ++l)
// 	// {
// 	// 	printf("\n\n\n%d", source[source_len]);
// 	// }
			
// 		}
// 	}
// }



// Collect arguments and set the global variables

int parse_command_line_arguments(int argc, char *argv[], GameParams *game_params) {
	for (int i = 1; i < argc; ++i) {
		if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0)) {
			help_me();
			exit(0);
		} else if (strcmp(argv[i], "-x") == 0) {
		  game_params->x_value = atoi(argv[i+1]);
		  i++;
		} else if (strcmp(argv[i], "-y") == 0) {
			game_params->y_value = atoi(argv[i+1]);
		  i++;
		} else if (strcmp(argv[i], "--player-count") == 0) {
			game_params->player_count = atoi(argv[i+1]);
			i++;
		} else if (strcmp(argv[i], "--penguin-count") == 0) {
			game_params->penguin_count = atoi(argv[i+1]);
			i++;
		}  else if ((strcmp(argv[i], "--default") == 0) || (strcmp(argv[i], "-d") == 0)) {
			game_params->x_value = 26;
			game_params->y_value = 15;
			game_params->player_count = 2;
			game_params->penguin_count = 5;
			game_params->difficulty = 5;
		} else if ((strcmp(argv[i], "--test") == 0) || (strcmp(argv[i], "-t") == 0)) {
			game_params->x_value = 3;
			game_params->y_value = 3;
			game_params->player_count = 2;
			game_params->penguin_count = 2;
			game_params->difficulty = 5;
		} else {
			printf("use \"--help\" or \"-h\" flag for help \n");
			break;
		}
	}
	return 0;
}

int collect_remaining_arguments(GameParams *game_params) {
	if(game_params->x_value == 0) {
		printf("\nplease enter an integer for x_value: ");
		scanf(" %d", &game_params->x_value);
	}	if(game_params->y_value == 0) {
		printf("\nplease enter an integer for y_value: ");
		scanf(" %d", &game_params->y_value);
	}	if(game_params->player_count == 0) {
		printf("\nplease enter an integer for player_count: ");
		scanf(" %d", &game_params->player_count);
	}	if(game_params->penguin_count == 0) {
		printf("\nplease enter an integer for penguin_count: ");
		scanf(" %d", &game_params->penguin_count);
	}	if(game_params->difficulty == 0) {
		printf("\nplease enter an integer for difficulty (1 -> 10): ");
		scanf(" %d", &game_params->difficulty);
	}	
}
