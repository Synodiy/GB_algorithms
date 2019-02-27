/*
8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char** args)
{	
	int a, b;
	int max, min;	

	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;

	max = a > b ? a : b;
	min = a > b ? b : a;

	for (int i = min; i <= max; i++)
	{
		cout << pow(i,2) << "\t";
		cout << pow(i,3) << endl;
	}


	return 0;
}
