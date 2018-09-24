#pragma once
#include"WeaponStore.h"

class PowerStone : public WeaponStore {
	Store* store;
public:
	PowerStone(void){}
	~PowerStone(void){}
	PowerStone(Store* s) { store = s; }
	std::string GetEquipSort() { return "���� ���� �߰���" + store->GetEquipSort(); }
	double cost() { return 2000 + store->cost(); }
};