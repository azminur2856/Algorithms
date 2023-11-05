#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int v = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = v;
    }
}

int main() {
    int arr[] = {43, 31, 26, 29, 12};
    int n = 5;

    insertionSort(arr, n);

    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

