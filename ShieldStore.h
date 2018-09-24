#pragma once
#include"Store.h"
#include<list>
// 1. ���丮 ������ �̷����.
// 2. ������ �հ� ���� Store�� ���� ����.
// 3. ���⼭ �ֻ����� Store���� ShieldStore�� Shield�� ������ �־� �ۼ��� ����.
// 4. ���� ���� ������ ǥ���� ����.
class ShieldStore : public Store {
	std::string name; // ������ �̸�.
	std::string limit; // ���� �ѵ�
	double retention;// ����.

public:
	std::list<std::string> material; // ������ ���.

	ShieldStore(void){}
	~ShieldStore(void){}
	// ���� ���� ����.
	std::string GetStoreSort() {
		std::cout << "ö�ǿ� ����� ����ݴϴ�." << std::endl;
		std::cout << "����� ���� ö���� �߶��ݴϴ�." << std::endl;
		std::cout << "���� �ٵ�� �� �� ö���� �ձ� ���·� ������ݴϴ�." << std::endl;
		std::cout << "�����̸� ���ϴ� ���� �ٿ��־� ���а� �ϼ� �Ǿ����ϴ�." << std::endl;
		std::list<std::string>::iterator itr;
		for (itr = material.begin(); itr != material.end(); itr++)
			std::cout << " [ " << *itr <<  "]";
		std::cout << std::endl;
		return "�̸��� ���, �����̶��.";
	}
	double cost() { return NULL; }
	//std::string GetStoreSort() { return "����� ���и� ����ٳ�."; }
	std::string GetEquipSort() { return "���д� ��, �޼�, ������ ��𿡵� ���� �� �� ����."; }
	void successTalk() { std::cout << "���� �ϼ��̱�!" << std::endl; }
	std::string getName() { return name; }
};