#include <iostream>
#include <string>
#include <time.h>

#define array_size 10000

using namespace std;

void SwapElementsInArray(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CopyArray(int *origin, int *copy)
{
	for (int i = 0; i < array_size; i++)
	{
		copy[i] = origin[i];
	}
}

void PrintArray(int *arr)
{
	for (int i = 0; i < array_size; i++)
	{
		cout << "[" << arr[i] << "] ";
	}
	cout << endl;
}

int BubbleSortSimple(int *arr)
{
	int counter = 0;

	for (int i = 0; i < array_size; i++)
	{
		for (int k = 0; k < array_size - 1; k++)
		{
			counter++;
			if (arr[k] > arr[k + 1])
			{
				SwapElementsInArray(&arr[k], &arr[k + 1]);
				counter++;
			}
		}
	}
	cout << "������ ����� ����������� ����������� ����������: " << endl;
//	PrintArray(arr);
	return counter;
}

int BubbleSortOptim(int *arr)
{
	int counter = 0;
	bool sorted = false;

	for (int i = 0; i < array_size; i++)
	{
		sorted = false;
		for (int k = 0; k < array_size - 1; k++)
		{
			counter++;
			if (arr[k] > arr[k + 1])
			{
				SwapElementsInArray(&arr[k], &arr[k + 1]);
				sorted = true;
				counter++;
			}
		}
		if (!sorted) break;
	}
	cout << "������ ����� ���������������� ����������� ����������: " << endl;
//	PrintArray(arr);
	return counter;
}

int ShakeSort(int *arr)
{
	int counter = 0;
	bool sorted = false;
	int start = 0;
	int stop = array_size - 1;

	for (int i = 0; i < array_size; i++)
	{
		sorted = false;
		for (int k = start; k < stop; k++)
		{
			counter++;
			if (arr[k] > arr[k + 1])
			{
				SwapElementsInArray(&arr[k], &arr[k + 1]);
				sorted = true;
				counter++;
			}
		}
		stop--; 
		for (int k = stop; k > start; k--)
		{
			counter++;
			if (arr[k] < arr[k - 1])
			{
				SwapElementsInArray(&arr[k], &arr[k - 1]);
				sorted = true;
				counter++;
			}
		}
		start++;
		if (!sorted) break;
	}
	cout << "������ ����� ��������� ����������: " << endl;
//	PrintArray(arr);
	return counter;
}

int SelectionSort(int *arr)
{
	int counter = 0;
	int min = 0;
	bool sorted = false;

	for (int i = 0; i < array_size; i++)
	{
		min = i;
		sorted = false;
		for (int k = i + 1; k < array_size; k++)
		{
			counter++;
			if (arr[k] < arr[min])
			{
				min = k;
				sorted = true;
			}
		}

		if (sorted)
		{
			SwapElementsInArray(&arr[i], &arr[min]);
			counter++;
		}
	}

	cout << "������ ����� ���������� ������� ������: " << endl;
//	PrintArray(arr);
	return counter;
}

int InsertSort(int *arr)
{
	int counter = 0;

	for (int i = 0; i < array_size; i++)
	{
		int temp = arr[i];
		int k = i;

		counter++;

		while ((k > 0) && (arr[k - 1] > temp))
		{
			SwapElementsInArray(&arr[k], &arr[k - 1]);
			k--;
			counter++;
		}
	}

	cout << "������ ����� ���������� ���������: " << endl;
//	PrintArray(arr);
	return counter;
}

int BinarySearch(int *arr, int num)
{
	int pos = 0;
	int start = 0;
	int stop = array_size - 1;

	pos = start + (stop - start) / 2;
	while ((start <= stop) && (arr[pos] != num))
	{		
		if (arr[pos] < num) start = pos + 1;
		else stop = pos - 1;
		pos = start + (stop - start) / 2;
	}
	
	if (arr[pos] == num) return pos;
	else return -1;
}

int main(int argc, char** args)
{
	int base_array[array_size];
	int temp_array[array_size];
	int input = 0, answer = 0;
	
	srand(time(NULL));
	setlocale(LC_CTYPE, "Russian");

	for (int i = 0; i < array_size; i++)
	{
		base_array[i] = rand() % 100 + 1;
	}
//	cout << "�������� ������: " << endl; 
//	PrintArray(base_array);
//	cout << endl;

	//*********����������� ����������********	
	CopyArray(base_array, temp_array);	
	cout << "���������� ��������: " << BubbleSortSimple(temp_array) << endl << endl;
	//***************************************
	
	//********����������� ���������� 2*******	
	CopyArray(base_array, temp_array);
	cout << "���������� ��������: " << BubbleSortOptim(temp_array) << endl << endl;
	//***************************************

	//**********��������� ����������*********	
	CopyArray(base_array, temp_array);
	cout << "���������� ��������: " << ShakeSort(temp_array) << endl << endl;
	//***************************************
		
	//*******���������� ������� ������*******	
	CopyArray(base_array, temp_array);
	cout << "���������� ��������: " << SelectionSort(temp_array) << endl << endl;
	//***************************************

	//*********���������� ���������**********	
	CopyArray(base_array, temp_array);
	cout << "���������� ��������: " << InsertSort(temp_array) << endl << endl;
	//***************************************

	cout << "���������������� ��������� ��������� = " << array_size * (array_size - 1) << " ��������." << endl << endl;

	//***********�������� �����**************	
	cout << "������� ������� ������� �������: ";
	cin >> input;
	answer = BinarySearch(temp_array, input);
	if (answer == -1) cout << "������� [" << input << "] �� ������ � �������." << endl << endl;
	else cout << "������� [" << input << "] ��������� ��� �������� " << answer << "." << endl << endl;
	//***************************************


	system("Pause");
}