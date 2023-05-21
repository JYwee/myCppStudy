
#include <iostream>

/////////////////
//5.18 homework//
/////////////////

//언더,오버플로우 체크
bool IsIntRangeRight(const int value) 
{
    const int max = 0b01111111111111111111111111111111;
    const int min = 0b10000000000000000000000000000000;
    if (value > max) {
        return false;
    }
    else if (value < min) {
        return false;
    }
    return true;
}


// 스트링 사이즈 반환
int GetStrSize(const char* const string)
{
    if (!string) {
        return -1;
    }

    int count = 0;

    while (string[count] != '\0'){
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

    int count = 0;

    for(size_t i =0; i<GetStrSize(string); ++i)
    {
        if (string[i] == Ch) {
            ++count;
        }
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
                for (size_t j = 0; j < GetStrSize(string) - i; j++)
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
    /*if (number < 0) {
        return -1;
    }*/
    if (!IsIntRangeRight(number)) {
        return -1;
    }
   
    int count = 0;

    if (number > 0) 
    {
        count = 1;
        while (number >= 10) 
        {
            number /= 10;
            ++count;
        }
    }
    else if (number < 0) 
    {
        //count = 0;
        while (number <= -1) 
        {
            number /= 10;
            --count;
        }
    }
    return count;
}

// left의 상수 문자열을 right 복사
void StrCopy(const char* const left, char* right)
{
    if (left)
    {
        for (size_t i = 0; i < GetStrSize(left); ++i)
        {
            right[i] = left[i];
        }
    }
    else {
        printf_s("left string is empty");

    }
    
}

//int number를 right 문자열로 치환
void NumberToString(int number, char* right)
{
    if (!IsIntRangeRight(number)) {
        printf_s("wrong value, might be over or under flow");
    }
    else {
        // Result = "312312";
        
        int digits = DigitsCount(number);
        if (digits < 0)                    // 음수의 경우
        {
            digits = ~digits;
            ++digits;
            number = ~number;
            ++number;

            for (size_t i = 0; i < digits + 1; ++i)
            {
                if (i == digits) {
                    right[digits - i] = '-';
                }
                else 
                {
                    right[digits - i] = (number % 10) + '0';
                    number /= 10;
                }   
            }
        }
        else if(digits > 0)                 // 양수의 경우
        {
            for (size_t i = 0; i < digits; ++i)
            {
                right[digits - i - 1] = (number % 10) + '0';
                number /= 10;
            }
        }
        else {
            right[digits] = '0';
        }
    }
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaaaa ccc ddd eee", 'a');

        int a = 0;
    }

    {
        char Arr[256] = " aa  b  c dd ee  ";
        //char Arr[256] = { NULL };

        TrimDelete(Arr);

        int a = 0;
    }

    {
        int Result = DigitsCount(10880010);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);
        //StrCopy(nullptr, ArrCopyText);
        int a = 0;
    }
    
    {
        char Result[256] = {};

        NumberToString(-321230, Result);

        printf_s("intToStr : %s", Result);

        int a = 0;
    }

  
}

