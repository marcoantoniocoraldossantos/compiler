CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj

# List of source files including main.c
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# List of object files
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

EXECUTABLE = compiler

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)