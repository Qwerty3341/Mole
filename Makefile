CC = gcc
CFLAGS = $(shell cat compile_flags.txt)
SRC = main.c $(wildcard src/*.c) $(wildcard src/utils/*.c)
TARGET = mole

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)
