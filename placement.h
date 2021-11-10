int placement(int *player_array, int **board, int penguin_count, int x_value, int y_value) {
	int size = sizeof(player_array) / sizeof(player_array[0]);
	char position[5];
	char *clear = "clear";
	int error_count, x, y;

	for (int i = 0; i < penguin_count ; ++i) {
		for (int j = 0; j < size; ++j) {
			do {
				print_stage(x_value, y_value, board);
				printf("Player %d: \n ", (j + 1));
				printf("\t please select a place to put penguins \n\t ie: \"a1\": ");
				scanf(" %s", position);
				system(clear);

				error_count = 0;
				x = position[0] - 97;
				y = atoi(&position[1]) - 1;

				if (x > x_value && error_count == 0) {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;} 

				if (y > y_value && error_count == 0) {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;}

				if(board[x][y] == 1 && error_count == 0) {
					board[x][y] = player_array[j];} 
				else {
					printf("\x1B[31minvalid parameters\033[0m \n");
					error_count++;}

			} while (error_count > 0);
		}
	}
}