CC = g++
CFLAGS = -Wall -std=c++20 -iquote include

sources = $(wildcard src/*.cpp)
objects = $(patsubst src/%.cpp,obj/%.o,$(sources))

test_sources = $(wildcard tests/*.cpp)
tests = $(patsubst %.cpp,%,$(test_sources))
tests_o = $(patsubst %.cpp,%.o,$(test_sources))
lib = lib/libGraph.a

all: $(lib) $(tests)

$(lib): obj lib $(objects)
	ar rcs $(lib) $(objects)

obj:
	mkdir -p obj

lib:
	mkdir -p lib

$(objects): obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#$(tests): $(tests_o)
	#$(CC) $(CFLAGS) -Llib -lGraph -ggdb $< -o $@

$(tests): $(tests_o)
	$(CC) $(CFLAGS) -Llib -lGraph -ggdb $< -o $@

$(tests_o): tests/%.o: tests/%.cpp
	$(CC) $(CFLAGS) -ggdb -c $< -o $@

.PHONY: clean

clean:
	rm -rf obj lib
