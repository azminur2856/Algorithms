// Implement a binary search algorithm C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

void FoundNotFound(int search, int key) {
	if (search != -1) {
		cout <<"\nKey " << key << " found at index: " << search << endl;
	}
	else {
		cout << "\nKey " << key << " Not found." << endl;
	}
}

void RangeGraterThanOrEqual(int arr[], int size, int key) {
	int lowerBound = binarySearch(arr, size, key);

	if (lowerBound == -1) {
		cout << "\nKey " << key << " not found, so no range found for elements >= " << key << "." << endl;
	}
	else {
		int upperBound = size - 1;
		cout << "\nRange of elements >= " << key << ": [" << lowerBound << ", " << upperBound << "]" << endl;
	}
}

void RangeLessThanOrEqual(int arr[], int size, int key) {
	int upperBound = binarySearch(arr, size, key);

	if (upperBound == -1) {
		cout << "\nKey " << key << " not found, so no range found for elements >= " << key << "." << endl;
	}
	else {
		int lowerBound = size - size;
		cout << "\nRange of elements <= " << key << ": [" << lowerBound << ", " << upperBound << "]" << endl;
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key0 = 17;
	int key1 = 37;
	int key2 = 42;

	int search0 = binarySearch(arr, size, key0);
	FoundNotFound(search0, key0);

	int search1 = binarySearch(arr, size, key1);
	FoundNotFound(search1, key1);

	int search2 = binarySearch(arr, size, key2);
	FoundNotFound(search2, key2);

	RangeGraterThanOrEqual(arr, size, key0);
	RangeLessThanOrEqual(arr, size, key1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
