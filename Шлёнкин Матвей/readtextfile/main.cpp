#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    string str;
    ifstream file("test.txt");
    while(file.good())
    {
    getline(file,str);
    cout <<str<< endl;
    }


    return 0;
}
