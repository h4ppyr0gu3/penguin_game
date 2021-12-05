// #include "avatar.h"
#include "game_params.h"
#include <stdio.h>
#include <stdlib.h>

void choose_avatar(GameParams *game_params) {
	const char* clear = "clear";
	int player = 0, flag, for_flag;
	for (int i = 0; i < game_params->player_count; i++) {
		flag = 1;
		while (flag == 1) {
			for_flag = 1;
			printf("Player %d:\n", (i + 1));
			printf("\t please choose an avatar: \n ");
			printf("\t\t 1: \t \033[3;100;30m!\033[0m \n ");
			printf("\t\t 2: \t \033[3;44;30m@\033[0m \n ");
			printf("\t\t 3: \t \033[3;42;30m#\033[0m \n ");
			printf("\t\t 4: \t \033[3;43;30m$\033[0m \n ");
			printf("\t\t 5: \t \x1B[35m%%\033[0m \n ");
			printf("\t\t 6: \t \033[3;104;30m&\033[0m \n\n ");
			printf("Value: ");
			scanf(" %d", &player);

			system(clear);

			for(int j = 0; j < game_params->player_count; ++j) {
				if (game_params->player_array[j] == (10 + player)) {
					for_flag = 0;
					printf("that avatar has been taken, please choose another one \n");
				}
			}
			if (player < 7 && player > 0 && for_flag == 1) {
				game_params->player_array[i] = 10 + player;
				flag = 0;
			}
		}
	}
}