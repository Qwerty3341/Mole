CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = main.c src/meminfo.c src/file_reader.c
TARGET = mole

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
