#include <iostream>
#include <string>


using namespace std;

int main()
{
	
	const string s = "Space Invaders!  ";
	string myStuff;


	while(myStuff.compare("q") != 0)
	{
		cout << s << endl;
		getline(cin, myStuff);
		system("clear");
		cout << myStuff << endl;
	}


	return 0;
}
