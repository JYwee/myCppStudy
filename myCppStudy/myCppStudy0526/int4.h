#pragma once
// 리스 이니셜라이저

//이녀석은 캡슐화된 클래스라기 보다는 기본자료형
struct int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }

    void operator-=(const int4& _Other)
    {
        X -= _Other.X;
        Y -= _Other.Y;
        Z -= _Other.Z;
        W -= _Other.W;
    }

    int4 operator-(const int4& _Other) const
    {
        int4 Return;
        Return.X = X - _Other.X;
        Return.Y = Y - _Other.Y;
        Return.Z = Z - _Other.Z;
        Return.W = W - _Other.W;
        return Return;
    }

    void operator ++()
    {
        X += 1;
        Y += 1;
        Z += 1;
        
    }
    
    void operator --()
    {
        X -= 1;
        Y -= 1;
        Z -= 1;

    }


    bool operator==(const int4& _Other) const
    {
        if (X == _Other.X && Y == _Other.Y &&
            Z == _Other.Z && W == _Other.W) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

