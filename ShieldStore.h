#pragma once
#include"Store.h"
#include<list>
// 1. 팩토리 패턴을 이뤄야함.
// 2. 상위는 앞과 같이 Store를 받을 예정.
// 3. 여기서 최상위는 Store지만 ShieldStore에 Shield를 하위로 주어 작성할 예정.
// 4. 방패 생성 공정을 표현할 생각.
class ShieldStore : public Store {
	std::string name; // 방패의 이름.
	std::string limit; // 착용 한도
	double retention;// 방어력.

public:
	std::list<std::string> material; // 방패의 재료.

	ShieldStore(void){}
	~ShieldStore(void){}
	// 방패 생성 공정.
	std::string GetStoreSort() {
		std::cout << "철판에 모양을 잡아줍니다." << std::endl;
		std::cout << "모양을 따라 철판을 잘라줍니다." << std::endl;
		std::cout << "겉을 다듬어 준 후 철판을 둥군 형태로 만들어줍니다." << std::endl;
		std::cout << "손잡이를 원하는 곳에 붙여주어 방패가 완성 되었습니다." << std::endl;
		std::list<std::string>::iterator itr;
		for (itr = material.begin(); itr != material.end(); itr++)
			std::cout << " [ " << *itr <<  "]";
		std::cout << std::endl;
		return "이름과 재료, 스펙이라네.";
	}
	double cost() { return NULL; }
	//std::string GetStoreSort() { return "여기는 방패를 만든다네."; }
	std::string GetEquipSort() { return "방패는 등, 왼손, 오른손 어디에든 착용 할 수 있지."; }
	void successTalk() { std::cout << "좋아 완성이군!" << std::endl; }
	std::string getName() { return name; }
};