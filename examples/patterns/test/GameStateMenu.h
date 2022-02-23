#ifndef GS_MENU
#define GS_MENU
#include "GameState.h"
using namespace std;

class GameStateManager;

class GameStateMenu: public GameState
{
	public : 
			GameStateMenu()
			{
			}

			void Test(int x)
			{
				cout << x << endl;
			}

};




#endif


