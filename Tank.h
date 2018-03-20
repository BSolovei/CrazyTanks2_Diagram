#pragma once
#include "Obj.h"
class CTank :public CObj
{
	static int counter;
	int number;
	
	int x;
	int y;
public:
	int getX() { return x; };
	int getY() { return y; };
	void setX(int _x) {  x=_x; };
	void setY( int _y) { y=_y; };
	CTank();
	CTank(int _x, int _y) { x = _x; y = _y; };
	virtual string type()const;

	int getNumber()const;
	~CTank();
};

