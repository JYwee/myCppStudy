#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수
#include <stdlib.h>



// 스트링 사이즈 반환
//int GetStrSize(const char* const string)
//{
//    if (!string) {
//        return -1;
//    }
//    int count = 0;
//    while (string[count] != '\0') {
//        ++count;
//    }
//    return count;
//}

void StatusRender(const char* const name, int att, int hp)
{
    if (!name) {
        return;
    }
    char upSideUI[40] = "---------------------------------------";
    const char underUI[40] = "---------------------------------------";

    for (size_t i = 0; name[i] != 0 && i < 40; ++i) 
    {
        upSideUI[i] = name[i];
    }

    printf_s("%s\n", upSideUI);
    printf_s("공격력 : %d\n", att);
    printf_s("체  력 : %d\n", hp);
    printf_s("%s\n", underUI);
}

void DamagePrint(const char* const attName, const char* const defName, int att)
{
    if (!attName || !defName) {
        return;
    }
    printf_s("%s가 %s를 공격했습니다.\n", attName, defName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", defName, att);
}

void Damage(int& hp, int att)
{
    hp -= att;
}

bool IsLive(int hp)
{
    if (hp <= 0) {
        return false;
    }
    return true;
}

int main()
{
    //std::locale::global(std::locale("ko_KR.UTF-8")); //.cpp
    
    int PlayerHp = 200;
    int PlayerAtt = 20;
    char PlayerName[40] = "fasdhjkfasdhjkfasdhjfklasdhjkfasdh";
    //char PlayerName[40];

    int MonsterHp = 100;
    int MonsterAtt =50;
    char MonsterName[40] = "Monster";

    if (PlayerHp <= 0 || MonsterHp <= 0)
    {
        printf_s("hp는 0보다 작거나 같을수 없습니다.");
        return 0;
    }
    if (PlayerAtt <= 0 && MonsterAtt <= 0)
    {
        printf_s("둘다 공격력이 0보다 작거나 같을수 없습니다.");
        return 0;
    }

    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    StatusRender(MonsterName, MonsterAtt, MonsterHp);

    while (true)
    {
        _getch();            // 아무키나 입력할때까지 기다리는 함수
        Damage(MonsterHp, PlayerAtt);
        
        system("cls");
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        if (!IsLive(MonsterHp)) {
            printf_s("%s win\n", PlayerName);
            return 0;
        }

        _getch();
        Damage(PlayerHp, MonsterAtt);
        
        system("cls");
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        if (!IsLive(PlayerHp)) {
            printf_s("%s win\n", MonsterName);
            return 0;
        }
    }
}
