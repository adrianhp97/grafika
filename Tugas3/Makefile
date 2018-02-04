CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=-g -lm

SOURCES=$(wildcard ./*.c)
OBJECTS=$(SOURCES:.c=.o)
MAIN=./main.CC
EXECUTABLE=./a

.PHONY: all bin clean

all: bin

bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

%.o: %.CC
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)