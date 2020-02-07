#include <iostream>
#include <chrono>
using namespace std;
#define LENGTH 100000
int arr[LENGTH];
constexpr int Runs = 10;

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* last element as pivot, places pivot correct position in sorted array, places all smaller to left of pivot,all greater elements to right of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort arr[] --> Array to be sorted, low --> Starting index, high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition
		quickSort(arr, low, pi - 1);

		quickSort(arr, pi + 1, high);

		
		
	}
}


// Driver Code 
int main()
{
	int64_t average = 0;
	for (int i = 0; i < Runs; i++)
	{
		

		for (int i = 0;i < LENGTH;i++) {
			arr[i] = rand() % LENGTH;//filling random value
		}
		auto t1 = std::chrono::high_resolution_clock::now();
		int j = partition(arr, 0, LENGTH - 1);// returns the pivot element
//#pragma omp parallel sections
//		{
//#pragma omp section
//			{
				quickSort(arr, 0, j - 1);//Thread 1
			//}
//#pragma omp section
			//{
				quickSort(arr, j + 1, LENGTH - 1);//Thread 2
			//}
		//}
		
		//quickSort(arr, 0, LENGTH - 1);

		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		
		std::cout << "Run " << i + 1 << " took " << duration << "ms" << ". Sorted Array of Length " << LENGTH << std::endl;
		
		average += duration;
	}
	std::cout << "Average: " << average / Runs << "ms" << std::endl;
	return 0;
}