#pragma once
#include"ShieldStore.h"
#include<string>
class LegendaryShield : public ShieldStore {
	Store* store;

public:
	LegendaryShield(void) {}
	LegendaryShield(Store* s) { store = s; 
	material.push_back("전설의 방패");
	material.push_back("티타늄과 아다만타이트를 결합한 작품입니다.");
	material.push_back("힘 : 500 의지 : 400 이 필요합니다.");
	}
	~LegendaryShield(void) {}
	double cost() { return 932801; }
};