/*
5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char** args)
{	
	int month;

	cout << "Input number of any month: ";
	cin >> month;

	
	if ((month > 2) && (month < 6)) cout << "This month in spring." << endl;
	else if ((month > 5) && (month < 9)) cout << "This month in summer." << endl;
	else if ((month > 8) && (month < 12)) cout << "This month in autumn." << endl;
	else if ((month > 0) && (month < 13)) cout << "This month in winter." << endl;
	else cout << "Only 12 months." << endl;

	return 0;
}
