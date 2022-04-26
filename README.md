# spaceInvaders-template
This repository contains the implementation for Space Invaders.  Computer Science 322 WSU-TC Semester project.

## Instructions to start the game

1.  Clone the repository

    ```console
    user@user> git clone https://github.com/WSU-Cpts322/spaceinvasions-achasmita
    user@user> cd spaceinvasions-achasmita
    ```

1.  Creat an executable file using make and run

    ```` console
    user@user/spaceinvasions-achasmita$ make
    
    # This will create an executable file called space. 
    # Next, invoke the following command to run the game

    user@user/spaceinvasions-achasmita$ ./space

    ````

## Features of the Space Invaders

1. First, users will see the Main Menu screen when the game is started. It shows the highscores and instructions. Please read the instructions carefully to understand the Game Play screen.
2. The Game Play screen displays the level, real-time score, and the number of lives remaining. Additionally, it also gives instructions to pause and quit the game.
3. The aliens move left, right, and descend everytime they hit the limit as decided within the application. They can kill spaceship and destroy barrier with their bomb. On the other hand, they get destroyed when striked with a shot from spaceship. An enemy ship also appears randomly from the top right corner, and the user can score a random score in the range of 50-250 when able to hit the enemy spaceship.
4. The previous high scores (stored in HighScore.csv) are recorded before starting the application and the database is updated when the user's score is higher than the least score in the database.
5. The application also emulates the earth envasion when aliens gradually descend and finally reach the bottom of the screen.
