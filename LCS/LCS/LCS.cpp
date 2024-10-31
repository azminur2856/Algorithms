// LCS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int LCS(int A[], int B[], int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	if (A[a - 1] == B[b - 1])
		return 1 + LCS(A, B, a - 1, b - 1);
	else
		return max(LCS(A, B, a - 1, b), LCS(A, B, a, b - 1));
}

int main()
{
    int A1[] = { 2, 1, 7, 3, 5, 4, 8, 9, 3, 6 };
    int Profits[] = { 1, 3, 5, 2, 4, 3, 6, 7, 8, 9 };
	int size_A1 = sizeof(A1) / sizeof(A1[0]);
	int size_Profits = sizeof(Profits) / sizeof(Profits[0]);
	cout << "The Longest Common Subsequence(LCS) is:" << LCS(A1, Profits, size_A1, size_Profits) << endl;
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
