//
//  Astar.cpp
//  Astar_Algorithm
//
//  Created by MinJu Jeong on 30/10/2018.
//  Copyright © 2018 MinJu Jeong. All rights reserved.
//
//

//  Astar.cpp

//  Astar_Algorithm

//

//  Created by MinJu Jeong on 30/10/2018.

//  Copyright © 2018 MinJu Jeong. All rights reserved.

//



#include "Astar.hpp"

#include <map>

#include <set>

#include <queue>





Astar::Astar(int _sX, int _sY, int _dX, int _dY) {

	_end[0] = _dX;

	_end[1] = _dY;



	std::vector<_Node*> _NodeMap(_size * _size);



	for (int i = 0; i < _NodeMap.size(); i++) {

		_NodeMap[i] = new _Node();

		_NodeMap[i]->_x = i / _size;

		_NodeMap[i]->_y = i % _size;

	}

	setPass(1, 0, false, _NodeMap);

	OPEN.push_back(_NodeMap[_sX * _size + _sY]);



	while (!OPEN.empty()) {

		_Node* _current = OPEN[0];



		if (_current->_x == _dX && _current->_y == _dY) break;



		CLOSE.push_back(_current);

		OPEN.erase(OPEN.begin());

		std::vector<_Node*> _vector = getChild(_NodeMap, _current);



		for (auto _x : _vector) {

			int h = Dist(_x->_x, _x->_y); //  지금까지 움직인 횟수.

			int g = _current->_g + 1; // 앞으로 예상되는 값

			int f = h + g; // g + h 앞으로의 경로.



			if (std::find(OPEN.begin(), OPEN.end(), _x) != OPEN.end()) {

				if (f < _x->_f) {

					_x->_h = h;

					_x->_g = g;

					_x->_f = f;

					_x->_parent = _current;

				}

			}
			else if (std::find(CLOSE.begin(), CLOSE.end(), _x) != CLOSE.end())

				continue;

			else {

				_x->_h = h;

				_x->_g = g;

				_x->_f = f;

				_x->_parent = _current;

				OPEN.push_back(_x);

			}

		}

		std::sort(OPEN.begin(), OPEN.end(), Cmpf);

	}

	_Node* node = _NodeMap[_dX * _size + _dY];

	while (node) {

		node->_isPath = true;

		node = node->_parent;

	}

	for (auto node : _NodeMap) {

		if (node->_isPath) std::cout << "o";

		else if (!node->_pass) std::cout << "x";

		else std::cout << " ";



		if (node->_y == _size - 1) std::cout << std::endl;

	}



}





// abs = 절대값을 출력.

int Astar::Dist(int _sX, int _sY) {

	return abs(_end[0] - _sX) + abs(_end[1] - _sY);

}


std::vector<_Node*> Astar::getChild(const std::vector<_Node *> &_NodeMap, const _Node *_node) {

	std::vector<std::pair<int, int>> dir;

	dir.push_back(std::pair<int, int>(1, 0));

	dir.push_back(std::pair<int, int>(1, 1));

	dir.push_back(std::pair<int, int>(1, -1));

	dir.push_back(std::pair<int, int>(0, 1));

	dir.push_back(std::pair<int, int>(0, -1));

	dir.push_back(std::pair<int, int>(-1, 0));

	dir.push_back(std::pair<int, int>(-1, 1));

	dir.push_back(std::pair<int, int>(-1, -1));

	std::vector<_Node*> v;



	for (int i = 0; i < dir.size(); i++) {

		int x = _node->_x + dir[i].first;

		int y = _node->_y + dir[i].second;

		if ((x >= 0 && x < _size) && (y >= 0 && y < _size) && (_NodeMap[x*_size + y]->_pass != 0))

			v.push_back(_NodeMap[x*_size + y]);

	}



	return v;

}



void Astar::setPass(int x, int y, bool _isPass, std::vector<_Node *> &_NodeMap) {

	_NodeMap[x*_size + y]->_pass = 0;

}

//

//bool Astar::Cmpf(_Node *n1, _Node *n2){

//    return n1->_f < n2->_f;

//}