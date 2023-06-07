#include "Snake.h"
#include <stdlib.h>
#include "ConsoleScreen.h"
#include "PosSturct.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Init()
{
	if (!mSnakeBody.empty()) {
		//
		printf_s("something wrong");
	}

	Pos2D tmp;
	tmp.pos_X = (rand() % (ConsoleScreen::Xline - 10)) + 5;
	tmp.pos_Y = (rand() % (ConsoleScreen::Yline - 10)) + 5;

	this->SetPosition(tmp);
	
	mSnakeBody.push_back(tmp);
	tmp = tmp + RIGHT;
	mSnakeBody.push_back(tmp);
	tmp = tmp + RIGHT;
	mSnakeBody.push_back(tmp);
	tmp = tmp + RIGHT;
	mSnakeBody.push_back(tmp);
	tmp = tmp + RIGHT;
	mSnakeBody.push_back(tmp);
	tmp = tmp + RIGHT;
}

void Snake::AddSnakeBody(Pos2D& pos)
{
	mSnakeBody.push_back(pos);
}

bool Snake::IsTouchBody(Pos2D& nextPos)
{
	
	return false;
}

void Snake::MoveSnakeBody(const Pos2D& nextPos)
{
	std::list<Pos2D>::iterator startIter = mSnakeBody.begin();
	std::list<Pos2D>::iterator endIter = mSnakeBody.end();

	Pos2D prev2d, tmp2d;

	for (; startIter != endIter; ++startIter)
	{
		if (startIter == mSnakeBody.begin())
		{
			prev2d = (*startIter);
			(*startIter) = (*startIter) + mDirection;
		}
		else if(*startIter == mSnakeBody.back()) {

			if (IsAddBody)
			{
				AddSnakeBody(*startIter);
				IsAddBody = false;
				(*startIter) = prev2d;
			}
			else {
				tmp2d = (*startIter);
				(*startIter) = prev2d;
				prev2d = tmp2d;
			}
			
			//prev2d = ;
		}
		else {
			tmp2d = (*startIter);
			(*startIter) = prev2d;
			prev2d = tmp2d;

		}
		
		
	}
	
}
