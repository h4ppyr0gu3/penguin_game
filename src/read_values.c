#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "read_values.h"
#include "read_params.h"
#include "help.h"

int read_values(ReadParams *read_params) {
	int c;
	read_params->value_count = 0;
	read_params->read_array = malloc(4 * sizeof(int)); 
	int *value;
	char buffer[256];
	value = malloc(4 * sizeof(int));
	int index = 0;
	printf("reading values: .....");
	fflush(stdin);
	fgets(buffer, 50, stdin);
	printf("%s", buffer);

	// while ((c = getc(buffer)) > 10) {
 //    if(c == 45) {
 //    	read_params->read_array[read_params->value_count] = concatenate_array(value);
 //    	value = (int*)realloc(value, 4 * sizeof(int));
 //    	read_params->value_count++;
 //    	index = 0;
 //    } else if (c == 104) {
 //    	help_me();
 //    	printf("\n");
 //    	return 1;
 //    } else {
 //    	value[index] = c - 48;
	// 		index++;
 //    }
	// }
	return 0;
}

int concatenate_array(int* array) {
	int elements;
	float sum = 0;
	for(int i = 0; array[i]; ++i)
		elements = i + 1;
	for(int i = 0; elements > i; i++) 
		sum += pow(10, elements - 1 - i) * array[i];
	return ceil(sum);
}