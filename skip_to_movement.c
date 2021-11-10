#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "printer.h"

int x_value, y_value , penguin_count , player_count, difficulty, some; 

int parse_command_line_arguments(int, char **);
int collect_remaining_arguments();
int movement(int *, int **, int, int, int, int*);

int main(int argc, char *argv[]) {

	x_value = 3;
	y_value = 3;
	player_count = 2;
	penguin_count = 2;
	difficulty = 5;

	int** board = (int**)malloc(x_value * sizeof(int*));
	for (int i = 0; i < x_value; ++i) {
		board[i] = (int*)malloc(y_value * sizeof(int));
	}	

	int *player_array;
	player_array = (int *)malloc(player_count * sizeof(int)); 

	int *score_board_array;
	score_board_array = (int *)malloc(player_count * sizeof(int)); 

	board[0][0] = 11;
	board[0][1] = 12;
	board[0][2] = 2;
	board[1][0] = 3;
	board[2][0] = 11;
	board[1][1] = 12;
	board[2][2] = 2;
	board[1][2] = 3;
	board[2][1] = 2;

	player_array[0] = 11;
	player_array[1] = 12;

	score_board_array[0] = 0;
	score_board_array[1] = 0;

	movement(player_array, board, penguin_count, x_value, y_value, score_board_array); 

}

int movement(int *player_array, int **board, int penguin_count, int x_value, int y_value, int *score_board_array) {
	int size = sizeof(player_array) / sizeof(player_array[0]);
	char move[10];
	char *clear = "clear";
	int error_count, x, y;
	int count = 0;
	int x_source, y_source, x_dest, y_dest;

	/* check if player can move */

	for (int i = 0; i < penguin_count ; ++i) {
		for (int j = 0; j < size; ++j) {
			int dest_flag = 0;
			do {
				print_stage(x_value, y_value, board);
				print_scoreboard(score_board_array);
				printf("Player %d: \n ", (j + 1));
				printf("\t please select a penguin source - destination\n\t ie: \"a1-a2\": ");
				scanf(" %s", move);
				// system(clear);

				error_count = 0;

				x_source = move[0] - 97;
				y_source = atoi(&move[1]) - 1;

				if (board[x_source][y_source] != player_array[j]) {
					error_count++;
					printf("\nPlease select your own penguin\n");
				}

				for (int k = 0; k < strlen(move); ++k) {
					if (move[k] == 45) {
						dest_flag++;
					}
					if (dest_flag == 1) {
						x_dest = move[k+1] - 97;
						y_dest = atoi(&move[k+2]) - 1;
						break;
					}
				}

				printf("\nx_source = %d, y_source = %d\nx_dest = %d, y_dest = %d \n", x_source, y_source, x_dest, y_dest);

				if (x_source < 0 || 
						x_source > x_value ||
						x_dest < 0 ||
						x_dest > x_value ||
						y_source < 0 || 
						y_source > y_value ||
						y_dest < 0 ||
						y_dest > y_value ) {
					error_count++;
					printf("invalid parameters");
				}

				if(x_dest == x_source && y_dest != y_source) {
					if (y_source > y_dest) {
						for (int i = y_dest; i < y_source; ++i) {
							if (board[x_source][i] == 2 || board[x_source][i] == 3) {
								continue;
							} else {
								error_count++;
								printf("invalid parameters");
							}
						}
					} else {
						for (int i = y_source; i < y_dest; ++i) {
							if (board[x_source][i] == 2 || board[x_source][i] == 3) {
								continue;
							} else {
								error_count++;
								printf("invalid parameters");
							}
						}
					}
				} else if (y_dest == y_source && x_dest != x_source) {
					if (x_source > x_dest) {
						for (int i = x_dest; i < x_source; ++i)	{
							if (board[i][y_source] == 2 || board[i][y_source] == 3) {
								continue;
							} else {
								error_count++;
								printf("invalid parameters");
							}
						}
					} else {
						for (int i = 0; i < count; ++i) {
							if (board[i][y_source] == 2 || board[i][y_source] == 3) {
								continue;
							} else {
								error_count++;
								printf("invalid parameters");
							}
						}
					}
 				} else {
					error_count++;
					printf("invalid parameters");
				}
			} while (error_count > 0);
		}
	}
}
