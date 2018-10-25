#pragma once
#include<iostream>
#include<string>
class Store {
	// 1. ���� ������ Decorator ������ �������� ������.
	// 2. ������ ������ ���� �Ǹ� ��ǰ�� �޸�����.
	// 3. �⺻������ ��°��� ��ȭ�� ���� ������ �ø���.
	// 4. ��ȭ, ������ �����ǰ� �Ͽ� ������ ���� �÷� ����.

private:
	std::string StoreSort; //������ ����.
	std::string Equip; //����� ����. 

public:
	Store(void):Equip("�˷��������� �����Դϴ�."){}
	~Store(void){}
	Store(std::string s) : Equip(s){}

	//���� �Լ� ����.
	virtual std::string GetStoreSort() { return StoreSort; } //���� ����.
	virtual std::string GetEquipSort() { return Equip; } // ��� ����.
	virtual double cost() = 0; // ����� ����.
};