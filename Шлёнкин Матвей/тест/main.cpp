//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"
void drawMaket()
{

    txSetColor(TX_WHITE);
    txSetFillColor(TX_TRANSPARENT);
    txRectangle(50,20,925,205);

    txSetFillColor(TX_TRANSPARENT);
    txRectangle(10,10,990,690);

    txRectangle(30,250,310,550);
    txRectangle(350,250,620,550);
    txRectangle(650,250,940,550);

    txRectangle(30,560,310,630);
    txRectangle(350,560,620,630);
    txRectangle(650,560,940,630);

}


int main()
{
txCreateWindow (1000, 700);
txTextCursor (false);
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
    drawMaket();
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans", 60);
    txSetTextAlign (TA_CENTER);
    txTextOut (490,80, "1.������� ������");
    txDrawText(30,560,310,630,"���������");
    txDrawText(350,560,620,630,"���������");
    txDrawText(650,560,930,630,"������");





























    }
txDisableAutoPause();
return 0;
}

