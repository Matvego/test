#include <iostream>
#include <fstream>
using namespace std;
string getpos(string str,int *pos2)
{
    int pos1 = *pos2 + 1;
    *pos2 = str.find(",", pos1);
    string part = str.substr(pos1, *pos2-pos1);

  return part;
}

int main()
{
    setlocale (LC_ALL,"Russian");
    string str;
    ifstream file("test.txt");
    while(file.good())
    {
    getline(file,str);
    int pos2 = -1;
    string text_question = getpos(str, &pos2);
    string picture_answer1 = getpos(str, &pos2);
    string text_answer1 = getpos(str, &pos2);
    string picture_answer2 = getpos(str, &pos2);
    string text_answer2 = getpos(str, &pos2);
    string picture_answer3 = getpos(str, &pos2);
    string text_answer3 = getpos(str, &pos2);
    string n_right_answer = getpos(str, &pos2);
    }
    return 0;
}
