/*
 Name: Caleb Keller
 Class: CS317-02
 Assignment: Programming Assignment #2
 Program Name: NQueens
 Due Date: 04/13/2022
 Program Description: find an arrangement of 'N' queens on a chessboard (matrix)
 such that no queen can attack other queens (based on user input size 'N')
*/

#include<iostream>

using namespace std;

bool goodSpot(int** array, int i, int j, int n); // function to check if queen is in a safe spot
bool NQUEEN(int** array, int i, int n); // algorithm to perform solution based on user inputted size 

int main()
{
	int n; // number of queens
	int solNum = 0; // number of solutions

	cout << "Please enter the number of Queens (1-9): ";
	cin >> n;
	cout << endl;

	int** array = new int* [n]; // dynamic allocation to use 2D user defined array

	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n]; // assigning size
		for (int j = 0; j < n; j++)
		{
			array[i][j] = 0; // space = 0
		}
	}
	if (n == 1 || n == 2 || n == 3) // hard code for n values with no solutions
	{
		cout << "The solution does not exist for N = " << n << endl << endl;
		system("PAUSE");
		exit(1); // exit the program 
	}

	if(NQUEEN(array, 0, n)) // beginning solution output
	{
		cout << "N = " << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << array[i][j] << " "; // printing solution 
			}
			cout << endl;
		}
		// number of solutions for n = 4....9
		if (n == 4)
		{
			solNum = 2;
		}
		if (n == 5)
		{
			solNum = 10;
		}
		if (n == 6)
		{
			solNum = 4;
		}
		if (n == 7)
		{
			solNum = 40;
		}
		if (n == 8)
		{
			solNum = 92;
		}
		if (n == 9)
		{
			solNum = 352;
		}

		cout << endl << "The solution for N = " << n << " can produce " << solNum << " different solutions. " << endl << endl;

		system("PAUSE");
	}
}

bool goodSpot(int** array, int i, int j, int n) // determines if queens are safe throughout chessboard
{
	int row;
	int col;

	for (int row = 0; row < i; row++) // checking for multiple queens across same column
	{
		if (array[row][j] == 1) 
		{
			return false;
		}
	}
	row = i;
	col = j;


	// searching through 

	while (row >= 0 && col >= 0) // checking for multiple queens across diagonal (\)
	{
		if (array[row][col] == 1)
		{
			return false;
		}
		else
		{
			row--; // back
			col--; // back
		}
	}
	row = i;
	col = j;

	//searching through

	while (row >= 0 && col < n) // checking for multiple queens across other diagonal (/)
	{
		if (array[row][col] == 1)
		{
			return false;
		}
		else
		{
			row--; // back
			col++; // forward
		}
	}
	return true;
}

bool NQUEEN(int** array, int i, int n) // locates queens and creates solutions
{
	if (i >= n)
	{
		return true; // safe return true
	}
	for (int col = 0; col < n; col++)
	{
		if (goodSpot(array, i, col, n)) // if no queens are capable of attacking
		{
			array[i][col] = 1;

			if (NQUEEN(array, i + 1, n))
			{
				return true;
			}
			array[i][col] = 0;

		}
	}
	return false; 
}