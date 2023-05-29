// myCppStudy0526.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "int4.h"
#include "ConsoleScreen.h"
#include "Object.h"
#include "Player.h"
#include "Bullet.h"
#include "Wall.h"
#include <Windows.h>

#include "GameManger.h"




//class GameManager;
class Player;

GameManger* GameManger::gm_Inst = nullptr;

// 1. 파일 정리
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.

// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.

// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.



int main()
{
    if (!GameManger::GetInstance()->Init())
    {
        return false;
    }

    
    ConsoleScreen* Screen = GameManger::GetInstance()->getScreen();
    Player* MainPlayer = GameManger::GetInstance()->getPlayer();
    Bullet* Bullet = GameManger::GetInstance()->getBullet();
    
    Wall* MainWall[10];
    
    
    

    Screen->Init('*');

    
    
    for (int i = 0; i < 10; ++i)
    {
        MainWall[i] = GameManger::GetInstance()->getWall(i);
        //GameManger::GetInstance()->getWall(i)->SetPos({ 1, i });
        MainWall[i]->SetPos({ 1, i });
    }

    // 클래스의경우에는 
    MainPlayer->SetPos({ 10, 5 });

    MainPlayer->AddPos({ 1 ,1 });

    while (true)
    {
        if (!GameManger::GetInstance()->getGameState()) {
            return 0;
        }

        Screen->Clear();
        for (int i = 0; i < 10; ++i)
        {
            Screen->SetPixel(MainWall[i]->GetPos(), '0');
        }
        Screen->SetPixel(MainPlayer->GetPos(), 'a');

        
        
        if (Bullet->IsOnFire()) {
            Screen->SetPixel(Bullet->GetPos(), 'B');
            Bullet->OnFire();
        }
        
        Screen->Print();



        //MainPlayer.Input(&Screen);

        if (0 != _kbhit())
        {
            //mGameManager.getScreen()->Input(&Screen);
            MainPlayer->Input(Screen);
            

            // 1000이면 1초입니다.
        }
        // 1초 동안 정지합니다.
        Sleep(200);
    }
}

