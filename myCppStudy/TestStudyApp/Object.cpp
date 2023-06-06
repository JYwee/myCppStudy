#include "Object.h"
#include "PosSturct.h"
#include "GameManager.h"


Object::Object() {

}
Object::~Object() {

}

void Object::Destory() {
	mIsEnable = false;
	GameManager::GetInstance()->getConsoleScreen().GetInstance()->SetPixel(mPosition, ' ');
	
}