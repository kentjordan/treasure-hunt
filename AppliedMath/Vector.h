#pragma once

#include "Vector.h"

class Vector {

private:
	float x, y;

public:
	Vector();
	Vector(float x, float y);

	void setX(float x) ;
	float getX();

	void setY(float y);
	float getY();

	double getLength();

};
