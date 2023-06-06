#pragma once
#include "Object.h"
#include <list>

class Snake :
    public Object
{
public:
    Snake();
    ~Snake();

    void Init();

    void AddSnakeBody(Pos2D& pos);
    
    bool IsTouchBody(Pos2D& nextPos);


    std::list<Pos2D> mSnakeBody;

    void SetDirection(const Pos2D& pos)
    {
        mDirection = pos;
    }

    const Pos2D& GetDirection() const
    {
        return mDirection;
    }


private:

    Pos2D mDirection = LEFT;
    
};

