#pragma once
#include "int4.h"

class ConsoleScreen;


class Object
{
public:
    Object();
    //Object(const Object&) = delete;
    ~Object();

    int4 Pos;

    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }
    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }
    bool IsEnableObj() {
        return isEnable;
    }
    void SetEnableObj(bool state) {
        isEnable = state;
    }

    void Destory();

private:
    bool isEnable;
};

