#pragma once
#include"WeaponStore.h"

class FireStone : public WeaponStore {
	Store* store;
public:
	FireStone(void) {}
	~FireStone(void) {}
	FireStone(Store* s) { store = s; }
	std::string GetEquipSort() { return "불의 돌과 " + store->GetEquipSort(); }
	double cost() { return 4000 + store->cost(); }
};