// myCppStudy0526.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

#include "ConsoleScreen.h"
#include "Object.h"
#include "Player.h"
#include "Wall.h"
#include <Windows.h>

//class Player;

// 1. 파일 정리
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.




int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Object obj;
    Player MainPlayer;
    Wall MainWall[4];

    for (int i = 0; i < 4; ++i)
    {

        MainWall[i].SetPos({ 1, i });
    }

    // 클래스의경우에는 
    MainPlayer.SetPos({ 10, 5 });

    MainPlayer.AddPos({ 1 ,1 });

    while (true)
    {
        Screen.Clear();
        for (int i = 0; i < 4; ++i)
        {
            Screen.SetPixel(MainWall[i].GetPos(), '0');
        }
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.Print();


        MainPlayer.Input(&Screen);
    }


}
