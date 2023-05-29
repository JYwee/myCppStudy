#include "ConsoleScreen.h"
#include <iostream>
#include "int4.h"


ConsoleScreen::ConsoleScreen() {

}

ConsoleScreen::~ConsoleScreen() {

}

void ConsoleScreen::Init(char _BaseCh)
{
    BaseCh = _BaseCh;
    Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch) {
    
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    
}

void ConsoleScreen::Clear() {
    
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    
}


bool ConsoleScreen::IsScreenOut(const int4& _Pos) const {
    
        if (0 > _Pos.X)
        {
            return true;
        }

        if (0 > _Pos.Y)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
    
}

void ConsoleScreen::Print() const {
    
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    
        printf_s("\n\n\n\n\n\n\n\n");
        printf_s("esc : 종료  w,a,s,d : 이동  space : 총알 발사 \n");
        printf_s("버전 1  왼쪽으로만 총알 발사 가능. 모든 벽 파괴시 종료\n");
}