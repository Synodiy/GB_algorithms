/*
14. * Автоморфные числа. 
Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
Например, 25 \ :sup: 2 = 625. 
Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
*/

#include <iostream>

using namespace std;

int main (int argc, char** args)
{
	int num = 0;
	cout << "Input the natural number: ";
	cin >> num;
	
	for (int i = 1; i <= num; i ++)
	{
		int d = 1;
		int sqdnum = i * i;
		while (i > d) d *= 10;
		
		if ((i == 1) || (sqdnum % d == i)) cout << i << "\t";
	} 
	
	cout << endl;

	return 0;
}
