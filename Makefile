CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*/*.c)
TARGET = build

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

