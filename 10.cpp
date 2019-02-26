/*
10. Дано целое число N > 0. С помощью операций деления нацело и взятия остатка от деления определить, 
имеются ли в записи числа N нечётные цифры. Если имеются, то вывести True, если нет – вывести False.
*/

#include <iostream>

using namespace std;

int main (int argc, char** args)
{	
	int input;
	
	cout << "Input any number (more than 0): ";
	cin >> input;

	while (input != 0)
	{
		if (input % 2 != 0) 
		{
			cout << "True" << endl;
			return 0;
		}
		input /= 10;
	}
	cout << "False" << endl;
	return 0;
}
