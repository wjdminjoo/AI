#pragma once
#include<iostream>
#include<string>
class Store {
	// 1. 상점 종류를 Decorator 디자인 패턴으로 만들자.
	// 2. 상점의 종류에 따른 판매 용품을 달리하자.
	// 3. 기본적으로 사는것은 강화를 통해 가격을 올리자.
	// 4. 강화, 소켓이 장착되게 하여 무기의 값을 올려 받자.

private:
	std::string StoreSort; //상점의 종류.
	std::string Equip; //장비의 종류. 

public:
	Store(void):Equip("알려지지않은 종류입니다."){}
	~Store(void){}
	Store(std::string s) : Equip(s){}

	//가상 함수 설정.
	virtual std::string GetStoreSort() { return StoreSort; } //상점 종류.
	virtual std::string GetEquipSort() { return Equip; } // 장비 종류.
	virtual double cost() = 0; // 장비의 가격.
};