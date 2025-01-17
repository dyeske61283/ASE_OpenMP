#pragma once

#include "Cell.h"
#include <iostream>
#include <vector>
// Credits go to Daniel Shiffman
// http://natureofcode.com

class GameOfLife {

private:
	constexpr static int w = 10;
	int columns, rows;
	std::vector<std::vector<Cell>> board;

public:

	GameOfLife() {
		columns = w;
		rows = w;
		for (int i = 0; i < w; i++) {
			board.push_back(std::vector<Cell>());
			for (int j = 0; j < w; j++) {
				board[i].push_back(Cell(i, j));
			}
		}
	}

	void generate() {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				board[i][j].savePrevious();
			}
		}
		// Loop through every spot in our 2D array and check spots neighbors
			for (int x = 0; x < columns; x++) {
				for (int y = 0; y < rows; y++) {

					// Add up all the states in a 3x3 surrounding grid
					int neighbors = 0;
					for (int i = -1; i <= 1; i++) {
						for (int j = -1; j <= 1; j++) {
							neighbors += board[(x + i + columns) % columns][(y + j + rows) % rows].previous;
						}
					}

					// A little trick to subtract the current cell's state since
					// we added it in the above loop
					neighbors -= board[x][y].previous;

					// Rules of Life
					if ((board[x][y].state == 1) && (neighbors < 2)) board[x][y].newState(0);           // Loneliness
					else if ((board[x][y].state == 1) && (neighbors > 3)) board[x][y].newState(0);           // Overpopulation
					else if ((board[x][y].state == 0) && (neighbors == 3)) board[x][y].newState(1);           // Reproduction
					// else do nothing!
				}
			}
	}

	// This is the easy part
	void display() {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				std::cout << board[i][j].toString() << " ";
			}
			std::cout << std::endl;
		}
	}
};