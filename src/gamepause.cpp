#include <ncurses.h>
#include <iostream>

#include "space.h"
#include "gameplay.h"
/* This function handles the menu options available to the user */
void pause(struct options *settings) 
{
    char option;
    
    clear();
    echo();
    nocbreak();
    nodelay(stdscr,0);

    move(1,0);
    addstr("1. Return to the game");
    move(2,0);
    addstr("2. Exit the game");
    move(4,0);
    addstr("Enter your option: ");
    refresh();

    while(1) 
    {
        move(4,19);
        option = getch();
        move(5,0);
        deleteln();
        move(6,0);
        deleteln();
        move(7,0);
        deleteln();
            
        if (option == '1') {
            break;
        }
        else if (option == '2') {
            endwin();
            exit(0);
        }
        else {
            move(5,0);
            addstr("ERROR: Invalid selection");
            move(4,19);
            addstr(" ");
            refresh();        
        }
    }

    clear();
    noecho();
    cbreak();
    nodelay(stdscr,1);

    int iter = 0;
    while (iter < COLS)
    {
        move(0, iter);
        addstr(":");
        iter ++;
    }
    iter = 0;
    while (iter < COLS)
    {
        move(2, iter);
        addstr(":");
        iter ++;
    }

    move(1,(COLS/2)-11);
    addstr("----SPACE INVADERS----");
    attron(COLOR_PAIR(2));
    move (1,2);
    addstr("SCORE: ");
    move (1,15);    
    addstr("LIVES: ");
    move(1,30);
    addstr("LEVEL: ");
    move(1,COLS-20);
    addstr("p = pause  q = quit");

}

