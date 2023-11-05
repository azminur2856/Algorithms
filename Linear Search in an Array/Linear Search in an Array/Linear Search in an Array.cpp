// Linear Search in an Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
int n = sizeof(arr);

int linearSearch(int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}
int main()
{
	int key;
	cout << "Enter the element to search: ";
	cin >> key;
	int index = linearSearch(arr, n, key);
	if (index == -1) {
		cout << key <<" not found" << endl;
	}
	else {
		cout << key << " found at index : " << index << endl;
	}
	return 0;
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
