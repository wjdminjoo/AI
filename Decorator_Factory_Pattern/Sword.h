#pragma once
#include"Store.h"
class Sword : public Store {
	Store* store;
public:

	Sword(void) {}
	~Sword(void) {}
	Sword(Store* s) { store = s; }
	
	std::string GetEquipSort() {
		return  "��Į�� ������ : ";
	}
	double cost() {
		return	1000; //������ ����.
	}
};