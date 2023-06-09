// TestStudyApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "ConsoleScreen.h"

GameManager* GameManager::mInstance = nullptr;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    srand((unsigned int)time(NULL));

    if (!GameManager::GetInstance()->Init())
    {
       
        return false;
    }

    while (GameManager::GetInstance()->GetGameState())
    {
        GameManager::GetInstance()->Run();


        if (0 != _kbhit())
        {
            
            GameManager::GetInstance()->Input();


            // 1000이면 1초입니다.
        }
        // 1초 동안 정지합니다.
        Sleep(100);
    
    
    }

    GameManager::GetInstance()->getConsoleScreen().GetInstance()->DestoryInstance();
    GameManager::GetInstance()->DestoryInstance();

    return 0;
}

