/*
7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1, y1, x2, y2). 
Требуется определить, относятся ли к поля к одному цвету или нет.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char** args)
{	
	int x1, x2, y1, y2;
	int del1, del2;
	
	cout << "Input first field: " << endl;
	cout << "x1: ";
	cin >> x1;
	cout << "y1: ";
	cin >> y1;
	cout << "Input second field: " << endl;
	cout << "x2: ";
	cin >> x2;
	cout << "x2: ";
	cin >> y2;

	del1 = (x1 + y1) % 2;
	del2 = (x2 + y2) % 2;
	if ((del1 == 0 && del2 == 0) || (del1 != 0 && del2 != 0)) cout << "Fields have one color." << endl;
	else cout << "Fields have different colors." << endl;

	return 0;
}
