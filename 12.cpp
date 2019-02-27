/*
12. Написать функцию нахождения максимального из трёх чисел.
*/

#include <iostream>

using namespace std;

int MaxNum (int a, int b, int c)
{
	a = a > b ? a : b;
	return (a > c ? a : c);	
}

int main (int argc, char** args)
{	
	int a, b, c;

	cout << "Input three numbers." << endl;
	cout << "Input first: ";
	cin >> a;
	cout << "Input second: ";
	cin >> b;
	cout << "Input third: ";
	cin >> c;
	
	cout << "Average of this three numbers is " << MaxNum(a, b, c) << endl; 

	return 0;
}
