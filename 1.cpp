/*
1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� � �� �����.
2. �������� ����������� ������� ������ ����� � �������.
3. �������� ������� ������ ����� � ������.
4. *������� ���������� ������� ��� ������ � �������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
using namespace std;

int **arr;		//������� ���������
int counter;	//���������� ������ �����
int *check;		//������ ���������� ������ �����

void ReadMatrix()
{
	FILE *file;

	file = fopen("matrix.txt", "r");
	if (file == NULL)
	{
		cout << "���������� ������� ����!" << endl;
		system("Pause");
		exit(0);
	}

	fscanf(file, "%d", &counter);

	arr = new int*[counter];
	for (int i = 0; i < counter; i++) arr[i] = new int[counter];

	for (int i = 0; i < counter; i++)
	{
		for (int k = 0; k < counter; k++)
		{
			fscanf(file, "%d", &arr[i][k]);
		}
	}
	fclose(file);
}

void PrintMatrix()
{
	cout << "������� ���������: " << endl;
	for (int i = 0; i < counter; i++)
	{
		for (int k = 0; k < counter; k++)
		{
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void SearchToDepth(int pos)
{
	cout << pos << " ";
	check[pos] = 1;
	for (int i = 0; i < counter; i++)
	{
		if ((arr[pos][i] != 0) && (check[i] != 1))
			SearchToDepth(i);
	}
}

void SearchToWidth(int pos)
{
	int *stack = new int[counter];

	int head = 0;

	stack[head] = pos;
	head++;
	check[pos] = 1;
	
	for (int t = 0; t < head; t++)
	{
		cout << stack[t] << " ";

		for (int i = 0; i < counter; i++)
		{
			if ((arr[stack[t]][i] != 0) && (check[i] != 1))
			{
				stack[head] = i;
				head++;
				check[i] = 1;
			}
		}
	}
}




int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	ReadMatrix();
	PrintMatrix();

	cout << "����������� ����� ����� � �������: " << endl;
	check = new int[counter];
	SearchToDepth(5);
	cout << endl;
	cout << endl;

	cout << "����� ����� � ������: " << endl;
	check = new int[counter];
	SearchToWidth(0);
	cout << endl;

	system("Pause");
	return 1;
}
