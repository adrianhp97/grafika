CC=g++
CFLAGS=-c -Wall -g -std=c++11
LDFLAGS=-g -lm

SOURCES=$(wildcard ./src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
MAIN=./src/Main.cpp
EXECUTABLE=./bin/main

.PHONY: all bin clean

all: clean bin

bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mkdir bin
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)
	-rmdir bin