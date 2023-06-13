#pragma once
#include "Snake.h"
#include "Apple.h"
#include <list>

class createManager
{
public:
	createManager();
	~createManager();


	Snake* mSnake;
	Apple* mApple;

	std::list<Snake*> mSnakeBodyList;

	static createManager* GetInstance() {
		if (!mInstance) {
			mInstance = new createManager();
		}
		return mInstance;
	}

	static void DestoryInstance() {
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
	}
private:
	static createManager* mInstance;

};

//static createManager* mInstance = nullptr;
//int4 int4::Down = { 0, 1 };
//template <typename T> T* SingletonType<T>::mInstance = nullptr;