CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

OBJ_DIR = build/
SRC_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/

TARGET = $(BIN_DIR)taskmgr_make

SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(OBJ_FILES) $(TARGET)

