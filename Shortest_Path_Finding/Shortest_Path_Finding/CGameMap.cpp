#include "CGameMap.h"
#include <iostream>


CGameMap::CGameMap()
{
}


CGameMap::~CGameMap()
{
}

void CGameMap::initMap()
{
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			_map[y][x] = 1000;
			_isVisit[y][x] = false;
		}
	}
}

void CGameMap::draw()
{
	std::cout << "============ ============ ============ ============ ============ ============ ============ ============ \n";
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			std::cout << _map[y][x] << "\t";
		}
		std::cout << "\n";
	}
}
