# test: test.c
# 	gcc -c test.c 
# 	gcc -o test test.o -lm
# movement: skip_to_movement.c
# 	gcc -c skip_to_movement.c 
# 	gcc -o movement skip_to_movement.o -lm

SRC_DIR := src
OBJ_DIR := src/obj
BIN_DIR := .

EXE := $(BIN_DIR)/penguins
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm    

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR)/penguins $(OBJ_DIR)

-include $(OBJ:.o=.d)

rebuild: clean
	make

test: test.c
	gcc -c test.c 
	gcc -o test test.o -lm
