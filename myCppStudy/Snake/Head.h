#pragma once
#include "Part.h"

// Ό³Έν :
class Head : public Part
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	int4 GetDirection() const
	{
		return mDirection;
	}

	void SetDirection(const int4& dir)
	{
		mDirection = dir;
	}

	bool IsContact(const int4& nexPos) ;

protected:
	void Tick(float _Time);



private:

	int4 mDirection = { 0,0 };

};

