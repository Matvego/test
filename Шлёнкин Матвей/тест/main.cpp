#include "TXLib.h"
#include <fstream>
using namespace std;
void drawMaket()
{

    txSetColor(TX_WHITE);
    txSetFillColor(TX_TRANSPARENT);
    txRectangle(50,20,925,205);

    txSetFillColor(TX_TRANSPARENT);
    txRectangle(10,10,990,690);

    //txRectangle(30,250,310,550);
    //txRectangle(350,250,620,550);
    //txRectangle(650,250,940,550);

    txRectangle(30,560,310,630);
    txRectangle(350,560,620,630);
    txRectangle(650,560,940,630);

}

struct Forma
{

  string text_question;
  HDC picture_answer1;
  string text_answer1;
  HDC picture_answer2;
  string text_answer2;
  HDC picture_answer3;
  string text_answer3;
  int n_right_answer;

  void draw()
  {
     txTextOut (490,80, text_question.c_str());
     txBitBlt(txDC(),30,250,280,300,picture_answer1);
     txDrawText(30,560,310,630,text_answer1.c_str());
     txBitBlt(txDC(),350,250,280,300,picture_answer2);
     txDrawText(350,560,620,630,text_answer2.c_str());
     txBitBlt(txDC(),650,250,280,300,picture_answer3);
     txDrawText(650,560,930,630,text_answer3.c_str());
  }



};


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
txCreateWindow (1000, 700);
txTextCursor (false);
Forma form_list[15];
int i = 0;

string str;
ifstream file("test.txt");
while(file.good())
{
  getline(file,str);
  int pos2 = -1;
  form_list[i].text_question = getpos(str, &pos2);
  form_list[i].picture_answer1 = txLoadImage(getpos(str, &pos2).c_str());
  form_list[i].text_answer1 = getpos(str, &pos2);
  form_list[i].picture_answer2 = txLoadImage(getpos(str, &pos2).c_str());
  form_list[i].text_answer2 = getpos(str, &pos2);
  form_list[i].picture_answer3 = txLoadImage(getpos(str, &pos2).c_str());
  form_list[i].text_answer3 = getpos(str, &pos2);
  form_list[i].n_right_answer = atoi(getpos(str, &pos2).c_str());
  i++;
}
file.close();


Forma form;

int count_question = i;
int num_question = 1;
int score = 0;
char stroka[30];

    while (num_question <= count_question)
    {
     txSetFillColor(TX_BLACK);
     txClear();
     txBegin();
     drawMaket();
     txSetColor (TX_WHITE);
     txSelectFont ("Comic Sans", 50);
     txSetTextAlign (TA_CENTER);



     form = form_list[num_question-1];
     form.draw();




      if(txMouseButtons() == 1 &&
       txMouseX()>30 && txMouseX()<310 && txMouseY()>250 && txMouseY()<550 )
      {

        if(form.n_right_answer == 1) score++;
        while (txMouseButtons() == 1) txSleep(20);
        num_question ++;
      }

      if(txMouseButtons() == 1 &&
       txMouseX()>350 && txMouseX()<620 && txMouseY()>250 && txMouseY()<550 )
      {
       if(form.n_right_answer == 2) score++;
       while (txMouseButtons() == 1) txSleep(20);
       num_question ++;
      }

       if(txMouseButtons() == 1 &&
       txMouseX()>650 && txMouseX()<940 && txMouseY()>250 && txMouseY()<550 )
      {
       if(form.n_right_answer == 3) score++;
       while (txMouseButtons() == 1) txSleep(20);
       num_question ++;
      }

    txEnd();
    txSleep(20);

    }

txSetFillColor(TX_BLACK);
txClear();
sprintf(stroka,"Вы ответили на %d из %d",score,count_question);
txDrawText(0,0,1000,700,stroka);

return 0;
}

