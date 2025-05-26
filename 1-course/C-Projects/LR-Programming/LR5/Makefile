CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o cli_handler.o file_manager.o task_list.o task.o
TARGET = task_manager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
