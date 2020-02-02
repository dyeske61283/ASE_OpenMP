#include <chrono>
#include "GameOfLife.h"
#include <iostream>

constexpr int Runs = 10;

int main()
{
	//omp_set_num_threads(4);
	int64_t average = 0;
	GameOfLife gol;

	for (int i = 0; i < Runs; i++)
	{
		auto t1 = std::chrono::high_resolution_clock::now();

		//Your Code is here
		//Let's do a 100 generations of the game of life
		for (int j = 0; j < 100; j++) {
			gol.generate();
			gol.display();
		}

		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		std::cout << "Run " << i + 1 << " took " << duration << "ms" << std::endl;

		average += duration;
	}

	std::cout << "Average: " << average / Runs << "ms" << std::endl;

	return 0;
}