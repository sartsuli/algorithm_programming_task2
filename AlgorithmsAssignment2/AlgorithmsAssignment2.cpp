#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

//ARRAYS
int array[20] = { 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };
int* bigArray = new int[100000];
int* biggerArray = new int[1000000];
int* biggestArray = new int[10000000];

//***FUNCTIONS***
/// <summary>
/// Find index of a wanted int in an array using linear search
/// </summary>
/// <param name="a">Array</param>
/// <param name="n">The size of the array</param>
/// <param name="x">Wanted int</param>
/// <returns>Index of the wanted int. returns -1 if it can't be found</returns>
int LinearSearch(int* a, int n, int x) {

	for (int i = 0; i < n; i++) {

		if (a[i] == x) return i;
	}
	return -1;
}
void InitializeArrayWithAscendingData(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

/// <summary>
/// For randomizing an integer that will be searched
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>an int between min and max values</returns>
int GetRandomInt(int min, int max) {
	return min + rand() % (max - min + 1);
}
/// <summary>
/// Find index of a wanted int in an array using binary search
/// </summary>
/// <param name="a">array</param>
/// <param name="n">size of the array</param>
/// <param name="x">wanted int</param>
/// <returns>Index of the wanted int. -1 if it can't be found</returns>
int BinarySearch(int* array, int n, int x) {

	int start = 0;
	int end = n - 1;
	int mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (array[mid] == x) return mid;

		if (array[mid] > x) end = mid - 1; //search in lower half

		else start = mid + 1; //search in higher half

	}

	 return -1;
}
int main()
{
	srand(time(NULL));

	int x; //Int that we are trying to find
	int index; // Index of where x is
	int amountOfRuns = 20;

	//Initialize the big arrays
	InitializeArrayWithAscendingData(bigArray, 100000);
	InitializeArrayWithAscendingData(biggerArray, 1000000);
	InitializeArrayWithAscendingData(biggestArray, 10000000);

	std::cout << "---Linear search---" << std::endl;

	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < amountOfRuns; i++) 
	{
		x = GetRandomInt(0, 100000); //Randomize an int that the algorithm will try to find
		index = LinearSearch(bigArray, 100000, x);

		//Print the results
		std::cout << "Run " << i << ": ";
		if (index != -1) {
			std::cout << x << " found at index " << index << "." << std::endl;
		}
		else std::cout << x << " not found!" << std::endl;
	}
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Total time taken: " << elapsed.count() << " micro seconds" << std::endl;

	std::cout << "---Binary search---" << std::endl;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < amountOfRuns; i++) {

		x = GetRandomInt(0, 100000); //Randomize an int that the algorithm will try to find
		index = BinarySearch(bigArray, 100000, x);

		//Print the results
		std::cout << "Run " << i << ": ";
		if (index != -1) {
			std::cout << x << " found at index: " << index << std::endl;
		}
		else std::cout << x << " not found!" << std::endl;

	}
	end = std::chrono::steady_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Total time taken: " << elapsed.count() << " micro seconds" << std::endl;

}


 