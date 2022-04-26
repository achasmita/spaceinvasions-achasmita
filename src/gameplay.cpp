#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include "space.h"
#include "menu.h"
#include "gameplay.h"


using namespace std;
#define MAX_BOMBS 1000

void gamePlay(int level, int score)
{
    clear();
    unsigned int nshots = 8;
    srand(time(NULL)); 
    int en_sp_nd = rand() % 5;
    int rnd_count = 0;
    int dir_change = 0;
    player tank;
    enemyShip alienShip;
    int flag_alienship = 0;
    alien aliens[50];
    shoot shot[nshots];
    bomb bomb[MAX_BOMBS];
    barrier barrier[300];
    struct options settings;
    unsigned int input, loops=0, i=0, j=0, currentshots = 0, currenttanks = 3, currentbombs = 0, currentaliens=50, currentalienShip = 4, currentbarrier = 300;
    int random=0, win=-1, lives = 3;
    char tellscore[30];
    char telllives[30];
    char telllevel[30];
   
    initscr();
    clear();
    noecho();
    cbreak();
    nodelay(stdscr,1);
    keypad(stdscr,1);
    
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);	
    init_pair(3, COLOR_BLUE, COLOR_BLACK);	

    /* Set default settings */
    settings.overall = 15000;
    settings.alien = 12;
    settings.shots = 5;
    settings.bombs = 5;
    settings.bombchance = 1;
    settings.alienShip = 10;

    /* Set tank settings */
    tank.setRow(LINES -2);
    tank.setColumn(COLS / 2);
    tank.setCharacter('^');
    tank.setAlive(3);

    alienShip.setRow(5);
    alienShip.setColumn(COLS -20);
    alienShip.setCharacter('v');
    alienShip.setScore(20);
    alienShip.setAlive(1);
    alienShip.setPR(0);
    alienShip.setPC(0);
    alienShip.setDir('l');
    int spaceship_score[4] = {50, 100, 150, 200};
    int enemyship_appear[5] = {25, 35, 45, 10, 30};
    srand (time(NULL));
   
    alienShip.setPR(0);
    alienShip.setPC(0);

    /* Set aliens settings */
    for (i=0; i<10; ++i) {
        aliens[i].setRow(7);
        aliens[i].setColumn(i*3+20);
        aliens[i].setPR(0);
        aliens[i].setPC(0);
        aliens[i].setCharacter('A');
        aliens[i].setAlive(1);
        aliens[i].setDir('r');
        aliens[i].setScore(15);
    }
    for (i=10; i<20; ++i) {
        aliens[i].setRow(8);
        aliens[i].setColumn((i-10)*3 + 20);
        aliens[i].setPR(0);
        aliens[i].setPC(0);
        aliens[i].setCharacter('B');
        aliens[i].setAlive(1);
        aliens[i].setDir('r');
        aliens[i].setScore(10);
    }
    for (i=20; i<30; ++i) {
        aliens[i].setRow(9);
        aliens[i].setColumn((i-20)*3 + 20);
        aliens[i].setPR(0);
        aliens[i].setPC(0);
        aliens[i].setCharacter('B');
        aliens[i].setAlive(1);
        aliens[i].setDir('r');
        aliens[i].setScore(10);
    }
    for (i=30; i<40; ++i) {
        aliens[i].setRow(10);
        aliens[i].setColumn((i-30)*3 + 20);
        aliens[i].setPR(0);
        aliens[i].setPC(0);
        aliens[i].setCharacter('C');
        aliens[i].setAlive(1);
        aliens[i].setDir('r');
        aliens[i].setScore(5);
    }
    for (i=40; i<50; ++i) {
        aliens[i].setRow(11);
        aliens[i].setColumn((i-40)*3 + 20);
        aliens[i].setPR(0);
        aliens[i].setPC(0);
        aliens[i].setCharacter('C');
        aliens[i].setAlive(1);
        aliens[i].setDir('r');
        aliens[i].setScore(5);
    }

    unsigned int count = 0;
    int l = 20;
    for(int m =0; m <35; m++)
    {
        for(int j = 6; j > 3; j-- )
        {
            for(int k =1; k < 6; k++ )
            {
                barrier[count].setPR(0);
                barrier[count].setPC(0);
                barrier[count].setRow(LINES -j);
                barrier[count].setColumn(k+l);
                barrier[count].setCharacter(61);
                barrier[count].setAlive(1);
                count++;
            }
        
        }
        if(l<COLS - 25)
        {
            l = l + 15;
        }
        else
        {
            break;
        }
    }
      
    /* Set shot settings */
    for (i=0; i<nshots; ++i) {
        shot[i].setActive(0);
        shot[i].setCharacter('*');
    }
    

    /* Set bomb settings */
    for (i=0; i<MAX_BOMBS; ++i) {
        bomb[i].setActive(0);
        bomb[i].setCharacter('+');
        bomb[i].setLoop(0);
        bomb[i].setPR(0);
        bomb[i].setPC(0);
    }
   
    /* Display game title,score header,options */
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

    int col = 20;
    while (col < COLS-20)
    {
        move(LINES-1, col);
        addstr("-");
        col++;
    }  
   
    while(1) 
    {
        /* Show score */
        sprintf(tellscore, "%d", score);
        move(1,9);
        addstr(tellscore);
        
        sprintf(telllives, "%d", lives);
        move(1,22);
        addstr(telllives);

        sprintf(telllevel, "%d", level);
        move(1,37);
        addstr(telllevel);

        /* Move tank */
        move(tank.getRow(),tank.getColumn());
        addch(tank.getCharacter());
        
        /* Move bombs */ 
        if (loops % settings.bombs == 0)
        for (i=0; i<MAX_BOMBS; ++i) 
        {
            if (bomb[i].getActive() == 1) 
            {
                if (bomb[i].getRow() < LINES-1) 
                {
                    if (bomb[i].getLoop() != 0) 
                    {
                        move(bomb[i].getRow()-1,bomb[i].getColumn());
                        addch(' ');
                    }

                    if (tank.getAlive()  > 1 && tank.getRow() == bomb[i].getRow() && tank.getColumn() == bomb[i].getColumn()) 
                    {
                        bomb[i].setActive(0);
                        --currentbombs;
                        --currenttanks;
                        --lives;
                        tank.setAlive(tank.getAlive() - 1);
                        break;
                    }
                    if (tank.getAlive()  == 1 && tank.getRow() == bomb[i].getRow() && tank.getColumn() == bomb[i].getColumn()) 
                    {
                        win = 0;
                        break;
                    }

                    for(j = 0; j<count; j++)
                    if (barrier[j].getAlive() == 1 && barrier[j].getRow() == bomb[i].getRow() && barrier[j].getColumn() == bomb[i].getColumn()) 
                    {
                        bomb[i].setActive(0);
                        barrier[j].setAlive(0);
                        --currentbombs;
                        --currentbarrier;

                     break;
                    }
                    else
                    {
                        bomb[i].setLoop(bomb[i].getLoop() + 1);
                    }
                    move(bomb[i].getRow(),bomb[i].getColumn());
                    addch(bomb[i].getCharacter());
                
                    bomb[i].setRow(bomb[i].getRow() + 1);
                    
                }
                else 
                {
                    bomb[i].setActive(0);
                    bomb[i].setLoop(0);
                    --currentbombs;
                    move(bomb[i].getRow() - 1,bomb[i].getColumn());
                    addch(' ');
                }
            }
        }
      
        /* Move shots */
        if (loops % settings.shots == 0)
        for (i=0; i<nshots; ++i) 
        {
            if (shot[i].getActive() == 1) 
            {
                if (shot[i].getRow() > 2) 
                {
                    if (shot[i].getRow() < LINES - 2) 
                    {
                        move(shot[i].getRow() + 1,shot[i].getColumn());
                        addch(' ');
                    }
               
                    for (j=0; j<50; ++j) 
                    {
                        if (aliens[j].getAlive() == 1 && aliens[j].getRow() == shot[i].getRow() && aliens[j].getPC() == shot[i].getColumn()) {
                            score += aliens[j].getScore();
                            aliens[j].setAlive(0);
                            shot[i].setActive(0);
                            --currentshots;
                            --currentaliens;
                            move(aliens[j].getPR(),aliens[j].getPC());
                            addch(' ');
                            break;
                        }
                    }
               
                    if (alienShip.getAlive() == 1 && alienShip.getRow() == shot[i].getRow() && alienShip.getColumn() == shot[i].getColumn()) 
                    {
                        alienShip.setAlive(0);
                        shot[i].setActive(0);
                        --currentshots;
                        --currentalienShip;
                        int sp =  rand() % 4;
                        score += spaceship_score[sp];
                        break;
                    }
                            
                    for (j=0; j<count; ++j) 
                    {
                        if (barrier[j].getAlive() == 1 && barrier[j].getRow() == shot[i].getRow() && barrier[j].getColumn() == shot[i].getColumn()) 
                        {
                            barrier[j].setAlive(0);
                            shot[i].setActive(0);
                            --currentshots;
                            --currentbarrier;
                            addch(' ');
                            break;
                        }
                    }

                    if (shot[i].getActive() == 1) {
                        move(shot[i].getRow(),shot[i].getColumn());
                        addch(shot[i].getCharacter());
                        
                        shot[i].setRow(shot[i].getRow() - 1);
                    }
                }
                else 
                {
                    shot[i].setActive(0);
                    --currentshots;
                    move(shot[i].getRow() + 1,shot[i].getColumn());
                    addch(' ');
                }
            }
        }     
      
        /* Move aliens */
        if (loops % settings.alien == 0)
        {
            for (i=0; i<50; ++i) 
            {
                if (aliens[i].getAlive() == 1) 
                {
                    move(aliens[i].getPR() ,aliens[i].getPC());
                    addch(' ');
                    
                    move(aliens[i].getRow(),aliens[i].getColumn());
                    addch(aliens[i].getCharacter());
                    
                    aliens[i].setPR(aliens[i].getRow());
                    aliens[i].setPC(aliens[i].getColumn());
                    
                    /* Check if alien should drop bomb */
                    random = 1+ (rand()%100);
                    if ((settings.bombchance - random) >= 0 && currentbombs < MAX_BOMBS) 
                    {
                        for (j=0; j<MAX_BOMBS; ++j) 
                        {
                            if (bomb[j].getActive() == 0) 
                            {
                                bomb[j].setActive(1);
                                ++currentbombs;
                                bomb[j].setRow(aliens[i].getRow() + 1);
                                bomb[j].setColumn(aliens[i].getColumn());
                                rnd_count ++;
                                break;
                            }
                        }
                    }
            
                    /* Set alien's next position */
                    if (aliens[i].getDir() == 'l')
                    aliens[i].setColumn(aliens[i].getColumn() - 1);
                   
                    else if (aliens[i].getDir() == 'r')
                    aliens[i].setColumn(aliens[i].getColumn() + 1);
                    
                    /* Check alien's next positions */
                    if (aliens[i].getColumn() == COLS - 20) 
                    {
                        for (int u = 0; u<10; u++)
                            aliens[u].setColumn(aliens[u].getColumn() - 1);

                        for (int l = 0; l<50; l++ )
                        {
                            if (aliens[l].getAlive() == 1) {
                            move(aliens[l].getRow(),aliens[l].getColumn());
                            addch(' ');
                            // aliens[l].setColumn(aliens[l].getColumn() - 1);
                            aliens[l].setRow(aliens[l].getRow() + 1);
                            move(aliens[l].getRow(),aliens[l].getColumn());
                            addch(aliens[l].getCharacter());
                            aliens[l].setDir('l');}
                        }
                        break;
                    }
                    else if (aliens[i].getColumn() == 20) 
                    {
                        aliens[i].setColumn(aliens[i].getColumn() + 1);
                       for (int l = 0; l<50; l++ )
                        {
                            if (aliens[l].getAlive() == 1) {
                            move(aliens[l].getRow(),aliens[l].getColumn());
                            addch(' ');
                            // aliens[l].setColumn(aliens[l].getColumn() - 1);
                            aliens[l].setRow(aliens[l].getRow() + 1);
                            move(aliens[l].getRow(),aliens[l].getColumn());
                            addch(aliens[l].getCharacter());
                            aliens[l].setDir('r');}
                        }
                        break;
                    }
                }
            }
        }


        /* Move alienship */
        if (rnd_count > enemyship_appear[en_sp_nd])
            flag_alienship = 1;
        if (loops % settings.alienShip ==0)
            if (alienShip.getAlive() == 1 && flag_alienship ==1 && dir_change < 2) 
            {
                alienShip.setPR(alienShip.getRow());
                alienShip.setPC(alienShip.getColumn());

                move(alienShip.getPR(), alienShip.getPC());
                addch(' ');
                
                /* Set alien's next position */
                if (alienShip.getDir() == 'l')
                alienShip.setColumn(alienShip.getColumn() - 1);
               
                else if (alienShip.getDir() == 'r')
                alienShip.setColumn(alienShip.getColumn() + 1);

                move(alienShip.getRow(), alienShip.getColumn());
                addch(alienShip.getCharacter());

                /* Check alien's next positions */
                if (alienShip.getColumn() == COLS - 20) 
                {
                    alienShip.setRow(alienShip.getRow());
                    alienShip.setDir('l');
                    move(alienShip.getRow(), alienShip.getColumn());
                    addch(' ');
                    dir_change ++;
                
                }
                else if (alienShip.getColumn() == 20) 
                {
                    alienShip.setRow(alienShip.getRow());
                    alienShip.setDir('r');
                    move(alienShip.getRow(), alienShip.getColumn());
                    addch(' ');
                    dir_change ++;
                }    
            }
      
      
        for (i=0; i<count; ++i)
        {
            if(barrier[i].getAlive() == 1)
            {
                move(barrier[i].getRow(), barrier[i].getColumn());
                addch(barrier[i].getCharacter());
            }
            else
            {
                move(barrier[i].getRow(), barrier[i].getColumn());
                addch(' ');
            }
        }

        if ( alienShip.getAlive() == 0)
        {
            move(alienShip.getRow(), alienShip.getColumn());
            addch(' ');
        }
      
        /* See if game has been won or lost*/
        if (currentaliens == 0) {
            level++;
            gamePlay(level, score);    
        }
        for (i=0; i<50; ++i) 
        {
            if (aliens[i].getRow() == LINES-4) 
            {
                win = 0;
                break;
            }
        }
      
        move(0,COLS-1);
        refresh();
        usleep(settings.overall);
        ++loops;
      
        input = getch();
        move(tank.getRow(),tank.getColumn());
        addch(' ');
      
        /* Check input */
        if (input == 'q')
        {
            win = 0;
            break;
        }
        else if (input == KEY_LEFT)
            tank.setColumn(tank.getColumn() -1);
        else if (input == KEY_RIGHT)
            tank.setColumn(tank.getColumn() +1);
        else if (input == ' ' && currentshots < nshots) 
        {
            for (i=0; i<nshots; ++i) 
            {
                if (shot[i].getActive() == 0) 
                {
                    shot[i].setActive(1);
                    ++currentshots;
                    shot[i].setRow(LINES - 2);
                    shot[i].setColumn(tank.getColumn());
                    break;
                }
            }
        }
        else if (input == 'p')
            pause(&settings); 
        
        if (win != -1)
            break;
      
        /* Check for valid tank position */
        if (tank.getColumn() > COLS-2)
            tank.setColumn(COLS - 2);
        else if (tank.getColumn() < 0)
            tank.setColumn(0);     
    }
   
    gameover(win , score);
    endwin();
}





