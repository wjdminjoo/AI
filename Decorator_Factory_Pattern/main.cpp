#include"WeaponStore.h"
#include"Sword.h"
#include"PowerStone.h"
#include"FireStone.h"
#include"ShieldStore.h"
#include"LegendaryShield.h"
#include"nomalShield.h"
int main() {

	Store* weaponStore = new WeaponStore();
	Store* FireSword = new WeaponStore();
	Store* Shield = new ShieldStore();

	std::cout << "데코레이터 패턴의 예제" << std::endl;
	//Decorator Pattern 
	weaponStore = new Sword(weaponStore);
	std::cout << weaponStore->GetEquipSort();
	std::cout << weaponStore->cost() << std::endl;
	weaponStore = new PowerStone(weaponStore);
	std::cout << weaponStore->GetStoreSort() << std::endl;
	std::cout << weaponStore->GetEquipSort();
	std::cout << weaponStore->cost() << std::endl;
	weaponStore = new FireStone(weaponStore);
	std::cout << weaponStore->GetStoreSort() << std::endl;
	std::cout << weaponStore->GetEquipSort();
	std::cout << weaponStore->cost() << std::endl;
	FireSword = new Sword(FireSword);
	std::cout << FireSword->GetEquipSort();
	std::cout << FireSword->cost() << std::endl;
	FireSword = new FireStone(FireSword);
	std::cout << FireSword->GetStoreSort() << std::endl;
	std::cout << FireSword->GetEquipSort();
	std::cout << FireSword->cost() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "팩토리 패턴의 예제" << std::endl;
	//Factory Pattern
	Shield = new LegendaryShield(Shield);
	std::cout << Shield->GetStoreSort() << std::endl;
	std::cout << Shield->GetEquipSort() << std::endl;
	std::cout << Shield->cost() <<"골드라네" <<std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Shield = new nomalShield(Shield);
	std::cout << Shield->GetStoreSort() << std::endl;
	std::cout << Shield->GetEquipSort() << std::endl;
	std::cout << Shield->cost() << "골드라네" << std::endl;
	system("pause");
	return 0;
}