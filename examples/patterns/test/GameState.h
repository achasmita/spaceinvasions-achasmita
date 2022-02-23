
#ifndef GS_STATE
#define GS_STATE

#include "GameStateManager.h"

using namespace std;

class GameStateManager;

class GameState
{
	public:
		GameState()
			{
			}
	protected:
		GameStateManager *gsManager;
};


#endif


