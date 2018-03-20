#include "Wall.h"



CWall::CWall()
{
	face = '#';
}

string CWall::type() const
{
	return "CWall";
}


CWall::~CWall()
{
}
