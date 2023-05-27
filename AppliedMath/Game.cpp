#pragma once
#include "Game.h"

Game::Game() : player{ *(new Player(*(new Coordinate(10, 10)))) } {}

void Game::start() {

	cout << "Press anykey in WASD to start" << endl;

	while (true) {
		this->player.movement();
	}

	cout << "Program has ended." << endl;
}