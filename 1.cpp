/*
1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

long calculate_hash(string inp)
{
	long out;

	for (int i = 0; i < inp.length(); i++)
	{
		out = (out * 234) ^ (inp[i] * 712);
	}
	return out;
}

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	string input;

	cout << "Введите строку: ";
	getline(cin, input);

	cout << "Результат: " << calculate_hash(input) << endl;	

	system("Pause");
	return 1;
}