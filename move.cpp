#include "move.h"



cmove::cmove()
{
}


cmove::~cmove()
{
}


bool cmove::move(int code, CTank * tank, bool ourt)
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

bool cmove::moveAll(int code)
{
	bool stop = move(code, ourTank, 1);
	for (int i = 0; i < t; i++) {
		stop = move(code, tanks[i], 0);
		if (stop) {
			break;
		}
	}
	return stop;
}
