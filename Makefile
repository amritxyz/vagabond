# Vagabond - 2d shooting game
# See LICENSE file for copyright and license details.

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -std=c99
LDFLAGS = -lraylib -lX11
SRC     = src/main.c
OBJ     = build/main.o
OUT     = bin/main
DEPS    = src/main.c src/config.h src/main.h
all: dirs $(OUT)
dirs:
	mkdir -p build bin
$(OBJ): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)
$(OUT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(OUT)
run: all
	./$(OUT)
clean:
	rm -rf build bin
.PHONY: all dirs run clean
