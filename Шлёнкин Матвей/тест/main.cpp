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


int main()
{
txCreateWindow (1000, 700);
txTextCursor (false);
HDC amst = txLoadImage ("Pictures/Амстердам.bmp");
HDC mosc = txLoadImage ("Pictures/Москва.bmp");
HDC chelyab = txLoadImage ("Pictures/Челябинск.bmp");
int count_question = 1;
int num_question = 1;
    while (num_question <= count_question)
    {
     txBegin();
     drawMaket();
     txSetColor (TX_WHITE);
     txSelectFont ("Comic Sans", 60);
     txSetTextAlign (TA_CENTER);
     txTextOut (490,80, "1.Столица России");
     txBitBlt(txDC(),30,250,280,300,amst);
     txDrawText(30,560,310,630,"Амстердам");
     txBitBlt(txDC(),350,250,280,300,chelyab);
     txDrawText(350,560,620,630,"Челябинск");
     txBitBlt(txDC(),650,250,280,300,mosc);
     txDrawText(650,560,930,630,"Москва");






















     if(txMouseButtons() == 1 &&
      txMouseX()>30 && txMouseX()<310 && txMouseY()>250 && txMouseY()<550 )
     {
      num_question ++;
     }

     if(txMouseButtons() == 1 &&
      txMouseX()>350 && txMouseX()<620 && txMouseY()>250 && txMouseY()<550 )
     {
      num_question ++;
     }

     if(txMouseButtons() == 1 &&
      txMouseX()>650 && txMouseX()<940 && txMouseY()>250 && txMouseY()<550 )
     {
      num_question ++;
     }



    txEnd();
    txSleep(20);

    }
txDeleteDC(amst);
txDeleteDC(mosc);
txDeleteDC(chelyab);
return 0;
}

