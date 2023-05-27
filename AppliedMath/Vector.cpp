#include "Vector.h"
#include <math.h>

Vector::Vector() {
	this->x = 0;
	this->y = 0;
}

Vector::Vector(float x = 0, float y = 0) {
	this->x = x; 
	this->y = y;
}

double Vector::getLength() {
	return sqrt((x * x) + (y * y));
}

void Vector::setX(float x) {
	this->x = x;
}

void Vector::setY(float y) {
	this->y = y;
}

float Vector::getX() {
	return this->x;
}
float Vector::getY() {
	return this->y;
}


