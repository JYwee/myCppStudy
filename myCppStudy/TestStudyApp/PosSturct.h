#pragma once

struct Pos2D
{
public:

	int pos_X = 0;
	int pos_Y = 0;

	void operator=(const Pos2D& right)
	{
		pos_X = right.pos_X;
		pos_Y = right.pos_Y;
	}

	Pos2D operator+(const Pos2D& right) const
	{
		Pos2D tmp2D;
		tmp2D.pos_X = pos_X + right.pos_X;
		tmp2D.pos_Y = pos_Y + right.pos_Y;
		return tmp2D;
	}

	Pos2D operator-(const Pos2D& right) const
	{
		Pos2D tmp2D;
		tmp2D.pos_X = pos_X - right.pos_X;
		tmp2D.pos_Y = pos_Y - right.pos_Y;
		return tmp2D;
	}

	bool operator==(const Pos2D& right) const
	{
		return ((pos_X == right.pos_X) && (pos_Y == right.pos_Y));
	}

	void operator++()
	{
		++pos_X;
		++pos_Y;
	}

	void operator--()
	{
		--pos_X;
		--pos_Y;
	}
};

const Pos2D LEFT = { -1, 0 };
const Pos2D RIGHT = { 1, 0 };
const Pos2D UP = { 0, -1 };
const Pos2D DOWN = { 0, 1 };