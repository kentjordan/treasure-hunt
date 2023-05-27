#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class Coordinate {

private:
	// 2D Coodinate with pointers of pointers
	string** coordinate;

	// Intial Coordinate's size if there's no explicit value provided
	int x = 1, y = 1;

	// Stage Level starts at one and increments when the user got to [F] finish point
	int level{ 1 };

	boolean willTryAgain = false;

	void Init();

public:
	Coordinate(int _x, int _y);

	string** getCoordinate();

	int getX();

	int getY();

	int getCurrentLevel();

	void Display();

	void nextLevel();

	void clearStage();

	void retryLevel();

	void levelManager(int level);

	void StageOne();

	void StageTwo();

	void StageThree();

	void StageTryAgain();
};