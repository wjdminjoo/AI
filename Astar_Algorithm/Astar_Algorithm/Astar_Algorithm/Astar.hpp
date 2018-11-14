//
//  Astar.hpp
//  Astar_Algorithm
//
//  Created by MinJu Jeong on 30/10/2018.
//  Copyright © 2018 MinJu Jeong. All rights reserved.
//
#ifndef Astar_hpp

#define Astar_hpp

#include<iostream>

#include<vector>

struct _Node {

	int _x, _y;

	int _f;

	int _g;

	int _h;

	int _pass;

	bool _isPath;

	_Node* _parent;

	_Node(int x = 0, int y = 0) : _x(x), _y(y), _f(0), _g(0), _h(0), _parent(NULL), _pass(1), _isPath(false) {}

};

bool Cmpf(_Node* n1, _Node* n2) {

	return n1->_f < n2->_f;

}



class Astar {

private:

	std::vector<_Node*> OPEN;

	std::vector<_Node*> CLOSE;

	const static int _size = 6;

	int _end[2];

public:

	Astar(int _sX, int _sY, int _dX, int _dY);

	~Astar() {}

	Astar() {}

	int Dist(int _sX, int _sY);

	std::vector<_Node*> getChild(const std::vector<_Node*>& _NodeMap, const _Node* _node);

	void setPass(int _x, int _y, bool _isPass, std::vector<_Node*>& _NodeMap);



};

#endif /* Astar_hpp */