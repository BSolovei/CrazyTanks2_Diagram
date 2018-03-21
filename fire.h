#pragma once
#include "Game.h"
//#include "Obj.h"
//#include "Tank.h"
#include <ctime>
#include <iostream>
using namespace std;

class fire :public CGame
{
public:
	fire();
	~fire();
	void fireTanks();
};

