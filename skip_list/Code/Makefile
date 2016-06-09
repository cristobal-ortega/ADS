CC = g++
CFLAGS = -std=gnu++11

TARGETS = main

all: $(TARGETS)

main: main.c skipList.hpp skipList.cpp
	$(CC) $(CFLAGS) main.c skipList.hpp skipList.cpp  -o $@

clean:
	$(RM) $(TARGETS)
