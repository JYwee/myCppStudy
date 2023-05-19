
#include <iostream>

/////////////////
//5.18 homework//
/////////////////


// 스트링 사이즈 반환
int getStrSize(const char* const string)
{
    if (!string) {
        return -1;
    }

    int count = 0;

    while (string[count] != '\0')
    {
        ++count;
    }
    return count;
}

//string 내의 ch 갯수 반환
int ChCount(const char* const string, char Ch)
{
    if (!string) {
        return -1;
    }

    int i = 0;
    int count = 0;
    while (string[i] != '\0')
    {
        char Ch = string[i];

        if (string[i] == Ch) {
            ++count;
        }
        ++i;
    }

    // Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
    return count;
}

//string 내의 ' ' 삭제
void TrimDelete(char* string)
{
    if (string) {
        int i = 0;
        while (string[i] != '\0') 
        {
            if (string[i] == ' ') 
            {
                for (size_t j = 0; j < getStrSize(string) - i; j++)
                {
                    string[i + j] = string[i + j + 1];
                }
            }
            else {
                ++i;
            }
        }
    }
    else {
        printf_s("string is empty");
    }
}

/*number의 자릿수 반환*/ 
int DigitsCount(int number)
{
    if (number < 0) {
        return -1;
    }
        
    int count = 1;
    while (number >= 10) {
        number /= 10;
        ++count;
    }
    
    return count;
}

// left의 상수 문자열을 right 복사
void StrCopy(const char* const left, char* right)
{
    if (left)
    {
        for (size_t i = 0; i < getStrSize(left); ++i)
        {
            right[i] = left[i];
        }
    }
    else {
        printf_s("left string is empty");

    }
    
}

/* 가장 어려운 숙제
int number를 right 문자열로 치환*/
void NumberToString(int number, char* right)
{
    // Result = "312312";
    //if( number < 0)
    int digits = DigitsCount(number);
    for (size_t i = 0; i < digits; ++i)
    {
        right[digits - i - 1 ] = (number % 10) +'0';
        number /= 10;
    }
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'w');
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        // Arr "aabcddee"
        int a = 0;
    }

    {
        // 8이 리턴되게 만들어라.
        int Result = DigitsCount(108880);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(312312, Result);

        //
        printf_s("intToStr : %s", Result);

        char Ch = '0';

        int Value = 7;

        char ChConvert = Value + 48;

        int a = 0;
    }

  
}

