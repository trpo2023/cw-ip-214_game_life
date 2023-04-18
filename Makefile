APP_NAME = game_life_main
LIB_NAME = game_life_lib

CPPFLAGS = -I src -MP -MMD
CC = g++
CFLAGS =

BIN_ = bin
BIN_DIR = bin/game_life_main
OBJ_DIR = obj
SRC_DIR = src

TARGET_OUT_NAME = game_life
TARGET = main

THIRDPARTY_DIR = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(BIN_DIR)/lib.a
LIB_OBJ_DIR = obj/src/game_life_lib
LIB_HEADERS_DIR = $(SRC_DIR)/game_life_lib

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

.PHONY: all

all: format $(APP_PATH) clean  

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean

clean:
	$(RM) $(LIB_PATH) 
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

format:
	clang-format -i $(SRCS) $(HDRS)