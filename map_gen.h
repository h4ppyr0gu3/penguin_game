void generate_map(int **board, int x_value, int y_value, int difficulty, int player_count, int penguin_count) {
	int map_point, one, two, three, ice, flag, random;
	one = player_count * penguin_count;
	double safe_ice = 0.1 * (x_value * y_value);
	ice = safe_ice;
	two = ceil(((x_value * y_value) - (one + ice)) / 2);
	three = (x_value * y_value) - (one + ice + two);
	flag = 0;

	// initialize with impossible values to check against

	for (int i = 0; i < x_value; ++i)	{
		for (int j = 0; j < y_value; ++j) {
			board[i][j] = -1;
		}
	}

	srand(time(NULL));

	while(check_board(x_value, y_value, board) == 1) {
		flag = 0;
		int x = rand() % x_value;
		int y = rand() % y_value;
		if (board[x][y] == -1) {
			while (flag == 0) {
				random = rand() % 4;
				switch (random) {
					case 0:
						if(ice > 0) {
							map_point = 0;
							ice--;
							flag++;
							break;
						} else {
							break;
						}
					case 1:
						if(one > 0) {
							map_point = 1;
							one--;
							flag++;
							break;
						} else {
							break;
						}
					case 2:
						if(two > 0) {
							map_point = 2;
							two--;
							flag++;
							break;
						} else {
							break;
						}
					case 3:
						if(three > 0) {
							map_point = 3;
							three--;
							flag++;
							break;
						} else {
							break;
						}
					default:
					break;
				}
			}
			board[x][y] = map_point;
		}
	}
}

int check_board(int x_value, int y_value, int **board) {
	for (int i = 0; i < x_value; ++i)	{
		for (int j = 0; j < y_value; ++j) {
			if (board[i][j] == -1) {
				return 1;
			}
		}
	}
	return 0;
}

