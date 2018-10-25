#pragma once
#include"Store.h"
class WeaponStore : public Store{
	

public:
	WeaponStore(void) {}
	~WeaponStore(void) {}
	std::string GetEquipSort() {
		return "원하는 무기를 골라라.";
	}
	double cost() { return 0; }
	std::string GetStoreSort() {
		return "어서와라, 여긴 무기를 주로 판매한다.";
	}
	
};