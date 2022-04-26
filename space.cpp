#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <cstring>
#include "space.h"
#include "menu.h"
#include "gameplay.h"

using namespace std;
#define MAX_BOMBS 1000

/* The main function handles user input, the game visuals, and checks for win/loss conditions */
int main() {
    int level = 0;
    int score = 0;
    mainMenu();
    gamePlay(level, score);
   	
   return 0;
}