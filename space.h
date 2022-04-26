/* Space Invaders */

/* header file for invaders.c */
//#include<cstring>
//using namespace std;

class Characters {
private:
	int r,c;
	int pr,pc;
	int alive; /* 1=alive 0=destroyed */
	char direction; /* 'l'=left 'r'=right */
	char ch;
	int active;
	int loop;
	int score;

public:
	void setRow(int row) {
      r = row;
    }
    
    int getRow() {
      return r;
    }

	void setColumn(int column) {
      c = column;
    }
    
    int getColumn() {
      return c;
    }

	void setPR(int PR) {
      pr = PR;
    }
    
    int getPR() {
      return pr;
    }

	void setPC(int PC) {
      pc = PC;
    }
    
    int getPC() {
      return pc;
    }

	void setAlive(int Alive) {
      alive = Alive;
    }
    
    int getAlive() {
      return alive;
    }

	void setDir(char Dir) {
      direction = Dir;
    }
    
    int getDir() {
      return direction;
    }

	void setCharacter(char Character) {
      ch = Character;
    }
    
    int getCharacter() {
      return ch;
    }

	void setActive(int Active) {
      active = Active;
    }
    
    int getActive() {
      return active;
    }

	void setLoop(int Loop) {
      loop = Loop;
    }
    
    int getLoop() {
      return loop;
    }
	
	void setScore(int Score) {
      score = Score;
    }
    
    int getScore() {
      return score;
    }
};
class alien : public Characters{

};

class player : public Characters{
	
};

class shoot : public Characters{
	
};

class bomb : public Characters{
	
};

class enemyShip : public Characters{
	
};

class barrier : public Characters{
	
};
struct options {
	int overall,alien,shots,bombs,bombchance,alienShip;
};

