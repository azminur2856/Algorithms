// 01knapsack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*int knapsack(int Weight[], int Profit[], int n, int TotalWeight) {
	
	int Table[n + 1][TotalWeight + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= TotalWeight; j++) {
			if (i == 0 || j == 0)
				Table[i][j] = 0;
			else if (Weight[i - 1] <= j)
				Table[i][j] = max(Profit[i - 1] + Table[i - 1][j - Weight[i - 1]], Table[i - 1][j]);
			else
				Table[i][j] = Table[i - 1][j];
		}
	}
	return Table[n][TotalWeight];
}*/

//1st method for kanpsack is showing error in visual studio for Table Arry. So i have used 2nd method. But 1st method is correct and runable.

int knapsack(int Weight[], int Profit[], int n, int TotalWeight)
{
	if (n == 0 || TotalWeight == 0)
		return 0;

	if (Weight[n - 1] <= TotalWeight)
	{
		return max(Profit[n - 1] + knapsack(Weight, Profit, n - 1, TotalWeight - Weight[n - 1]), knapsack(Weight, Profit, n - 1, TotalWeight));
	}
	else
	{
		return knapsack(Weight, Profit, n - 1, TotalWeight);
	}
}

int main()
{
	int Weight[] = { 1, 3, 4, 5 };
	int Profit[] = { 1, 4, 5, 7 };
	int TotalWeight = 7;
	int n = sizeof(Weight) / sizeof(Weight[0]);
	cout << "Maximum Profit : " << knapsack(Weight, Profit, n, TotalWeight);
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
