#pragma once
#include"Store.h"
class Sword : public Store {
	Store* store;
public:

	Sword(void) {}
	~Sword(void) {}
	Sword(Store* s) { store = s; }
	
	std::string GetEquipSort() {
		return  "이칼의 가격은 : ";
	}
	double cost() {
		return	1000; //무기의 가격.
	}
};