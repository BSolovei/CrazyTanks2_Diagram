#include "Game.h"
//#include "GameMove.h"
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

	//gm = new GameMove();



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


