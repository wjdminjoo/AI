#pragma once
#include"Store.h"
class WeaponStore : public Store{
	

public:
	WeaponStore(void) {}
	~WeaponStore(void) {}
	std::string GetEquipSort() {
		return "���ϴ� ���⸦ ����.";
	}
	double cost() { return 0; }
	std::string GetStoreSort() {
		return "��Ͷ�, ���� ���⸦ �ַ� �Ǹ��Ѵ�.";
	}
	
};