CC = g++
CFLAGS = -Wall -Wextra -Werror -I src/ -I thirdparty/
LIFE_SRC = src/game_life_main/
LIBLIFE_SRC = src/game_life_lib/

LIFE_OBJ = obj/src/game_life_main/
LIBLIFE_OBJ = obj/src/game_life_lib/

BIN = bin/

TEST_BIN = bin/game_life_test/

SRC = src/

TEST = test/

TEST_OBJ = obj/game_life_test/

THIRDPARTY = thirdparty/

SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

.PHONY: main

$(BIN)game_life_main/main.out: $(LIFE_OBJ)main.o $(LIBLIFE_OBJ)liblife.a
	$(CC) $(CFLAGS) -o $@ $^
$(LIFE_OBJ)main.o: $(LIFE_SRC)main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)liblife.a: $(LIBLIFE_OBJ)display.o $(LIBLIFE_OBJ)randominput.o $(LIBLIFE_OBJ)fileinput.o $(LIBLIFE_OBJ)countlife.o $(LIBLIFE_OBJ)copygrid.o $(LIBLIFE_OBJ)liveordie.o 
	ar rcs $@ $^
$(LIBLIFE_OBJ)display.o: $(LIBLIFE_SRC)display.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)copygrid.o: $(LIBLIFE_SRC)copygrid.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)liveordie.o: $(LIBLIFE_SRC)liveordie.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)countlife.o: $(LIBLIFE_SRC)countlife.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)randominput.o: $(LIBLIFE_SRC)randominput.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)fileinput.o: $(LIBLIFE_SRC)fileinput.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: test

test: $(BIN)game_life_test/test
	./$<

$(BIN)game_life_test/test: $(TEST_OBJ)ctest.o $(TEST_OBJ)main.o $(TEST_OBJ)testliblife.a 
	$(CC) $(CFLAGS) -o $@ $^
$(TEST_OBJ)ctest.o: $(TEST)ctest.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)main.o: $(TEST)main.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)testliblife.a: $(TEST_OBJ)randominput.o $(TEST_OBJ)fileinput.o $(TEST_OBJ)copygrid.o $(TEST_OBJ)countlife.o $(TEST_OBJ)liveordie.o
	ar rcs $@ $^
$(TEST_OBJ)randominput.o: $(LIBLIFE_SRC)randominput.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)fileinput.o: $(LIBLIFE_SRC)fileinput.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)copygrid.o: $(LIBLIFE_SRC)copygrid.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)countlife.o: $(LIBLIFE_SRC)countlife.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)liveordie.o: $(LIBLIFE_SRC)liveordie.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(LIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.a
	rm -rf $(TEST_OBJ)*.o
	rm -rf $(TEST_OBJ)*.a
	rm -rf $(BIN)*.out

.PHONY: format

format:
	clang-format -i $(SRCS) $(HDRS)