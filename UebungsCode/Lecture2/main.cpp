#include <chrono>
#include "GameOfLife.h"
#include <iostream>
#include <time.h>

constexpr int Runs = 10;

int main()
{
	srand(time(NULL));
	int64_t average = 0;
	GameOfLife gol;

	for (int i = 0; i < Runs; i++)
	{
		auto t1 = std::chrono::high_resolution_clock::now();

		//Your Code goes here

		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		std::cout << "Run " << i + 1 << " took " << duration << "ms" << std::endl;

		average += duration;
	}

	std::cout << "Average: " << average / Runs << "ms" << std::endl;

	return 0;
}