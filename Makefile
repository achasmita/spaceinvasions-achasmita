GCC=g++
 
  
all: space.cpp
	$(GCC) -g -Wall -o space space.cpp

clean: 
	$(RM) space

