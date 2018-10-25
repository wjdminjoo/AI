#pragma once
#pragma once
#include"ShieldStore.h"
#include<string>
class nomalShield : public ShieldStore {
	Store* store;

public:
	nomalShield(void) {}
	nomalShield(Store* s) {
		store = s;
		material.push_back("일반 방패");
		material.push_back("길에 굴러다니던 나무로 다듬어 만든 방패입니다.");
		material.push_back("힘 : 1 이상이 필요합니다.");
	}
	~nomalShield(void) {}
	double cost() { return 1000; }
};