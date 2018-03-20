#pragma once
#include "Obj.h"
#include "Treasure.h"
#include "Tank.h"
class CGame
{
	int m;
	int n;
	int t;
	CTank* ourTank;
	CTank** tanks;
	CObj*** matr;
	Treasure* tr;
	int counter;
	void Inizialize();

	bool move(int code, CTank* tank, bool ourt);
public:
	
	CGame(int _m = 15,int _n = 15,int _t = 6);
	int getT() { return t; };
	int getcounter() { return counter; };
	void setcounter( int _c) { counter=_c; };
	void show()const;
	bool moveAll(int code);
	void fire();	
	void resurrection();
	~CGame();
};

