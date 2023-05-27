#pragma once
#include "Point.h"
#include "Vector.h"
#include "Coordinate.h"

class Player {

private:
	Point player;
	Vector vPlayer;
	Coordinate coord;

public:
	Player(Coordinate coordinate);
	void movement();
	void resetPlayerPosition();
	void KeyW();
	void KeyS();
	void KeyA();
	void KeyD();
};