GCC=g++
 
  
all: src/space.cpp src/menu.cpp
	$(GCC) -g -Wall -o space src/space.cpp src/menu.cpp src/gameplay.cpp src/gamepause.cpp src/gameover.cpp -lncurses

clean: 
	$(RM) space space.o menu.o