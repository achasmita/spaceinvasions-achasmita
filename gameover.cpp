#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

#include "space.h"
#include "menu.h"


using namespace std;
/* This function handles displaying the win/lose screen */
void gameover(int win, int score) 
{
    if (win == 0) 
    {
        clear();
        char name[10];
        noecho();
        curs_set(0);
        cbreak();
        timeout(0);
        keypad(stdscr, TRUE);
        nodelay(stdscr, FALSE);
        int input;

        fstream fin, fout;
        int scores[3];
        string users[3] = {};
        int user_score;
        string word, line, temp;
        fin.open("HighScore.csv", ios::in);
        fout.open("HighScorenew.csv", ios::out);
        vector<string> row;
        int idx = 0;

        while (getline(fin, line))
        {
            vector<string> row;
            stringstream s(line);
        
            while (getline(s, word, ' ')) 
            {
                row.push_back(word);
            }
            user_score = stoi(row[1]);
            scores[idx] = user_score;
            users[idx] = row[0];
            idx++;
        }

        if (score > scores[2])
        {
            clear();
            echo();
            nocbreak();
            nodelay(stdscr,0);
            
            move(1,0);
            addstr("Congratulations!, you have reached high score. ");
            move(3,0);
            addstr("Enter your initial: ");
            refresh();
    
            getnstr(name, sizeof(name)-1);
        
            if (score >= scores[0])
            {
                users[2] = users[1];
                users[1] = users[0];
                users[0] = name;
                scores[2] = scores[1];
                scores[1] = scores[0];
                scores[0] = score;
            }
            if (score< scores[0] && score >= scores[1])
            {
                users[2] = users[1];
                users[1] = name;
                scores[2] = scores[1];
                scores[1] = score;
            }
            if (score<scores[1] && score> scores[2])
            {
                users[2] = name;
                scores[2] = score;
            }
            for (int k = 0; k<3; k++)
            {
                fout << users[k]<< " " << scores[k]<< "\n";
            }
            fout.close();
            remove("HighScore.csv");
            rename("HighScorenew.csv", "HighScore.csv");

            clear();
            mainMenu();
        }
        else
        {
            move((LINES/2),(COLS/2)-11);
            addstr("  PRESS 'q' TO EXIT");
            move((LINES/2)-1,(COLS/2)-5);
            addstr("YOU LOSE!");

            while (1)
            {
                if((input=getch ()) == (int)'q')
                {
                    endwin();
                    exit(0) ;
                }
            
                if (input == (int) 'm')
                {
                    clear();
                    mainMenu(); 
                }
            }

        }                        
        
    }
}
