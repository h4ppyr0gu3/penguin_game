int print_stage(int x, int y, int **array) {
	const char *letters[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	for (int i = -1; i < x; ++i) {
		for (int j = -1; j < y; ++j) {
			if (i < 0 && j < 0) {
				printf("\t y\\x \t");
			} else if (i < 0) {
				printf("\t %d", j + 1);
			} else if (j < 0) {
				printf("\t %s \t", letters[i]);
			} else {
				switch ( array[i][j] ) {
					case 0: 
					printf("\t \033[1;47;35mx\033[0m");
					break;
					case 1:
					printf("\t \x1B[31m1\033[0m");
					break;
					case 2:
					printf("\t \x1B[93m2\033[0m");
					break;
					case 3:
					printf("\t \x1B[32m3\033[0m");
					break;
					case 11:
					printf("\t \033[3;100;30m!\033[0m");
					break;
					case 12:
					printf("\t \033[3;44;30m@\033[0m");
					break;
					case 13:
					printf("\t \033[3;42;30m#\033[0m");
					break;
					case 14:
					printf("\t \033[3;43;30m$\033[0m");
					break;
					case 15:
					printf("\t \x1B[35m%%\033[0m");
					break;
					case 16:
					printf("\t \033[3;104;30m&\033[0m");
					break;
					default:
					printf("\t 2");
					break;
				}
			}
		}
		if (i < 0 ) {
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
