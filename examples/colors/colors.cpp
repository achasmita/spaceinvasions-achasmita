#include <iostream>

using namespace std;

int main()
{
    cout << "\033[31m red text\033[0m" << endl;
    cout << "\033[34m blue text\033[0m" << endl;

    cout << "\033[4;32m underline green text\033[0m" << endl;



    return 0;
}

