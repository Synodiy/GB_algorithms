/*
13. * Написать функцию, генерирующую случайное число от 1 до 100.
	с использованием стандартной функции rand()
	без использования стандартной функции rand() 
*/


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int generateRandWithSTD (void)
{
	return (rand() % 100 + 1);
}

int generateRandWithoutSTD (void)
{
	long int x = time(NULL);
	int a = 5, b = 2;
	return ((a * x + b) % 100 + 1);
}

int main (int argc, char** args)
{
	srand(time(NULL));

	cout << "Random number with standart generator: " << generateRandWithSTD() << endl;

	cout << "Random number without standart generator: " <<generateRandWithoutSTD() << endl;

	return 0;
}
