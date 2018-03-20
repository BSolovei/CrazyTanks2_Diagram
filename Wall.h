#pragma once
#include "Obj.h"
class CWall :
	public CObj
{
public:
	CWall();
	virtual string type()const;
	~CWall();
};

