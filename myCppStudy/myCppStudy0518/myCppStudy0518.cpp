// myCppStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
/////////////////
//5.18 homework//
/////////////////
int StringCount(char* arr)
{
    if (arr == nullptr) {
        return 0;
    }
    int count = 0;
    while (arr[count] != '\0')
    {
        ++count;
    }
    return count;
}

void ChangeChar(char* arr, char prevChar, char nextChar)
{
    // 1. 들어온 글자를 전부 '1'로 채워봐라.
    //  1-1. 함수 내부에서 하지 말고
    // for while도 생각하지 말고
    if (!arr || arr[0] == '\0') {
        printf_s("string is empty");
    }
    else
    {
        for (int i = 0; i < StringCount(arr); ++i)
        {
            if (arr[i] == prevChar)
            {
                arr[i] = nextChar;
            }
        }
    }
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "aa bb";
        // 5이 나와야 합니다.
        // 글자수를 세는 함수입니다.
        int Result = StringCount(Arr);
        printf_s("Arr count : %d \n", Result);
    }
    {
        char Arr[100] = "aaa bbb ccc";
        //char Arr[100] = "";

        ChangeChar(Arr, ' ', 'p');              // "aaa bbb ccc"; => "aaa bbb ddd";
        //ChangeChar(nullptr, 'c', 'd');

        if (Arr && (Arr[0] != '\0')) {
            printf_s("Changed String : %s", Arr);
        }
    }
    return 0;
}
