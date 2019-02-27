/*
9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, 
найти частное от деления нацело N на K, а также остаток от этого деления.
*/

#include <iostream>

using namespace std;

int main (int argc, char** args)
{	
	int N, K, temp;
	int res1 = 0, res2 = 0;
	
	cout << "Input N: ";
	cin >> N;
	temp = N;
	cout << "Input K: ";
	cin >> K;

	while (N >= K)
	{
		N -= K;
		res1 ++;
	}
	res2 = N;
	
	cout << "Quotient from " << temp << "/" << K << " equally " << res1 << " with remainder " << res2 << endl;
	return 0;
}
