/*
1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
*/

#include <iostream>

using namespace std;

void DecToBin (int dec)
{
	if (dec >= 2) DecToBin(dec/2);

	cout << dec % 2;
}

int main (int argc, char** args)
{	
	int num;

	cout << "Input decimal number: ";
	cin >> num;

	cout << "This number in binary equal ";
	DecToBin (num);
	cout << endl;

	return 0;
}
