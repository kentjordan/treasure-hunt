#include "Coordinate.h";

Coordinate::Coordinate(int _x = 10, int _y = 10) : x(_x), y(_y), coordinate(new string* [this->x])
{
	Init();
	StageOne();
}

string** Coordinate::getCoordinate() {
	return this->coordinate;
}

void Coordinate::Init() {

	for (int i = 0; i < y; i++)
	{
		this->coordinate[i] = new string[this->x];
	}

	for (int i = 0; i < this->y; i++) {
		for (int j = 0; j < this->x; j++) {
			this->coordinate[i][j] = "[ ]";
		}
	}
}

int Coordinate::getX() {
	return this->x;
}

int Coordinate::getY() {
	return this->x;
}

int Coordinate::getCurrentLevel() {
	return this->level;
}

void Coordinate::Display() {
	// Clear the console screen (specific to windows OS)
	system("cls");

	if (getCurrentLevel() >= 4) {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                                           *" << endl;
		cout << "* Congratulations! You've got the treasure! *" << endl;
		cout << "*                                           *" << endl;
		cout << "*********************************************" << endl;
	
	}
	else {
		cout << "------------------------------" << endl;
		cout << "------  Treasure Hunt  -------" << endl;
		cout << "------------------------------" << endl;
		cout << "Stage Lvl: " << to_string(this->level) << endl;
		cout << "------------------------------" << endl;
		cout << "------------------------------" << endl;
		// Render the Stage Coordinate
		for (int _y = 0; _y < this->y; _y++)
		{
			for (int _x = 0; _x < this->x; _x++)
			{
				cout << this->coordinate[_y][_x];
			}

			cout << endl;
		}
		cout << "------------------------------" << endl;
		cout << "------------------------------" << endl;
	}

	// Executes Try Again Coordinate when player touched the wall
	if (this->willTryAgain) {
		clearStage();
		Sleep(1500);
		levelManager(this->level);
		this->willTryAgain = false;
		Display();
	}

	// Rendering Delay in milli-seconds
	Sleep(100);
}

void Coordinate::nextLevel() {
	this->level = this->level + 1;
	levelManager(this->level);
}

void Coordinate::clearStage() {
	for (int i = 0; i < this->y; i++) {
		for (int j = 0; j < this->x; j++) {
			this->coordinate[i][j] = "[ ]";
		}
	}
}

void Coordinate::retryLevel() {
	this->willTryAgain = true;
	levelManager(-1);
}

void Coordinate::levelManager(int level) {
	switch (level) {
	case 1:
		this->StageOne();
		break;
	case 2:
		this->StageTwo();
		break;
	case 3:
		this->StageThree();
		break;
	case -1:
		this->StageTryAgain();
		break;
	case -2:
		break;
	default:
		break;
	}
}

void Coordinate::StageOne() {
	this->coordinate[0][2] = "[ ]";
	this->coordinate[0][3] = "[-]";
	this->coordinate[0][4] = "[-]";
	this->coordinate[0][5] = "[-]";
	this->coordinate[0][6] = "[-]";
	this->coordinate[0][7] = "[-]";
	this->coordinate[0][8] = "[-]";
	this->coordinate[0][9] = "[-]";

	this->coordinate[1][1] = "[*]";
	this->coordinate[1][2] = "[ ]";
	this->coordinate[1][3] = "[-]";
	this->coordinate[1][4] = "[-]";
	this->coordinate[1][9] = "[-]";

	this->coordinate[2][3] = "[-]";
	this->coordinate[2][4] = "[-]";
	this->coordinate[2][6] = "[-]";
	this->coordinate[2][7] = "[-]";
	this->coordinate[2][9] = "[-]";

	this->coordinate[3][0] = "[-]";
	this->coordinate[3][1] = "[-]";
	this->coordinate[3][3] = "[-]";
	this->coordinate[3][4] = "[-]";
	this->coordinate[3][6] = "[-]";
	this->coordinate[3][7] = "[-]";
	this->coordinate[3][9] = "[-]";

	this->coordinate[4][0] = "[-]";
	this->coordinate[4][1] = "[-]";
	this->coordinate[4][3] = "[-]";
	this->coordinate[4][4] = "[-]";
	this->coordinate[4][6] = "[-]";
	this->coordinate[4][7] = "[-]";
	this->coordinate[4][9] = "[-]";

	this->coordinate[5][0] = "[-]";
	this->coordinate[5][1] = "[-]";
	this->coordinate[5][3] = "[-]";
	this->coordinate[5][4] = "[-]";
	this->coordinate[5][6] = "[-]";
	this->coordinate[5][7] = "[-]";
	this->coordinate[5][9] = "[-]";

	this->coordinate[6][0] = "[-]";
	this->coordinate[6][1] = "[-]";
	this->coordinate[6][3] = "[-]";
	this->coordinate[6][4] = "[-]";
	this->coordinate[6][6] = "[-]";
	this->coordinate[6][7] = "[-]";
	this->coordinate[6][9] = "[-]";

	this->coordinate[7][0] = "[-]";
	this->coordinate[7][1] = "[-]";
	this->coordinate[7][3] = "[-]";
	this->coordinate[7][4] = "[-]";
	this->coordinate[7][6] = "[-]";
	this->coordinate[7][7] = "[-]";
	this->coordinate[7][9] = "[-]";

	this->coordinate[8][0] = "[-]";
	this->coordinate[8][1] = "[-]";
	this->coordinate[8][6] = "[-]";
	this->coordinate[8][7] = "[-]";
	this->coordinate[8][8] = "[ ]";
	this->coordinate[8][9] = "[-]";

	this->coordinate[9][0] = "[-]";
	this->coordinate[9][1] = "[-]";
	this->coordinate[9][2] = "[-]";
	this->coordinate[9][3] = "[-]";
	this->coordinate[9][4] = "[-]";
	this->coordinate[9][5] = "[-]";
	this->coordinate[9][6] = "[-]";
	this->coordinate[9][7] = "[-]";
	this->coordinate[9][8] = "[ ]";
	this->coordinate[9][9] = "[F]";
}

