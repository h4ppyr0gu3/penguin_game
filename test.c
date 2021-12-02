#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int concatenate_array(int* array);

int main(int argc, char *argv[]) {

	int c, numbers_read = 0;
	int *read_values;
	read_values = malloc(4 * sizeof(int)); 
	int *value;
	value = malloc(4 * sizeof(int));
	int index = 0;
	while ((c = fgetc(stdin)) > 10) {
    if(c == 45) {
    	read_values[numbers_read] = concatenate_array(value);
    	value = (int*)realloc(value, 4 * sizeof(int));
    	numbers_read++;
    	index = 0;
    } else if (c == 104) {
    	printf("heres some help");
    	printf("\n");
    	return 1;
    } else {
    	value[index] = c - 48;
			index++;
    }
	}

	for (int i = 0; i < numbers_read; ++i) {
		printf("\n%d   \"\n",read_values[i]);
	}

}

int concatenate_array(int* array) {
	int elements;
	float sum = 0;
	for(int i = 0; array[i]; ++i) {
		elements = i + 1;
	}
	for(int i = 0; elements > i; i++) {
		sum += pow(10, elements - 1 - i) * array[i];
	}
	return ceil(sum);
}