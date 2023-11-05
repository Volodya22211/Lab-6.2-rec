#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

void printArray(int* arr, int size, int i);
void generateArray(int* arr, int size, int min, int max, int i);
int findSmallestIndex(const int* arr, int size, int i, int SmallestIndex, int SmallestNum);
int main() {
	srand(unsigned(time(NULL)));
	const int arrSize = 10;
	int a[arrSize];
	generateArray(a, arrSize, -10, 10, 0);

	cout << "originalArray: ";
	printArray(a, arrSize, 0);


	int sm = findSmallestIndex(a, arrSize, 0, -1, INT_MAX);
	cout << "SmallestIndex:  " << sm;
}

void generateArray(int* arr, int size, int min, int max, int i) {
	
	if (i < size) {
		arr[i] = min + rand() % (max - min + 1);
		generateArray(arr, size, min, max, i + 1);
	}
}

void printArray(int* array, int size, int i) {
	cout << setw(4) << array[i] << " ";
	if (i < size - 1)
		printArray(array, size, i + 1);
	if (i == size - 1)
		cout << endl;
}


int findSmallestIndex(const int* arr, int size, int i, int SmallestIndex, int SmallestNum) {

	if (i < size) {
		if (!(arr[i] % 2 == 0) && arr[i] < SmallestNum) {
			SmallestIndex = i;
			SmallestNum = arr[i];
		}

		return findSmallestIndex(arr, size, i + 1, SmallestIndex, SmallestNum);
	}

	else return SmallestIndex;
}