void Coordinate::StageTwo() {
	this->coordinate[0][0] = "[#]";
	this->coordinate[0][1] = "[#]";
	this->coordinate[0][2] = "[#]";
	this->coordinate[0][3] = "[#]";
	this->coordinate[0][4] = "[#]";
	this->coordinate[0][5] = "[#]";
	this->coordinate[0][6] = "[#]";
	this->coordinate[0][7] = "[#]";
	this->coordinate[0][8] = "[#]";
	this->coordinate[0][9] = "[#]";

	this->coordinate[1][0] = "[#]";
	this->coordinate[1][1] = "[#]";
	this->coordinate[1][2] = "[#]";
	this->coordinate[1][3] = "[#]";
	this->coordinate[1][4] = "[#]";
	this->coordinate[1][5] = "[#]";
	this->coordinate[1][6] = "[#]";
	this->coordinate[1][7] = "[#]";
	this->coordinate[1][8] = "[#]";
	this->coordinate[1][9] = "[#]";

	this->coordinate[2][0] = "[F]";
	this->coordinate[2][1] = "[ ]";
	this->coordinate[2][2] = "[#]";
	this->coordinate[2][3] = "[ ]";
	this->coordinate[2][4] = "[ ]";
	this->coordinate[2][5] = "[ ]";
	this->coordinate[2][6] = "[ ]";
	this->coordinate[2][7] = "[ ]";
	this->coordinate[2][8] = "[ ]";
	this->coordinate[2][9] = "[#]";

	this->coordinate[3][0] = "[#]";
	this->coordinate[3][1] = "[ ]";
	this->coordinate[3][2] = "[#]";
	this->coordinate[3][3] = "[ ]";
	this->coordinate[3][4] = "[#]";
	this->coordinate[3][5] = "[#]";
	this->coordinate[3][6] = "[#]";
	this->coordinate[3][7] = "[#]";
	this->coordinate[3][8] = "[ ]";
	this->coordinate[3][9] = "[#]";

	this->coordinate[4][0] = "[#]";
	this->coordinate[4][1] = "[ ]";
	this->coordinate[4][2] = "[#]";
	this->coordinate[4][3] = "[ ]";
	this->coordinate[4][4] = "[#]";
	this->coordinate[4][5] = "[#]";
	this->coordinate[4][6] = "[#]";
	this->coordinate[4][7] = "[#]";
	this->coordinate[4][8] = "[ ]";
	this->coordinate[4][9] = "[#]";

	this->coordinate[5][0] = "[#]";
	this->coordinate[5][1] = "[ ]";
	this->coordinate[5][2] = "[#]";
	this->coordinate[5][3] = "[ ]";
	this->coordinate[5][4] = "[#]";
	this->coordinate[5][5] = "[#]";
	this->coordinate[5][6] = "[#]";
	this->coordinate[5][7] = "[#]";
	this->coordinate[5][8] = "[ ]";
	this->coordinate[5][9] = "[#]";

	this->coordinate[6][0] = "[#]";
	this->coordinate[6][1] = "[ ]";
	this->coordinate[6][2] = "[#]";
	this->coordinate[6][3] = "[ ]";
	this->coordinate[6][4] = "[ ]";
	this->coordinate[6][5] = "[#]";
	this->coordinate[6][6] = "[ ]";
	this->coordinate[6][7] = "[ ]";
	this->coordinate[6][8] = "[ ]";
	this->coordinate[6][9] = "[#]";

	this->coordinate[7][0] = "[#]";
	this->coordinate[7][1] = "[ ]";
	this->coordinate[7][2] = "[#]";
	this->coordinate[7][3] = "[#]";
	this->coordinate[7][4] = "[ ]";
	this->coordinate[7][5] = "[#]";
	this->coordinate[7][6] = "[ ]";
	this->coordinate[7][7] = "[#]";
	this->coordinate[7][8] = "[#]";
	this->coordinate[7][9] = "[#]";

	this->coordinate[8][0] = "[#]";
	this->coordinate[8][1] = "[ ]";
	this->coordinate[8][2] = "[ ]";
	this->coordinate[8][3] = "[ ]";
	this->coordinate[8][4] = "[ ]";
	this->coordinate[8][5] = "[#]";
	this->coordinate[8][6] = "[ ]";
	this->coordinate[8][7] = "[ ]";
	this->coordinate[8][8] = "[ ]";
	this->coordinate[8][9] = "[ ]";

	this->coordinate[9][0] = "[#]";
	this->coordinate[9][1] = "[#]";
	this->coordinate[9][2] = "[#]";
	this->coordinate[9][3] = "[#]";
	this->coordinate[9][4] = "[#]";
	this->coordinate[9][5] = "[#]";
	this->coordinate[9][6] = "[#]";
	this->coordinate[9][7] = "[#]";
	this->coordinate[9][8] = "[ ]";
	this->coordinate[9][9] = "[*]";
}

