CC=g++
CFLAGS=-c -Wall -g -std=c++11
LDFLAGS=-g -lm -lpthread

SOURCES=$(wildcard ./src/*.cpp) $(wildcard ./src/**/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
MAIN=./src/Main.cpp
EXECUTABLE=./bin/main

.PHONY: all bin clean

all: bin

bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mkdir -p bin
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)