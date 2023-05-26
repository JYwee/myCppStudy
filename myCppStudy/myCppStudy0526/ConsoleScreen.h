#pragma once
class int4;

class ConsoleScreen
{
public:
    ConsoleScreen();
    ~ConsoleScreen();
    void Init(char _BaseCh);
    

    void SetPixel(const int4& _Pos, char _Ch);
    void Clear();
    bool IsScreenOut(const int4& _Pos) const;
    void Print() const;
    


private:

    static const int XLine = 20;
    static const int YLine = 10;


    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};