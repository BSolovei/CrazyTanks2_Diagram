#include "Tank.h"

int CTank::counter = 0;

CTank::CTank()
{
	number = counter++;
	x = 0;
	y = 0;
	face = '-';
}

string CTank::type() const
{
	return "CTank";
}

int CTank::getNumber()const
{
	return number;
}


CTank::~CTank()
{
}
