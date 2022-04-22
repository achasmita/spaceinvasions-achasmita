#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "menu.h"
//#include "game.h"
//#include "invader.h"
#define MAX_LINE_LENGTH 80

int	mainMenu()
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	cbreak();
	timeout(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);	

	int yMax, xMax;
	int choice;

	getmaxyx(stdscr, yMax, xMax);

	attron(COLOR_PAIR(1));
	mvprintw (yMax-(yMax-1), xMax - 15, "HIGHSCORE:");
	FILE *fp = fopen("HighScore.txt", "r");

	char myText[MAX_LINE_LENGTH] = {0};
	
	int z = 2; 

	while (fgets(myText, MAX_LINE_LENGTH, fp)) 
	{
		mvprintw(yMax - (yMax-z),xMax - 15, "%s\n", myText);
		z++;

	}
	
	fclose(fp);

	mvprintw (yMax-(yMax-7), (xMax-29)/2, "***** *****     *     ***** *****");
	mvprintw (yMax-(yMax-8), (xMax-29)/2, "*     *   *    * *    *     *    ");
	mvprintw (yMax-(yMax-9), (xMax-29)/2, "***** *****   *****   *     *****");
	mvprintw (yMax-(yMax-10), (xMax-29)/2, "    * *      *     *  *     *    ");
	mvprintw (yMax-(yMax-11),(xMax-29)/2, "***** *     *       * ***** *****");

	mvprintw (yMax-(yMax-12), (xMax-41)/2, "***** *   * *       *    *     ***** ***** *****");
	mvprintw (yMax-(yMax-13), (xMax-41)/2, "  *   **  *  *     *    * *    *   * *     *   *");
	mvprintw (yMax-(yMax-14), (xMax-41)/2, "  *   * * *   *   *    *****   *   * ***** *****");
	mvprintw (yMax-(yMax-15), (xMax-41)/2, "  *   *  **    * *    *     *  *   * *     * *  ");
	mvprintw (yMax-(yMax-16), (xMax-41)/2, "***** *   *     *    *       * ***** ***** *   *");

	mvprintw (yMax-6, (xMax-24)/2, "Press \"h\" for game instructions.");
	mvprintw (yMax-4, (xMax-24)/2, "    Press \"q\" to quit game.");
	mvprintw (yMax-2, (xMax-24)/2, " Press \"space\" to start game.");
	attroff(COLOR_PAIR(1));
	refresh();

	while (1)
	{
		if((choice = getch ()) == (int)' ')
		{
			clear();
			//gamePlay();
		}
		if (choice== (int) 'h')
		{
			clear();
	
			noecho();
			curs_set(0);
			cbreak();
			timeout(0);
			keypad(stdscr, TRUE);
			nodelay(stdscr, TRUE);
			
			int help;
			move(1,0);
			attron(COLOR_PAIR(2));
			addstr("--------------------Game Instructions------------------");
			move(3,0);
			addstr("1. Press \"KEY_LEFT\" or \"d\" to move spaceship(^) to left ");
			move(4,0);
			addstr("2. Press \"KEY_RIGHT\" or \"a\" to move spaceship(^) to right");
			move(5,0);
			addstr("3. Press \"SPACE KEY\" to fire missile toward alien(A,B,C) and enemy spaceship(V)");

			move(7,0);
			addstr("--Aliens Point Value--");
			move(8,0);
			addstr(" A  -  15 points");
			move(9,0);
			addstr(" B  -  10 points");
			move(10,0);
			addstr(" C  -  5 points");
			move(11,0);
			addstr(" V  -  50-200 points");
			attroff(COLOR_PAIR(2));
			refresh();
			attron(COLOR_PAIR(1));
			move(14,0);
			addstr("      Press \"m\" to go back to the main menu");
			move(16,0);
			addstr("           Press \"q\" to quit the game");
			move(18,0);
			addstr("      Press \"space key\" to start the game");
			attroff(COLOR_PAIR(1));
			
			while (1)
			{
				if((help=getch ()) == (int)' ')
				{
					clear();
				//	gamePlay();
				}
				if (help== (int) 'm')
				{
					clear();
					mainMenu(); 
				}

				if(help == (int)'q')
				{
					endwin();
					exit(0) ;
				}

			}
		}	
		if (choice == (int) 'q')
		{
			endwin();
			exit(0) ;
		}
		
	}
	clear();	
}




