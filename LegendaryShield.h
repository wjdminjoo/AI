#pragma once
#include"ShieldStore.h"
#include<string>
class LegendaryShield : public ShieldStore {
	Store* store;

public:
	LegendaryShield(void) {}
	LegendaryShield(Store* s) { store = s; 
	material.push_back("������ ����");
	material.push_back("ƼŸ���� �ƴٸ�Ÿ��Ʈ�� ������ ��ǰ�Դϴ�.");
	material.push_back("�� : 500 ���� : 400 �� �ʿ��մϴ�.");
	}
	~LegendaryShield(void) {}
	double cost() { return 932801; }
};