#include <chrono>
#include <iostream>

constexpr int64_t UpperLimit = 2000000;
constexpr int StepSize = 5;
constexpr int Runs = 10;


auto ReallyIntenseWork() -> int64_t
{
	int64_t number = 0;

	for (int64_t i = 0; i != UpperLimit; ++i)
	{
		number += StepSize;
	}

	return number;
}

int main()
{
	//omp_set_num_threads(4);
	int64_t average = 0;
	int64_t value = 0;
	for (int i = 0; i < Runs; i++)
	{
		auto t1 = std::chrono::high_resolution_clock::now();

		value = ReallyIntenseWork();
		
		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		std::cout << "Run " << i+1 << " took " << duration << "ms" << ". And we added numbers up to " << value << std::endl;

		average += duration;
	}

	std::cout << "Average: " << average / Runs << "ms" << std::endl;

	return 0;
}