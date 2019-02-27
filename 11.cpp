/*
11. С клавиатуры вводятся числа, пока не будет введён 0. 
Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8.
*/

#include <iostream>

using namespace std;

int main (int argc, char** args)
{	
	int input;
	int counter = 0;
	float sum = 0;

	cout << "Input any numbers (0 to stop):" << endl;

	do
	{
		cin >> input;
		
		if ((input > 0) && (input % 10 == 8))
		{
			sum += input;
			counter ++;
		}

	}while (input != 0);
		
	if (counter != 0) 
	{
		cout << "Arithmetical average = " << (sum / counter) << endl; 
	}
	else
	{
		cout << "You don't input any numbers." << endl; 
	}

	return 0;
}
