CC = g++
CFLAGS = -I src/ -I thirdparty/
LIFE_SRC = src/game_life_main/
LIBLIFE_SRC = src/game_life_lib/

LIFE_OBJ = obj/src/game_life_main/
LIBLIFE_OBJ = obj/src/game_life_lib/

BIN = bin/

SRC = src/

TEST = test/

TEST_OBJ = obj/test/

THIRDPARTY = thirdparty/

SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

.PHONY: main

$(BIN)game_life_main/main.out: $(LIFE_OBJ)main.o $(LIBLIFE_OBJ)liblife.a
	$(CC) $(CFLAGS) -o $@ $^
$(LIFE_OBJ)main.o: $(LIFE_SRC)main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)liblife.a: $(LIBLIFE_OBJ)display.o $(LIBLIFE_OBJ)count_life.o $(LIBLIFE_OBJ)copygrid.o $(LIBLIFE_OBJ)liveordie.o 
	ar rcs $@ $^
$(LIBLIFE_OBJ)display.o: $(LIBLIFE_SRC)display.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)copygrid.o: $(LIBLIFE_SRC)copygrid.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)liveordie.o: $(LIBLIFE_SRC)liveordie.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)count_life.o: $(LIBLIFE_SRC)count_life.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(LIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.a
	rm -rf $(BIN)*.out

.PHONY: format

format:
	clang-format -i $(SRCS) $(HDRS)