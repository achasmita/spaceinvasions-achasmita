GCC=g++
 
  
all: space.cpp menu.cpp
	$(GCC) -g -Wall -o space space.cpp menu.cpp -lncurses

clean: 
	$(RM) space space.o menu.o
