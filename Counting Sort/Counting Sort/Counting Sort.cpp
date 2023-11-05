// Counting Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int R = max - min + 1;

    int count[100];

    for (int i = 0; i < R; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < R; i++) {
        count[i] += count[i - 1];
    }

    int output[100];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = { 0, 3, 1, 5, 7, 9, 6, 9, 0, 4, 3, 0, 2, 8, 8, 9, 3, 4, 6, 5 };

    int n = sizeof(array) / sizeof(array[0]);

    cout << "UnSorted Array: ";
    printArray(array, n);

    countingSort(array, n);

    cout << "Sorted Array  : ";
    printArray(array, n);

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
