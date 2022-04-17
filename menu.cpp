#include "menu.h"
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <fstream>
#define MAX_LINE_LENGTH 80


void mainMenu()
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	cbreak();
	timeout(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);	
	init_pair(10, COLOR_CYAN, COLOR_BLACK);

	int yMax, xMax;

	getmaxyx(stdscr, yMax, xMax);

	attron(COLOR_PAIR(5));
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

	mvprintw (yMax-5, (xMax-24)/2, "Press \"h\" for game instructions.");
	mvprintw (yMax-4, (xMax-24)/2, "Press \"q\" to quit game.");
	mvprintw (yMax-2, (xMax-24)/2, "Press \"space\" to start game.");
	
	refresh();
	clear();
}
