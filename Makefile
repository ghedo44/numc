CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -Iinclude

SRC     = main.c src/numc.c
OBJ     = $(SRC:.c=.o)
BIN     = main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

# pattern rule for .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

