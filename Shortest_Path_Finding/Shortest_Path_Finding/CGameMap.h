#pragma once
class CGameMap
{

private:
	int** _map; // Map Info
	bool** _isVisit; // Check Visit
	int _width; // Width
	int _height; // Height


public:
	CGameMap();
	~CGameMap();
	CGameMap(int w, int h) : _width(w), _height(h) {
		_map = new int*[h];
		_isVisit = new bool*[h];
		for (int i = 0; i < h; i++) {
			_map[i] = new int[w];
			_isVisit[i] = new bool[w];
		}
		initMap();
	}

	// map init
	void initMap();

	// map width, height
	int getWidth() { return _width; }
	int getHeight() { return _height; }

	// Set map Value
	void setMapVal(int x, int y, int val) { _map[y][x] = val; }

	// return map Value
	int getMapVal(int x, int y) { return _map[y][x]; }

	// Set isVisit
	void setIsVisit(int x, int y, bool val) { _map[y][x] = val; }

	// return isVisit
	bool getIsVisit(int x, int y) { return _map[y][x]; }

	// paint screen
	void draw();

};

