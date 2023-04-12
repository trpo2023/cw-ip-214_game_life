APP_NAME = game_life
LIB_NAME = game_life_lib

CPPFLAGS = -I src -MP -MMD
CFLAGS = -Wall -Werror
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_OUT_DIR = bin/game_life_test

TARGET_OUT_NAME = game_life
TARGET = main

THIRDPARTY_DIR = thirdparty

TEST_SRC_DIR = test
TEST_OUT_NAME = game_life_test