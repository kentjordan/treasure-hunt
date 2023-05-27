#pragma once

class Point {

private:
	int x, y;

public:
	Point(int x, int y);
	Point();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

};
