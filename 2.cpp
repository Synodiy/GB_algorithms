/*
2. –ешить задачу о нахождении длины максимальной последовательности с помощью матрицы.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char** args)
{
	const int lenght1 = 7;
	const int lenght2 = 8;
	int arr[lenght1][lenght2];
	int string1[lenght1], string2[lenght2];
	
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));	

	for (int i = 0; i < lenght1; i++) string1[i] = rand() % 10 + 1;
	for (int i = 0; i < lenght2; i++) string2[i] = rand() % 10 + 1;
	
	cout << "ѕерва¤ последовательность:" << endl;
	for (int i = 0; i < lenght1; i++) cout << "[" << string1[i] << "]";
	cout << endl;
	cout << "¬тора¤ последовательность:" << endl;
	for (int i = 0; i < lenght2; i++) cout << "[" << string2[i] << "]";
	cout << endl;
	cout << endl;

	for (int i = 0; i < lenght1; i++) arr[i][0] = 0;
	for (int i = 0; i < lenght2; i++) arr[0][i] = 0;

	for (int i = 1; i < lenght1; i++)
	{
		for (int k = 1; k < lenght2; k++)
		{
			if (string1[i] == string2[k]) arr[i][k] = arr[i - 1][k - 1] + 1;
			else arr[i][k] = arr[i][k - 1] >= arr[i - 1][k] ? arr[i][k - 1] : arr[i - 1][k];
		}
	}

	cout << "»тогова¤ матрица:" << endl;
	for (int i = 0; i < lenght1; i++)
	{
		for (int k = 0; k < lenght2; k++)
		{
			cout << "[" << arr[i][k] << "]";
		}
		cout << endl;
	}

	system("Pause");
	return 0;
}

