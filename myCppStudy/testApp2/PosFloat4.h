#pragma once


struct PosFloat4
{
public:

	static const PosFloat4 LEFT;
	static const PosFloat4 RIGHT;
	static const PosFloat4 UP;
	static const PosFloat4 DOWN;


	float x = 0;
	float y = 0;

	void operator = (const PosFloat4& right)
	{
		x = right.x;
		y = right.y;
	}

	void operator += (const PosFloat4& right)
	{
		x += right.x;
		y += right.y;
	}

	bool operator ==(const PosFloat4& right) const
	{
		return (x == right.x) && (y == right.y);
	}

	PosFloat4 operator + (const PosFloat4& right) const
	{
		PosFloat4 tmp;
		tmp.x = x + right.x;
		tmp.y = y + right.y;
		return tmp;
	}

	PosFloat4 operator * (const PosFloat4& right) const
	{
		PosFloat4 tmp;
		tmp.x = x * right.x;
		tmp.y = y * right.y;
		return tmp;
	}

	PosFloat4 operator - (const PosFloat4& right) const
	{
		PosFloat4 tmp;
		tmp.x = x - right.x;
		tmp.y = y - right.y;
		return tmp;
	}
};

const PosFloat4 PosFloat4::LEFT = { -1.f, 0.f};
const PosFloat4 PosFloat4::RIGHT = { 1.f, 0.f };
const PosFloat4 PosFloat4::UP = { 0.f, -1.f };
const PosFloat4 PosFloat4::DOWN = { 0.f , 1.f };
