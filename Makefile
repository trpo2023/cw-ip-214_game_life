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

.PHONY: main

$(BIN)game_life_main/main.out: $(LIFE_OBJ)main.o $(LIBLIFE_OBJ)liblife.a
	$(CC) $(CFLAGS) -o $@ $^
$(LIFE_OBJ)main.o: $(LIFE_SRC)main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBLIFE_OBJ)liblife.a: 
	ar rcs $@ $^

.PHONY: clean

clean:
	rm -rf $(LIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.o
	rm -rf $(LIBLIFE_OBJ)*.a
	rm -rf $(BIN)*.out

.PHONY: format

format:
	git ls-files *.{cpp,h} | xargs clang-format -i