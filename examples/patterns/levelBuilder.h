#include <string>
#include "level.h"

using namespace std;

enum LevelType
{
	Easy = 1,
	Hard = 2,
	Extreme = 3
};

class LevelFactory
{
  	public:
		Level* Create(LevelType type)
		{
			
			Level * level = 0;

			switch(type)
			{
				case Easy:
					level = new Level("Easy - Something Else");
					break;
				case Hard:
					level = new Level("Hard");
					break;
				case Extreme:
					level = new Level("Extreme");
					break;
			
			}

			return level;
		}
};



