// myCppStudy0523.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include <iostream>

class Test
{
public:
    // 100
      
    //과제 1
    //int A;      //4
    //__int64 B;  //8
    //char C;     //1
    //char D;     //1
    //short E; // 2바이트 정수입니다.
    //int F;      //4

    short A;
    char B;
    char C;
    bool D;
    float E;
    short F;
    bool G;
    int H;
    
};

// 1 2 4 8

class Player
{
public:
    int HP;
    int ATT;
    Player() {};
    void testFunc()     
    {
  //      return (__int64)&testFunc;
    };
};

//
// 과제 2  [H][H][H][H] [A][A][A][A] [_T][_T][_T][_T] [][][][]
//
void TestFunction(Player _Newplayer, int _Test)
{
    size_t Size = sizeof(_Newplayer);
    __int64 Address0 = (__int64)&_Newplayer.HP;    //657795840400
    __int64 Address1 = (__int64)&_Newplayer.ATT;   //657795840404

    //__int64 Address_T = (__int64)&_Newplayer.testFunc;

    __int64 Address_T = (__int64)&_Test;           //657795840408


    // 이것도 확인해보세요.
}

int main()
{
    size_t Size = sizeof(Test);

    //// 경우 2
    //int A;      //4
    //__int64 B;  //8
    //char C;     //1
    //char D;     //1
    //short E;    // 2바이트 정수입니다.
    //int F;      //4

    // 
    // 
    // 과제 1 [A][A][A][A][][][][] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F] 
    //
    // 
    // 
    //// 다른 경우 임의 테스트
    //short A;
    //char B;
    //char C;
    //bool D;
    //float E;
    //short F;
    //bool G;
    //int H;
    
    // size는 20  
    // [A][A][B][C] [D][][][] [E][E][E][E] [F][F][G][] [H][H][H][H] 

    Test NewTest;


    __int64 Address0 = (__int64)&NewTest.A;
    __int64 Address1 = (__int64)&NewTest.B;
    __int64 Address2 = (__int64)&NewTest.C;
    __int64 Address3 = (__int64)&NewTest.D;
    __int64 Address4 = (__int64)&NewTest.E;
    __int64 Address5 = (__int64)&NewTest.F;
    __int64 Address6 = (__int64)&NewTest.G;
    __int64 Address7 = (__int64)&NewTest.H;


    size_t SizeP = sizeof(Player);

    Player NewPlayer = Player();
    TestFunction(NewPlayer, 20);
    
    //
    //아래는 실험.
    //
    size_t SizeTest = sizeof(&TestFunction);        //8
    __int64 AddressTest = (__int64)&TestFunction;   //  140699984728384
    auto AddressTest2 = &TestFunction;              //0x00007ff7cca31140

    size_t SizeTest2 = sizeof(&Player::testFunc);   //8
    auto AddressTest3 = &Player::testFunc;          //0x00007ff7cca313d4
    
    size_t SizeTest3 = sizeof(&NewPlayer.testFunc); //8
    //auto AddressT = &NewPlayer.testFunc;          //에러

    Player *NewPlayer2 = new Player();
    size_t SizeTest4 = sizeof(&NewPlayer2->testFunc);//8
    //auto AddressTest4 = &NewPlayer2->testFunc;    //에러
    
}