/*
2. Реализовать функцию возведения числа a в степень b:

a. без рекурсии;
b. рекурсивно;
c. *рекурсивно, используя свойство чётности степени.
*/

#include <iostream>
#include <math.h>

using namespace std;

int count1, count2, count3;

float PowWithoutRec (int n, int p)
{
	float result = 1;

	if (p < 0)
	{
		p = fabs(p);
		for (int i = 0; i < p; i ++)
		{
			result *= n;
			count1 ++;
		}
		result = 1 / result;
	}
	else 
	{
		for (int i = 0; i < p; i ++)
		{
			result *= n;
			count1 ++;
		}
	}

	return result;
}

float PowWithRec (int n, int p)
{
	count2 ++; 

	if (p == 0) return 1;
	else if (p > 0) return n * PowWithRec(n, p - 1);
	else return 1 / PowWithRec(n, fabs(p));	
}

float PowWithRec2 (int n, int p)
{
	count3 ++;

	if (p == 0) return 1;
	else if (p < 0) return 1 / PowWithRec2(n, fabs(p));
	else if (p % 2 == 0) return n * n * PowWithRec2(n, p - 2);
	else return n * PowWithRec2(n, p - 1);
}


int main (int argc, char** args)
{	
	int num, pwr;

	count1 = count2 = count3 = 0;

	setlocale(LC_CTYPE, "Russian");

	cout << "Введите число: ";
	cin >> num;
	cout << "Введите степень, в которую необходимо возвести число: ";
	cin >> pwr;

	cout << "Возведение в степень без рекурсии: " << PowWithoutRec (num, pwr);
	cout <<"; за " << count1 << " итераций." << endl;
	cout << "Возведение в степень с рекурсией: " << PowWithRec (num, pwr);
	cout << "; за " << count2 << " итераций." << endl;
	cout << "Возведение в степень с рекурсией 2: " << PowWithRec2 (num, pwr);
	cout << "; за " << count3 << " итераций." << endl;

	return 0;
}
