#pragma once
#include "Object.h"
#include <list>
#include <vector>

class Snake :
    public Object
{
public:
    Snake();
    ~Snake();


    std::list<Pos2D> mSnakeBody;
    std::vector<Pos2D> mSnakeBody_Vec;


    bool IsAddBody = false;

    void Init();

    void AddSnakeBody(Pos2D& pos);
    
    bool IsTouchBody(Pos2D& nextPos);

    void MoveSnakeBody(const Pos2D& nextPos);
    

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

