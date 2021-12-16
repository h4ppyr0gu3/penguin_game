#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "read_values.h"
#include "help.h"

int read_values(int *array) {
	printf("Please enter values (x y): ");
	scanf("%d %d", &array[1], &array[0]);
	for (int i = 0; i < 2; ++i)
		array[i] = array[i] - 1;
	fflush(stdin);
	return 0;
}
