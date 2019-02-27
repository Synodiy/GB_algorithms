/*
6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
*/

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char** args)
{	
	int age;

	setlocale(LC_CTYPE,"Russian");
	
	cout << "Input age: ";
	cin >> age;

	if (((age > 4) && (age < 21)) || ((age > 104) && (age < 121))) cout << age << " лет" << endl;
	else if (age % 10 == 1) cout << age << " год" << endl;
	else if ((age % 10 > 1) && (age % 10 < 5)) cout << age << " года" << endl;
	else cout << age << " лет" << endl;


	return 0;
}
