/*
4. Написать программу нахождения корней заданного квадратного уравнения.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char** args)
{	
	double a, b, c;
	double x1, x2;
	double discr;

	cout << "Input parameters of equation a*x^2 + b*x + c = 0." << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	
	if (a == 0) 
	{
		cout << "This is no quadratic equation" << endl;
		return 0;
	}

	discr = pow(b, 2) - 4 * a * c;

	if (discr < 0) cout << "No roots." << endl;
	else if (discr == 0) 
	{	
		x1 = -b / (2 * a);
		cout << "Root = " << x1 << endl;
	}
	else 
	{
		x1 = (-b + sqrt(discr)) / (2 * a);
		x2 = (-b - sqrt(discr)) / (2 * a);
		cout << "First root = " << x1 << ". Second root = " << x2 << endl;
	}


	return 0;
}
