#include <iostream>
#include <string>
#include "levelBuilder.h"

using namespace std;

int main()
{
	LevelFactory factory;
	Level * level = factory.Create(LevelType::Easy);
	cout << level->GetName() << endl;
	delete level;

	level = factory.Create(LevelType::Extreme);
	cout << level->GetName() << endl;
	delete level;

	level = factory.Create(LevelType::Hard);
	cout << level->GetName() << endl;
	delete level;

	return 0;
}
