#pragma once

template <typename Type>
class SingletonType
{
protected:
	SingletonType() {}
	virtual ~SingletonType() {}

public:
	//static Type* 
	
	static Type* GetInstance() {
		if (!mInstance) {
			mInstance = new Type();
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
	static Type* mInstance;
};

template <typename T> T* SingletonType<T>::mInstance = nullptr;