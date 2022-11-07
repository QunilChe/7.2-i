// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMaxEven(int** a, const int n, int& minEven);
bool SearchMinEven(int** a, const int n, int& minEven);

int SearchMaxi(int** a, const int n, int& minEven);
int SearchMini(int** a, const int n, int& minEven);
int SearchMaxj(int** a, const int n, int& minEven);
int SearchMinj(int** a, const int n, int& minEven);

void swapMaxMin(int** a,  int maxI, int minI, int maxJ, int minJ);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -6;
	int High = 23;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int minEven, max, mininEven;
	SearchMaxEven(a, n, minEven);
	SearchMinEven(a, n, mininEven);
	SearchMaxi(a, n, minEven);
	SearchMini(a, n, mininEven);
	int maxI = SearchMaxi(a, n, minEven);
	int minI = SearchMini(a, n, mininEven);
	int maxJ = SearchMaxj(a, n, minEven);
	int minJ = SearchMinj(a, n, mininEven);
	swapMaxMin(a,  maxI, minI, maxJ, minJ);
	cout << "max even = " << minEven << endl;
	cout << "min even = " << mininEven << endl;
	Print(a, n);
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool SearchMaxEven(int** a, const int n, int& minEven)
{
	int max;
	max = a[0][1];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] > max) max = a[i][j], minEven = a[i][j];	
	return true;
}
int SearchMaxi(int** a, const int n, int& minEven)
{
	int max;
	int maxI{};
	max = a[0][1];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] > max) max = a[i][j], maxI = i;
	return maxI;
}
int SearchMaxj(int** a, const int n, int& minEven)
{
	int max;
	int maxJ{};
	max = a[0][1];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] > max) max = a[i][j], maxJ = j;
	return maxJ;
}
bool SearchMinEven(int** a, const int n, int& mininEven)
{
	int min;
	min = a[0][1];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[i][j] < min) min = a[i][j], mininEven = a[i][j];

	//cout << "min in = " << min << endl;
	return true;
}
int SearchMini(int** a, const int n, int& mininEven)
{
	int min;
	int minI{};
	min = a[0][1];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[i][j] < min) min = a[i][j], minI = i;
	return minI;
}
int SearchMinj(int** a, const int n, int& mininEven)
{
	int max;
	int minJ{};
	max = a[0][1];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] > max) max = a[i][j], minJ = j;
	return minJ;
}
void swapMaxMin(int** a, int maxI, int minI, int maxJ, int minJ)
{
	int tmp = a[maxI][maxJ];
	a[maxI][maxJ] = a[minI][minJ];
	a[minI][minJ] = tmp;
}
