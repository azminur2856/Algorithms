// Sorting Algorithms with Time Measurement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int point = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[point]) {
                point = j;
            }
        }
        if (point != i) {
			swap(arr[point], arr[i]);
		}
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 23, 45, 12, 9, 56, 34, 87, 61, 5, 32, 78, 6, 89, 18, 67 };
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start_time, end_time;

    start_time = clock();
    selectionSort(arr, n);
    end_time = clock();
    double selectionSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    int resetArr[] = { 23, 45, 12, 9, 56, 34, 87, 61, 5, 32, 78, 6, 89, 18, 67 };

    start_time = clock();
    insertionSort(resetArr, n);
    end_time = clock();
    double insertionSortTime = double(end_time - start_time) / CLOCKS_PER_SEC;

    int resetArr2[] = { 23, 45, 12, 9, 56, 34, 87, 61, 5, 32, 78, 6, 89, 18, 67 };

    start_time = clock();
    bubbleSort(resetArr2, n);
    end_time = clock();
    double bubbleSortTime    = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Selection Sort Execution Time: " << selectionSortTime << " seconds" << endl;
    cout << "Insertion Sort Execution Time: " << insertionSortTime << " seconds" << endl;
    cout << "Bubble Sort Execution Time   : " << bubbleSortTime    << " seconds" << endl;

    if (selectionSortTime > insertionSortTime && selectionSortTime > bubbleSortTime) {
        cout << "Selection Sort has the highest execution time." << endl;
    }
    else if (insertionSortTime > selectionSortTime && insertionSortTime > bubbleSortTime) {
        cout << "Insertion Sort has the highest execution time." << endl;
    }
    else {
        cout << "Bubble Sort has the highest execution time."    << endl;
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
