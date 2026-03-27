# Vagabond - 2d shooting game
# See LICENSE file for copyright and license details.

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -std=c99 -Isrc
LDFLAGS = -lraylib -lm

SRC     = src/main.c src/player.c src/monsters.c src/debug.c
OBJ     = build/main.o build/player.o build/monsters.o build/debug.o
OUT     = bin/main
HEADERS = src/config.h src/main.h src/player.h src/monsters.h src/debug.h

SESSION_TYPE := $(shell echo $$XDG_SESSION_TYPE)

ifeq ($(SESSION_TYPE),x11)
	LDFLAGS += -lX11
endif

all: dirs $(OUT)

dirs:
	mkdir -p build bin

build/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf build bin

.PHONY: all dirs run clean
