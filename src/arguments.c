#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arguments.h"
#include "help.h"

void parse_command_line_arguments(int argc, char *argv[], GameParams *game_params) {
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			/** Automated mode **/
			if (strcmp(argv[i], "phase=placement") == 0) {
				game_params->phase = "placement";
				assert(strstr(argv[i+1], "penguins="));
				assert(argv[i+2] != NULL);
				assert(argv[i+3] != NULL);
				game_params->input_file = argv[i+2];
				game_params->output_file = argv[i+3];
				break;
			} else if (strcmp(argv[i], "phase=movement") == 0) {
			  assert(argv[i+1] != NULL);
				assert(argv[i+2] != NULL);
				game_params->input_file = argv[i+1];
				game_params->output_file = argv[i+2];
				game_params->phase = "movement";
				break;
			} else if ((strcmp(argv[i], "name") == 0) || (strcmp(argv[i], "--help") == 0)) {
				printf("epfu21Z-104-b");
				exit(0);
			}
			/** Interactive mode **/
			else if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0)) {
				help_me();
				exit(0);
			} else if (strcmp(argv[i], "-x") == 0) {
			  (*game_params).x_value = atoi(argv[i+1]);
				game_params->phase = "interactive";
			  i++;
			} else if (strcmp(argv[i], "-y") == 0) {
				(*game_params).y_value = atoi(argv[i+1]);
				game_params->phase = "interactive";
			  i++;
			} else if (strcmp(argv[i], "--player-count") == 0) {
				(*game_params).player_count = atoi(argv[i+1]);
				game_params->phase = "interactive";
				i++;
			} else if (strcmp(argv[i], "--penguin-count") == 0) {
				(*game_params).penguin_count = atoi(argv[i+1]);
				game_params->phase = "interactive";
				i++;
			}  else if ((strcmp(argv[i], "--default") == 0) || (strcmp(argv[i], "-d") == 0)) {
				(*game_params).x_value = 26;
				(*game_params).y_value = 26;
				(*game_params).player_count = 2;
				(*game_params).penguin_count = 5;
				game_params->phase = "interactive";
			} else if ((strcmp(argv[i], "--test") == 0) || (strcmp(argv[i], "-t") == 0)) {
				(*game_params).x_value = 3;
				(*game_params).y_value = 3;
				(*game_params).player_count = 2;
				(*game_params).penguin_count = 2;
				game_params->phase = "interactive";
			} else {
				printf("use \"--help\" or \"-h\" flag for help \n");
				game_params->phase = "interactive";
				break;
			}
		} 
	} else {
		game_params->phase = "interactive";
	}
}

// for interactive mode
void collect_remaining_arguments(GameParams *game_params) {
	if(game_params->y_value == 0) {
		printf("\nplease enter an integer for x_value: ");
		scanf(" %d", &game_params->y_value);
	}	if(game_params->x_value == 0) {
		printf("\nplease enter an integer for y_value: ");
		scanf(" %d", &game_params->x_value);
	}	if(game_params->player_count == 0) {
		printf("\nplease enter an integer for player_count: ");
		scanf(" %d", &game_params->player_count);
	}	if(game_params->penguin_count == 0) {
		printf("\nplease enter an integer for penguin_count: ");
		scanf(" %d", &(*game_params).penguin_count);
	}	
}
