#pragma once
#include"WeaponStore.h"

class FireStone : public WeaponStore {
	Store* store;
public:
	FireStone(void) {}
	~FireStone(void) {}
	FireStone(Store* s) { store = s; }
	std::string GetEquipSort() { return "���� ���� " + store->GetEquipSort(); }
	double cost() { return 4000 + store->cost(); }
};