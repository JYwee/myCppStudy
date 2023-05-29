#pragma once
#include "Object.h"
class Bullet :   public Object
{
public:
	Bullet();
	~Bullet();

	void OnFire();
	bool IsOnFire() {
		return mbulletState;
	}
	void SetBulletState(bool state) {
		mbulletState = state;
	};

private:
	bool mbulletState;
};

