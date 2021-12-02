#include "help.h"
#include <stdio.h>

void help_me() {
	printf("Welcome to the Penguin game help page\n"
	"-d/--default\t\tThis sets the game parameters to default\n"
	"\t\t\tie. Penguin count: 5\n"
	"\t\t\t    Player count: 2\n"
	"\t\t\t    plane settings (x*y): (15*26)\n"
	"\t\t\t    difficulty: 5\n"
	"-t/--test\t\tthis creates a test setup with smaller board to run through the program quicker\n"
	"\t\t\tie. Penguin count: 2\n"
	"\t\t\t    Player count: 2\n"
	"\t\t\t    plane settings (x*y): (3*3)\n"
	"\t\t\t    difficulty: 2\n"
	""
	);
	printf("\n");
}