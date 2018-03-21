#pragma once
#include "Game.h"
//#include "Obj.h"
//#include "Tank.h"
#include <ctime>
#include <iostream>
using namespace std;
const int h = 1;
const int up = 72;
const int down = 80;
const int leftm = 75;
const int rightm = 77;
const int moves[] = { up,down,leftm,rightm };

class cmove:public CGame
{
	

public:
	cmove();
	~cmove();
	bool move(int code, CTank* tank, bool ourt);
	bool moveAll(int code);
};

