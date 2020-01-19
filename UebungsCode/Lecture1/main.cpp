#include <iostream>
#include <chrono>

void function()
{
	long long number = 0;

	for (long long i = 0; i != 2000000; ++i)
	{
		number += 5;
	}
}

int main(void)
{
	long long average = 0;

	for (int i = 0; i < 10; i++)
	{
		auto t1 = std::chrono::high_resolution_clock::now();
		// insert your code here
		function();
		//
		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		std::cout << "Run " << i+1 << " took " << duration << "ms" << std::endl;

		average += duration;
	}

	std::cout << "Average: " << average / 10 << "ms" << std::endl;

	return 0;
}