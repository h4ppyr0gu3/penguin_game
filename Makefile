test: test.c
	gcc -c test.c 
	gcc -o test test.o -lm
movement: skip_to_movement.c
	gcc -c skip_to_movement.c 
	gcc -o movement skip_to_movement.o -lm