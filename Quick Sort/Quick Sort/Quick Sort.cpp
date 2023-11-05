// Quick Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // pivot
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = pivot;
	arr[high] = temp;

	return i +1; // return the index of pivot
}


void quickSort(int arr[], int low, int high) {
	if (low < high)
	{
		int pivortIndex = partition(arr, low, high);

		quickSort(arr, low, pivortIndex - 1); // Before pi
		quickSort(arr, pivortIndex + 1, high); // After pi
	}
}


int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 , 54, 43, 5787, 55, 5, 5, 5, 5, 7646, 3756, 226, 123, 64556, 657678, 4522,7647578,34224355 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++) {
		cout<< "\n" << i << " " << arr[i] << " ";
	}
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
