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

/* Tme main function handles mainmenu and overall game play */
int main() {
    int level = 0;
    int score = 0;
    mainMenu();
    gamePlay(level, score);
   	
   return 0;
}