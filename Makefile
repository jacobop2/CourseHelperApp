EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
