#include "Game.h"
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int h = 1;
const int up = 72;
const int down = 80;
const int leftm = 75;
const int rightm = 77;
const int moves[] = { up,down,leftm,rightm };

void CGame::Inizialize()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = nullptr;
		}
	}

	//розтавить стены


	ourTank = new CTank();
	ourTank->setFace('*');
	matr[5][8] = ourTank;
	
	tr = new Treasure(10,10);
	tr->setFace('?');
	matr[tr->getX() ][tr->getY()] = tr;


	tanks = new CTank*[t];
	for (int i = 0; i < t; i++) {
		tanks[i] = new CTank;
		int x = 0 + rand() % m;
		int y = 0 + rand() % n;
		matr[x][y] = tanks[i];
	}

}



CGame::CGame(int _m, int _n, int _t)
{
	m = _m;
	n = _n;
	t = _t;
	counter = 3;
	matr = new CObj**[m];
	for (int i = 0; i < m; i++) {
		matr[i] = new CObj*[n];
	}

	
	Inizialize();
	
}

void CGame::show() const
{
	system("cls");

	cout << "\xc9";
	for (int i = 0; i < n; i++) cout << "\xcd";
	cout << "\xbb" << endl;
	for (int i = 0; i < m; i++) {
		cout << "\xba";
		for (int j = 0; j < n; j++) {
			if (matr[i][j] == nullptr)  cout << " ";
			if (matr[i][j] != nullptr) {
				/*if ((i == ourTank->getX()) && (j == ourTank->getY()))
					cout << "*";
				else  --cout << ".";*/
				    cout << matr[i][j]->getFace();
			}

			
		}
		cout << "\xba" << endl;
	}

	cout << "\xc8";
	for (int i = 0; i < n; i++) cout << "\xcd";
	cout << "\xbc" << endl;
	
}


bool CGame::move(int code, CTank* tank, bool ourt)
{
	bool stop = false;
	int y = tank->getY();
	int x = tank->getX();
	matr[tank->getX()][tank->getY()] = nullptr;
	int ourx = ourTank->getX();
	int oury = ourTank->getY();
	if (!ourt)
	{	
		srand(time(0));
		int dir = 0 + rand() % 3;
		code = moves[dir];
	}
	
		switch (code) {
		case up:
			x = tank->getX();
			if (x - h <= 0) {
				tank->setX(x + m - 1 - h);
			}
			else {
				tank->setX(tank->getX() - h);
			}
			break;
		case down://down
			x = tank->getX();
			if (x + h >= m) {
				tank->setX(x - m + h);
			}
			else tank->setX(x + h);
			break;
		case leftm://left
			y = tank->getY();
			if (y - h <= 0) {
				tank->setY(y + n - h);
			}
			else tank->setY(y - h);

			break;
		case rightm:// right
			y = tank->getY();
			if (y + h >= n) {
				tank->setY(y - n + h);
			}
			else {
				tank->setY(tank->getY() + h);
			}
			break;
		}

		matr[tank->getX()][tank->getY()] = tank;
	
	if (!ourt) {
		if ((tank->getX() == ourx) || (tank->getY() == oury)) {
			matr[ourx][oury] = nullptr;			
			stop = true;
		}
		if ((tank->getX() == tr->getX()) || (tank->getY() == tr->getY())) {
			matr[tr->getX()][tr->getY()] = nullptr;
			counter = 0;
			stop = true;
		}

	}
	show();
	return stop;

}

bool CGame::moveAll(int code)
{
	bool stop=move(code, ourTank, 1);
	for (int i = 0; i < t; i++) {
		stop=move(code,tanks[i],0);
		if (stop) {
			break;
		}
	}
	return stop;
}

void CGame::fire()
{	
	
	int ourx = ourTank->getX();
	int oury = ourTank->getY();	
	for (int i = 0; i < t; i++) {
		int y = tanks[i]->getY();
		int x = tanks[i]->getX();
		if ((x == ourx)|| (y == oury)){
		  matr[x][y] = nullptr; 
		  t = t - 1;
			  for (int k = i; k < t; k++) {
				  tanks[k] = tanks[k + 1];
			  }
			  
		}
		
	}
	
		show();
	
}

void CGame::resurrection()
{
	matr[ourTank->getX()][ourTank->getY()] = ourTank;
}



CGame::~CGame()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j]) delete matr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		delete[]matr[i];
	}
	delete[]matr;
}


