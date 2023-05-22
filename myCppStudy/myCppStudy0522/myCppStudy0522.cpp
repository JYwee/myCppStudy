#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수
#include <stdlib.h>

// 상태와 개념을 하나로 묶어서 내가 인간적인 생각을 문법으로 표현한다.
// 이걸 객체지향의 특성이 추상화라고 합니다.

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
// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.
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
// 내일꼭 break continue

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

    // 숙제 2 -- 실시간으로 만들어오세요.
    // 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
    // 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
    // 그냥 무식하게 생각해라.
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
       
        _getch();

        // 아무키나 입력할때까지 기다리는 함수
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
        // 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.
        // 몬스터와 플레이어가 서로 한대씩 때리면서
        // 한명이 죽으면 끝납니다.
        // 지금 그걸 그래픽으로 표현할 방법이 없으니까.
        // 글자로 표현하겠습니다.
    }
}
