CC=g++
CFLAGS=-std=c++17 -Iinclude
DEBUGFLAGS=-g -O0
OPTFLAGS=-O2

# Source and object files
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:src/%.cpp=build/%.o)
DEBUG_TARGET=bin/project_debug
RELEASE_TARGET=bin/project_release

.PHONY: all clean debug release prepare

all: prepare debug release

debug: $(DEBUG_TARGET)

release: $(RELEASE_TARGET)

$(DEBUG_TARGET): $(OBJECTS)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) $^ -o $@

$(RELEASE_TARGET): $(OBJECTS)
	$(CC) $(OPTFLAGS) $(CFLAGS) $^ -o $@

# Compile source files into object files
build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Prepare the necessary directories using Windows CMD syntax
prepare:
	if not exist "build" mkdir build
	if not exist "bin" mkdir bin

clean:
	if exist "build" rmdir /s /q build
	if exist "bin" rmdir /s /q bin
