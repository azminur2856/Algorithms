#include<iostream>
using namespace std;



void SelectionShort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int point = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[point])
            {
                point = j;
            }
            if(point > i)
            {
                swap(arr[point], arr[i]);
            }

        }
    }
}


int main(){
    int arr[] = {9,13,15,11,2,4,2,3,2};
    int n = 9;

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    SelectionShort(arr,n);

    cout << "Sorted array  : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
