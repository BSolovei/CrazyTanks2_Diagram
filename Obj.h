#pragma once
#include <string>
//#include <iostream>
using namespace std;
class CObj
{
protected:
	char face;
public:
	CObj() ;
	virtual string type()const;
	void setFace(char _face) { face = _face; }
	char getFace() { return face; };
	virtual~CObj();
};

