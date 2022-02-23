#include <string>

using namespace std;

class Level
{
	/* 
	 * Name of the level 
	 */
	string m_name;

  	public:
		Level(string name)
		{
			m_name = name;
		}

		string GetName()
		{
			return m_name;
		}

};

