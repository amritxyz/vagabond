CC      = cc
CFLAGS  = -Wall -Werror -Wextra -std=c99
LDFLAGS = -lraylib -lX11
SRC     = src/main.c
OBJ     = build/main.o
OUT     = bin/main
all: dirs $(OUT)
dirs:
	mkdir -p build bin
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)
$(OUT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(OUT)
run: all
	./$(OUT)
clean:
	rm -rf build bin
.PHONY: all dirs run clean
