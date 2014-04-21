CC=clang++
CFLAGS=-std=c++11 -Wall -o3 -g -Weverything
LIBS=-lGL -lGLU -lglut

BUILD_DIR  := bin
SOURCE_DIR := src

OBJ :=  $(BUILD_DIR)/GLWindow.o $(BUILD_DIR)/imageloader.o\
		$(BUILD_DIR)/lab2.o\
	   	$(BUILD_DIR)/main.o
BIN := main

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

all: $(BIN)
$(BIN): $(OBJ)
	$(CC) -o $(BUILD_DIR)/$(BIN) $(OBJ) $(LIBS)
clean:
	rm -f $(OBJ) $(BIN)
