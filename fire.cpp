#include "fire.h"



fire::fire()
{

}


fire::~fire()
{
}

void fire::fireTanks()
{
	int ourx = ourTank->getX();
	int oury = ourTank->getY();
	for (int i = 0; i < t; i++) {
		int y = tanks[i]->getY();
		int x = tanks[i]->getX();
		if ((x == ourx) || (y == oury)) {
			matr[x][y] = nullptr;
			t = t - 1;
			for (int k = i; k < t; k++) {
				tanks[k] = tanks[k + 1];
			}

		}

	}

	show();
}
