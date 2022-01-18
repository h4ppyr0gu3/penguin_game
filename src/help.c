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
	"Usage:\n"
  "./penguins [options]\n\n"
	"Options:\n\n"
	"-d, --default                default game parameters:\n"
	"                             x=10, y=10, penguins=3, players=2\n"
	"-t, --test                   test game parameters:\n"
	"                             x=3, y=3, penguins=1, players=2\n"
	"-h, --help                   print help and exit\n"
	"-x <integer>                 set number of columns\n"
	"-y <integer>                 set number of rows\n"
	"--player-count <integer>     set player count (< 6)\n"
	"--penguin-count <integer>    set penguins per player\n"
	"name                         prints name of group\n"
	);
	printf("\n");
}