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
		material.push_back("�Ϲ� ����");
		material.push_back("�濡 �����ٴϴ� ������ �ٵ�� ���� �����Դϴ�.");
		material.push_back("�� : 1 �̻��� �ʿ��մϴ�.");
	}
	~nomalShield(void) {}
	double cost() { return 1000; }
};