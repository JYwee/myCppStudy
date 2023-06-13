#pragma once
#include "ConsoleObject.h"

// Ό³Έν :
class Part : public ConsoleObject
{
public:
	// constrcuter destructer
	Part();
	~Part();

	// delete Function
	Part(const Part& _Other) = delete;
	Part(Part&& _Other) noexcept = delete;
	Part& operator=(const Part& _Other) = delete;
	Part& operator=(Part&& _Other) noexcept = delete;

	Part* GetNext() {
		return Next;
	}
	Part* GetPrev() {
		return Prev;
	}
	int4 GetPrevPos() const{
		return PrevPos;
	}

	void SetNext(Part* _Next) {
		Next = _Next;
	}
	void SetPrev(Part* _Prev) {
		Prev = _Prev;
	}
	void SetPrevPos(const int4& _PrevPos) {
		PrevPos = _PrevPos;
	}

	//virtual void Tick(float _Time);
	
protected:

private:
	Part* Next = nullptr;
	Part* Prev = nullptr;
	int4 PrevPos;
};

