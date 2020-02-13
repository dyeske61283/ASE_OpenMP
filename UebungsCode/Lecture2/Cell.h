#pragma once

#include <random>
#include <string>
#include <time.h>
// Credits go to Daniel Shiffman
// http://natureofcode.com

class Cell {

public:
	int x, y;

	int state;
	int previous;

	Cell(int x_, int y_) {
		x = x_;
		y = y_;
		state = rand() % 2;
		previous = state;
	}

	Cell() : x(0), y(0) {
		state = rand() % 2;
		previous = state;
	}

	void savePrevious() {
		previous = state;
	}

	void newState(int s) {
		state = s;
	}

	std::string toString() {
		return std::to_string(state);
	}
};