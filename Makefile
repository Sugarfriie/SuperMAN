CC=gcc
CFLAGS=-W -Wall -g -std=c99
LDFLAGS=-lgsl -lgslcblas -lm
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXEC=SuperMAN

all: $(EXEC)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
