#include "TXLib.h"
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


int main()
{
txCreateWindow (1000, 700);
txTextCursor (false);


Forma form1 = {"1.Столица России",txLoadImage ("Pictures/Амстердам.bmp"),"Амстердам",txLoadImage ("Pictures/Челябинск.bmp"),"Челябинск", txLoadImage ("Pictures/Москва.bmp"),"Москва"};
Forma form2 = {"2.Столица Нидерландов",txLoadImage ("Pictures/Амстердам.bmp"),"Амстердам",txLoadImage ("Pictures/Челябинск.bmp"),"Челябинск",txLoadImage ("Pictures/Москва.bmp"),"Москва"};
Forma form3 = {"3.",txLoadImage ("Pictures/Амстердам.bmp"),"Амстердам",txLoadImage ("Pictures/Челябинск.bmp"),"Челябинск",txLoadImage ("Pictures/Москва.bmp"),"Москва"};

int count_question = 3;
int num_question = 1;
    while (num_question <= count_question)
    {
     txSetFillColor(TX_BLACK);
     txClear();
     txBegin();
     drawMaket();
     txSetColor (TX_WHITE);
     txSelectFont ("Comic Sans", 60);
     txSetTextAlign (TA_CENTER);

     if (num_question == 1)
     {
       form1.draw();
     }
     else if (num_question == 2)
     {
       form2.draw();
     }
     else if (num_question == 3)
     {
       form3.draw();
     }


















     if(txMouseButtons() == 1 &&
      txMouseX()>30 && txMouseX()<310 && txMouseY()>250 && txMouseY()<550 )
     {
       while (txMouseButtons() == 1) txSleep(20);
       num_question ++;
     }

     if(txMouseButtons() == 1 &&
      txMouseX()>350 && txMouseX()<620 && txMouseY()>250 && txMouseY()<550 )
     {
      while (txMouseButtons() == 1) txSleep(20);
      num_question ++;
     }

     if(txMouseButtons() == 1 &&
      txMouseX()>650 && txMouseX()<940 && txMouseY()>250 && txMouseY()<550 )
     {
      while (txMouseButtons() == 1) txSleep(20);
      num_question ++;
     }



    txEnd();
    txSleep(20);

    }

return 0;
}

