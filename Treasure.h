#pragma once
#include "Obj.h"
class Treasure:public CObj
{
	int x;
	int y;

public:
	int getX() { return x; };
	int getY() { return y; };
	void setX(int _x) { x = _x; };
	void setY(int _y) { y = _y; };
	Treasure(int _x, int _y) { x = _x; y = _y; setFace('?'); }
	~Treasure();
};

