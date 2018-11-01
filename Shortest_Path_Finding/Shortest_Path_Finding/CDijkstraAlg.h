#pragma once
#include<stack>
#include<list>
struct point {
	int x;
	int y;
};

class CGameMap;
class CDijkstraAlg
{
	CGameMap* _gameMap;
	std::stack<point> _path; // Start Node to Target Node
	std::list<point> _VisitNode; // Founding Visit Node Save.
	bool _IsFound;

public:
	CDijkstraAlg();
	~CDijkstraAlg();
	CDijkstraAlg(CGameMap* map) :_gameMap(map), _IsFound(false) {};

	// ref วüลย, Extract Min - Get a Node
	void choiceNode(point &choisNode, int dX, int dY); 

	// find a shortest path s = start, d = destination
	bool findPath(int sx, int sy, int dx, int dy); 
	void draw(); 

};

