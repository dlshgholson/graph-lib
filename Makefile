CC = g++
CFLAGS = -Wall -ggdb -std=c++20 -iquote include

sources = $(wildcard src/*.cpp)
objects = $(patsubst src/%.cpp,obj/%.o,$(sources))

test_sources = $(wildcard tests/*.cpp)
tests = $(patsubst %.cpp,%,$(test_sources))
corelib = lib/libGraph.a

all: $(corelib) $(tests)

$(corelib): obj lib $(objects)
	ar rcs $(corelib) $(objects)

obj:
	mkdir -p obj

lib:
	mkdir -p lib

$(objects): obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(tests): %: %.cpp
	$(CC) $(CFLAGS) $< -Llib -lGraph -o $@

.PHONY: clean

clean:
	rm -rf obj lib
	rm $(tests)