void Coordinate::StageThree() {
	this->coordinate[0][0] = "[@]";
	this->coordinate[0][1] = "[@]";
	this->coordinate[0][2] = "[@]";
	this->coordinate[0][3] = "[@]";
	this->coordinate[0][4] = "[@]";
	this->coordinate[0][5] = "[@]";
	this->coordinate[0][6] = "[@]";
	this->coordinate[0][7] = "[ ]";
	this->coordinate[0][8] = "[ ]";
	this->coordinate[0][9] = "[ ]";

	this->coordinate[1][0] = "[ ]";
	this->coordinate[1][1] = "[ ]";
	this->coordinate[1][2] = "[ ]";
	this->coordinate[1][3] = "[ ]";
	this->coordinate[1][4] = "[ ]";
	this->coordinate[1][5] = "[ ]";
	this->coordinate[1][6] = "[@]";
	this->coordinate[1][7] = "[ ]";
	this->coordinate[1][8] = "[ ]";
	this->coordinate[1][9] = "[ ]";

	this->coordinate[2][0] = "[*]";
	this->coordinate[2][1] = "[ ]";
	this->coordinate[2][2] = "[ ]";
	this->coordinate[2][3] = "[@]";
	this->coordinate[2][4] = "[@]";
	this->coordinate[2][5] = "[ ]";
	this->coordinate[2][6] = "[@]";
	this->coordinate[2][7] = "[ ]";
	this->coordinate[2][8] = "[ ]";
	this->coordinate[2][9] = "[ ]";

	this->coordinate[3][0] = "[@]";
	this->coordinate[3][1] = "[@]";
	this->coordinate[3][2] = "[@]";
	this->coordinate[3][3] = "[@]";
	this->coordinate[3][4] = "[ ]";
	this->coordinate[3][5] = "[ ]";
	this->coordinate[3][6] = "[@]";
	this->coordinate[3][7] = "[ ]";
	this->coordinate[3][8] = "[@]";
	this->coordinate[3][9] = "[ ]";

	this->coordinate[4][0] = "[@]";
	this->coordinate[4][1] = "[ ]";
	this->coordinate[4][2] = "[ ]";
	this->coordinate[4][3] = "[ ]";
	this->coordinate[4][4] = "[ ]";
	this->coordinate[4][5] = "[ ]";
	this->coordinate[4][6] = "[@]";
	this->coordinate[4][7] = "[ ]";
	this->coordinate[4][8] = "[@]";
	this->coordinate[4][9] = "[ ]";

	this->coordinate[5][0] = "[@]";
	this->coordinate[5][1] = "[ ]";
	this->coordinate[5][2] = "[@]";
	this->coordinate[5][3] = "[@]";
	this->coordinate[5][4] = "[@]";
	this->coordinate[5][5] = "[@]";
	this->coordinate[5][6] = "[@]";
	this->coordinate[5][7] = "[ ]";
	this->coordinate[5][8] = "[@]";
	this->coordinate[5][9] = "[ ]";

	this->coordinate[6][0] = "[@]";
	this->coordinate[6][1] = "[ ]";
	this->coordinate[6][2] = "[@]";
	this->coordinate[6][3] = "[@]";
	this->coordinate[6][4] = "[@]";
	this->coordinate[6][5] = "[ ]";
	this->coordinate[6][6] = "[ ]";
	this->coordinate[6][7] = "[ ]";
	this->coordinate[6][8] = "[@]";
	this->coordinate[6][9] = "[ ]";

	this->coordinate[7][0] = "[@]";
	this->coordinate[7][1] = "[ ]";
	this->coordinate[7][2] = "[ ]";
	this->coordinate[7][3] = "[ ]";
	this->coordinate[7][4] = "[ ]";
	this->coordinate[7][5] = "[ ]";
	this->coordinate[7][6] = "[@]";
	this->coordinate[7][7] = "[@]";
	this->coordinate[7][8] = "[@]";
	this->coordinate[7][9] = "[ ]";

	this->coordinate[8][0] = "[@]";
	this->coordinate[8][1] = "[@]";
	this->coordinate[8][2] = "[@]";
	this->coordinate[8][3] = "[@]";
	this->coordinate[8][4] = "[@]";
	this->coordinate[8][5] = "[@]";
	this->coordinate[8][6] = "[@]";
	this->coordinate[8][7] = "[@]";
	this->coordinate[8][8] = "[@]";
	this->coordinate[8][9] = "[ ]";

	this->coordinate[9][0] = "[F]";
	this->coordinate[9][1] = "[ ]";
	this->coordinate[9][2] = "[ ]";
	this->coordinate[9][3] = "[ ]";
	this->coordinate[9][4] = "[ ]";
	this->coordinate[9][5] = "[ ]";
	this->coordinate[9][6] = "[ ]";
	this->coordinate[9][7] = "[ ]";
	this->coordinate[9][8] = "[ ]";
	this->coordinate[9][9] = "[ ]";
}

