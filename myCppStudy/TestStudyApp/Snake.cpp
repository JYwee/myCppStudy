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
	tmp.pos_X = (rand() % (ConsoleScreen::Xline - 5)) + 1;
	tmp.pos_Y = (rand() % (ConsoleScreen::Yline - 5)) + 1;

	this->SetPosition(tmp);
	
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
