#include"CDijkstraAlg.h"
#include"CGameMap.h"
#include<iostream>


CDijkstraAlg::CDijkstraAlg()
{
}


CDijkstraAlg::~CDijkstraAlg()
{
}

void CDijkstraAlg::choiceNode(point & choisNode, int dX, int dY)
{

	// 다익스트라 AL
	//int _max = INT_MAX;

	//int _width = _gameMap->getWidth();
	//int _height = _gameMap->getHeight();


	//int _cx, _cy;

	//// Select the node with the smallest weight among the uninvited nodes that are connected to the visited node
	//std::list<point>::reverse_iterator _curPos;
	//for (_curPos = _VisitNode.rbegin(); _curPos != _VisitNode.rend(); _curPos++) {
	//	for (int _ty = -1; _ty <= 1; _ty++) {
	//		for (int _tx = -1; _tx <= 1; _tx++) {
	//			_cx = _curPos->x + _tx;
	//			_cy = _curPos->y + _ty;
	//			if (_cx < 0 || _cx > _width - 1 || _cy < 0 || _cy > _height - 1 || (_tx == 0 && _ty == 0)) continue;
	//			if (_gameMap->getMapVal(_cx, _cy) < _max && _gameMap->getIsVisit(_cx, _cy) == false) {
	//				_max = _gameMap->getMapVal(_cx, _cy);
	//				choisNode = { _cx, _cy };
	//			}
	//		}
	//	}
	//}

	// Astar AL
	int _max = INT_MAX;

	int _width = _gameMap->getWidth();
	int _height = _gameMap->getHeight();


	int _cx, _cy;

	// Select the node with the smallest weight among the uninvited nodes that are connected to the visited node
	std::list<point>::reverse_iterator _curPos;
	for (_curPos = _VisitNode.rbegin(); _curPos != _VisitNode.rend(); _curPos++) {
		for (int _ty = -1; _ty <= 1; _ty++) {
			for (int _tx = -1; _tx <= 1; _tx++) {
				_cx = _curPos->x + _tx;
				_cy = _curPos->y + _ty;
				if (_cx < 0 || _cx > _width - 1 || _cy < 0 || _cy > _height - 1 || (_tx == 0 && _ty == 0)) continue;
				auto difdX = abs(_cx - dX);
				auto difdY = abs(_cy - dY);
				auto h = (difdX + difdY) * 10;
				if (_gameMap->getMapVal(_cx, _cy) < _max && _gameMap->getIsVisit(_cx, _cy) == false) {
					_max = _gameMap->getMapVal(_cx, _cy);
					choisNode = { _cx, _cy };
				}
			}
		}
	}
}

bool CDijkstraAlg::findPath(int sx, int sy, int dx, int dy)
{
	_IsFound = false;
	int _width = _gameMap->getWidth();
	int _height = _gameMap->getHeight();

	// each Node parent Info Save.
	point **_parent; 

	_parent = new point*[_height];
	for (int i = 0; i < _width; i++) 
		_parent[i] = new point[_width];

	// V - S Node. Than smaller.
	point _choiceNode;

	// Start Node.
	_choiceNode = { sx, sy };
	_gameMap->setMapVal(sx, sy, 0);
	_parent[sy][sx] = _choiceNode;

	for (int i = 0; i < _width * _height; i++) {
		choiceNode(_choiceNode, dx, dy);
		_gameMap->setIsVisit(_choiceNode.x, _choiceNode.y, true);
		_VisitNode.push_back(_choiceNode);
		if (_choiceNode.x == dx && _choiceNode.y == dy) {
			// Destination Visit.
			_IsFound = true;
			break;
		}

		// near Node Edge Relax
		for (int ty = -1; ty <= 1; ty++) {
			for (int tx = -1; tx <= 1; tx++) {
				int _nextX = _choiceNode.x + tx;
				int _nextY = _choiceNode.y + ty;

				int _dist;
				// out of Range
				if (_nextX < 0 || _nextX > _width - 1 || _nextY < 0 || _nextY > _height - 1)
					continue;
				// Edge Relax
				if (_gameMap->getIsVisit(_nextX, _nextY) == false) {
					_dist = (tx == 0 || ty == 0) ? 10 : 14;

					if (_gameMap->getMapVal(_choiceNode.x, _choiceNode.y) + _dist < _gameMap->getMapVal(_nextX, _nextY)) {
						int _newVal = _gameMap->getMapVal(_choiceNode.x, _choiceNode.y) + _dist;
						_gameMap->setMapVal(_nextX, _nextY, _newVal);
						_parent[_nextX][_nextY] = _choiceNode;
					}
				}
			}
		}
	}
	if (_IsFound) {
		point _p;
		_p = { dx, dy };
		_path.push(_p);
		while (_p.x != sx || _p.y != sy) {
			_p = _parent[_p.y][_p.x];
			_path.push(_p);
		}
		return true;
	}

	return false;
}

void CDijkstraAlg::draw()
{
	_gameMap->draw();
	if (_IsFound) {
		point _curNode;

		while (!_path.empty()){
			_curNode = _path.top();
			std::cout << "(" << _curNode.x << ", " << _curNode.y << ") ==> ";
			_path.pop();
		}

		std::cout << "CONGRATULATION YOU FOUND THE SHORTEST PATH \n";
	}
}
