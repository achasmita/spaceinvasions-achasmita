

class Characters {
private:
	int r,c;
	int drow,dcol;
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

	void setdefaultRow(int dRow) {
      drow = dRow;
    }
    
    int getdefaultRow() {
      return drow;
    }

	void setdefaultColumn(int dCol) {
      dcol = dCol;
    }
    
    int getdefaultColumn() {
      return dcol;
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
  private:
  	int live;
  
  public:
  void setLive(int Live) {
      live = Live;
    }
    
    int getLive() {
      return live;
    }

  
	
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