void Coordinate::StageTryAgain() {

	switch (getCurrentLevel())
	{

	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

	for (int i = 0; i < this->y; i++) {
		for (int j = 0; j < this->x; j++) {
			switch (getCurrentLevel())
			{
			case 1:
				this->coordinate[i][j] = "[-]";
				break;
			case 2:
				this->coordinate[i][j] = "[#]";
				break;
			case 3:
				this->coordinate[i][j] = "[@]";
				break;
			default:
				break;
			}
		}
	}
}

/*
class Coordinate {

private:
	// 2D Coodinate with pointers of pointers
	string** coordinate;

	// Intial Coordinate's size if there's no explicit value provided
	int x = 1, y = 1;

	// Stage Level starts at one and increments when the user got to [F] finish point
	int level{1};

	boolean willTryAgain = false;

	void Init() {

		for (int i = 0; i < y; i++)
		{
			this->coordinate[i] = new string[this->x];
		}

		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) {
				this->coordinate[i][j] = "[ ]";
			}
		}
	}

public:
	Coordinate(int _x = 10, int _y = 10): x(_x), y(_y), coordinate(new string* [this->x])
	{
		Init();
		StageOne();
	}

	string** getCoordinate() {
		return coordinate;
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->x;
	}

	void Display() {

		// Clear the console screen (specific to windows OS)
		system("cls");
		cout << "Stage Level: " << to_string(this->level) << endl;

		// Render the Stage Coordinate
		for (int i = 0; i < this->y; i++)
		{
			for (int j = 0; j < this->x; j++)
			{

				cout << this->coordinate[i][j];
			}

			cout << endl;
		}

		// Executes Try Again Coordinate when player touched the wall
		if (this->willTryAgain) {
			clearStage();
			Sleep(1500);
			levelManager(this->level);
			this->willTryAgain = false;
			Display();
		}

		// Rendering Delay in milli-seconds
		Sleep(250);
	}

	void nextLevel() {

		this->level = this->level + 1;
		levelManager(this->level);
	}

	void clearStage() {

		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) {
				this->coordinate[i][j] = "[ ]";
			}
		}
	}

	void retryLevel() {
		this->willTryAgain = true;
		levelManager(-1);
	}

	void levelManager(int level) {
		switch (level) {
			case 1:
				this->StageOne();
				break;
			case 2:
				this->StageTwo();
				break;
			case 3:
				this->StageThree();
				break;
			case -1:
				this->StageTryAgain();
				break;
			case -2:
				break;
			default:
				break;
			}
	}

	void StageOne(){

		this->coordinate[0][2] = "[-]";
		this->coordinate[0][3] = "[-]";
		this->coordinate[0][4] = "[-]";
		this->coordinate[0][5] = "[-]";
		this->coordinate[0][6] = "[-]";
		this->coordinate[0][7] = "[-]";
		this->coordinate[0][8] = "[-]";
		this->coordinate[0][9] = "[-]";

		this->coordinate[1][2] = "[-]";
		this->coordinate[1][3] = "[-]";
		this->coordinate[1][4] = "[-]";
		this->coordinate[1][9] = "[-]";

		this->coordinate[2][3] = "[-]";
		this->coordinate[2][4] = "[-]";
		this->coordinate[2][6] = "[-]";
		this->coordinate[2][7] = "[-]";
		this->coordinate[2][9] = "[-]";

		this->coordinate[3][0] = "[-]";
		this->coordinate[3][1] = "[-]";
		this->coordinate[3][3] = "[-]";
		this->coordinate[3][4] = "[-]";
		this->coordinate[3][6] = "[-]";
		this->coordinate[3][7] = "[-]";
		this->coordinate[3][9] = "[-]";

		this->coordinate[4][0] = "[-]";
		this->coordinate[4][1] = "[-]";
		this->coordinate[4][3] = "[-]";
		this->coordinate[4][4] = "[-]";
		this->coordinate[4][6] = "[-]";
		this->coordinate[4][7] = "[-]";
		this->coordinate[4][9] = "[-]";

		this->coordinate[5][0] = "[-]";
		this->coordinate[5][1] = "[-]";
		this->coordinate[5][3] = "[-]";
		this->coordinate[5][4] = "[-]";
		this->coordinate[5][6] = "[-]";
		this->coordinate[5][7] = "[-]";
		this->coordinate[5][9] = "[-]";

		this->coordinate[6][0] = "[-]";
		this->coordinate[6][1] = "[-]";
		this->coordinate[6][3] = "[-]";
		this->coordinate[6][4] = "[-]";
		this->coordinate[6][6] = "[-]";
		this->coordinate[6][7] = "[-]";
		this->coordinate[6][9] = "[-]";

		this->coordinate[7][0] = "[-]";
		this->coordinate[7][1] = "[-]";
		this->coordinate[7][3] = "[-]";
		this->coordinate[7][4] = "[-]";
		this->coordinate[7][6] = "[-]";
		this->coordinate[7][7] = "[-]";
		this->coordinate[7][9] = "[F]";

		this->coordinate[8][0] = "[-]";
		this->coordinate[8][1] = "[-]";
		this->coordinate[8][6] = "[-]";
		this->coordinate[8][7] = "[-]";
		this->coordinate[8][8] = "[-]";
		this->coordinate[8][9] = "[-]";

		this->coordinate[9][0] = "[-]";
		this->coordinate[9][1] = "[-]";
		this->coordinate[9][2] = "[-]";
		this->coordinate[9][3] = "[-]";
		this->coordinate[9][4] = "[-]";
		this->coordinate[9][5] = "[-]";
		this->coordinate[9][6] = "[-]";
		this->coordinate[9][7] = "[-]";
		this->coordinate[9][8] = "[-]";
		this->coordinate[9][9] = "[-]";

	}

	void StageTwo(){

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				this->coordinate[i][j] = "[ ]";
			}
		}

	}

	void StageThree() {

	}

	void StageTryAgain() {
		this->coordinate[0][0] = "[ ]";
		this->coordinate[0][1] = "[ ]";
		this->coordinate[0][2] = "[ ]";
		this->coordinate[0][3] = "[ ]";
		this->coordinate[0][4] = "[ ]";
		this->coordinate[0][5] = "[ ]";
		this->coordinate[0][6] = "[ ]";
		this->coordinate[0][7] = "[ ]";
		this->coordinate[0][8] = "[ ]";
		this->coordinate[0][9] = "[ ]";
		this->coordinate[1][0] = "[-]";
		this->coordinate[1][1] = "[-]";
		this->coordinate[1][2] = "[-]";
		this->coordinate[1][3] = "[-]";
		this->coordinate[1][4] = "[-]";
		this->coordinate[1][5] = "[-]";
		this->coordinate[1][6] = "[-]";
		this->coordinate[1][7] = "[-]";
		this->coordinate[1][8] = "[-]";
		this->coordinate[1][9] = "[ ]";
		this->coordinate[2][0] = "[-]";
		this->coordinate[2][1] = "[-]";
		this->coordinate[2][2] = "[-]";
		this->coordinate[2][3] = "[-]";
		this->coordinate[2][4] = "[-]";
		this->coordinate[2][5] = "[-]";
		this->coordinate[2][6] = "[-]";
		this->coordinate[2][7] = "[-]";
		this->coordinate[2][8] = "[-]";
		this->coordinate[2][9] = "[ ]";
		this->coordinate[3][0] = "[ ]";
		this->coordinate[3][1] = "[ ]";
		this->coordinate[3][2] = "[-]";
		this->coordinate[3][3] = "[-]";
		this->coordinate[3][4] = "[ ]";
		this->coordinate[3][5] = "[-]";
		this->coordinate[3][6] = "[-]";
		this->coordinate[3][7] = "[ ]";
		this->coordinate[3][8] = "[ ]";
		this->coordinate[3][9] = "[ ]";
		this->coordinate[4][0] = "[ ]";
		this->coordinate[4][1] = "[ ]";
		this->coordinate[4][2] = "[-]";
		this->coordinate[4][3] = "[-]";
		this->coordinate[4][4] = "[ ]";
		this->coordinate[4][5] = "[-]";
		this->coordinate[4][6] = "[-]";
		this->coordinate[4][7] = "[ ]";
		this->coordinate[4][8] = "[-]";
		this->coordinate[4][9] = "[-]";
		this->coordinate[5][0] = "[ ]";
		this->coordinate[5][1] = "[ ]";
		this->coordinate[5][2] = "[-]";
		this->coordinate[5][3] = "[-]";
		this->coordinate[5][4] = "[ ]";
		this->coordinate[5][5] = "[-]";
		this->coordinate[5][6] = "[-]";
		this->coordinate[5][7] = "[ ]";
		this->coordinate[5][8] = "[-]";
		this->coordinate[5][9] = "[-]";
		this->coordinate[6][0] = "[ ]";
		this->coordinate[6][1] = "[ ]";
		this->coordinate[6][2] = "[-]";
		this->coordinate[6][3] = "[-]";
		this->coordinate[6][4] = "[ ]";
		this->coordinate[6][5] = "[-]";
		this->coordinate[6][6] = "[-]";
		this->coordinate[6][7] = "[ ]";
		this->coordinate[6][8] = "[ ]";
		this->coordinate[6][9] = "[-]";
		this->coordinate[7][0] = "[ ]";
		this->coordinate[7][1] = "[ ]";
		this->coordinate[7][2] = "[-]";
		this->coordinate[7][3] = "[-]";
		this->coordinate[7][4] = "[ ]";
		this->coordinate[7][5] = "[-]";
		this->coordinate[7][6] = "[-]";
		this->coordinate[7][7] = "[-]";
		this->coordinate[7][8] = "[-]";
		this->coordinate[7][9] = "[-]";
		this->coordinate[8][0] = "[ ]";
		this->coordinate[8][1] = "[ ]";
		this->coordinate[8][2] = "[-]";
		this->coordinate[8][3] = "[-]";
		this->coordinate[8][4] = "[ ]";
		this->coordinate[8][5] = "[-]";
		this->coordinate[8][6] = "[-]";
		this->coordinate[8][7] = "[-]";
		this->coordinate[8][8] = "[-]";
		this->coordinate[8][9] = "[-]";
		this->coordinate[9][0] = "[ ]";
		this->coordinate[9][1] = "[ ]";
		this->coordinate[9][2] = "[ ]";
		this->coordinate[9][3] = "[ ]";
		this->coordinate[9][4] = "[ ]";
		this->coordinate[9][5] = "[ ]";
		this->coordinate[9][6] = "[ ]";
		this->coordinate[9][7] = "[ ]";
		this->coordinate[9][8] = "[ ]";
		this->coordinate[9][9] = "[ ]";

	}

};


*/