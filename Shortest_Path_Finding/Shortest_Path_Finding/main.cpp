#include "CDijkstraAlg.h"
#include "CGameMap.h"

void main() {
	CGameMap _gameMap(10, 10);
	CDijkstraAlg _shortPath(&_gameMap);

	_shortPath.draw();

	bool _IsFound = _shortPath.findPath(0, 9, 5, 5);
	_shortPath.draw();

	system("pause");
}