#pragma once
#include "Head.h"
#include "Body.h"
#include <list>

class createManager
{
public:
	createManager();
	~createManager();


	Head* mHead;
	Body* mBody;

	std::list<Part*> mPartList;

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