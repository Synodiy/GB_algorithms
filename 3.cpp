/*
3. Исполнитель Калькулятор преобразует целое число, записанное на экране. 
У исполнителя две команды, каждой команде присвоен номер:
 	1.Прибавь 1 
	2.Умножь на 2 
Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. 
Сколько существует программ, которые число 3 преобразуют в число 20? 
	а) с использованием массива; 
	б) с использованием рекурсии.

*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int count, count2;

void Calculator (int n1, int n2, string prg)
{
	if (n1 > n2) return;
	else if (n1 == n2) 
	{
		count ++;
		cout << prg << endl;
	}
	else 
	{
		Calculator (n1 + 1, n2, prg + "[1]");
		Calculator (n1 * 2, n2, prg + "[2]");
	}
}

void CalculatorArr (int n1, int n2)
{
	int arr_size = 200;
	string array[arr_size];
	int cnt = 0;
	int temp = 0;
	string tempprog = "", newprog;
	int nounic;

	for (int i = 0; i < arr_size; i ++)
	{
		temp = n1;
		newprog = tempprog;
		nounic = 0;
		
		while (temp < n2) 
		{		
			if (temp * 2 <= n2) 
			{
				newprog += "[2]";
				temp *= 2;
			}			
			else if (temp + 1 <= n2) 
			{
				newprog += "[1]";
				temp ++;
			}

			if (temp == n2) 
			{
				if (i == 0) 
				{
					cnt ++;
					temp ++;
					array[i] = newprog;
					continue;
				}

				for (int k = 0; k < i; k ++)
				{
					if (newprog == array[k]) nounic = 1;				
				} 
				
				if (nounic == 0)
				{
					cnt ++;
					temp ++;
					array[i] = newprog;
				}
			}
		}

		if (i == arr_size - 1) continue;
		tempprog += "[1]";
		n1 ++;
	}

	for (int i = 0; i < cnt; i ++)
	{	
		cout << array[i] << endl;		
	}
	count2 = cnt;
}

int main (int argc, char** args)
{	
	int start, stop;
	count = count2 = 0;
	string prog = "";

	setlocale(LC_CTYPE, "Russian");

	cout << "Введите началное число: ";
	cin >> start;
	cout << "Введите конечное число: ";
	cin >> stop;

	cout << "С помощью операций \"Прибавь 1\" и \"Умножь на 2\" получить из числа " << start << " число " << stop << "." << endl;	

	cout << "Используя рекурсию: " << endl;
	Calculator (start, stop, prog);
	cout << "Существует " << count << " комбинаций данных операций." << endl;

	cout << "Используя массив: " << endl;
	CalculatorArr (start, stop);	
	cout << "Существует " << count2 << " комбинаций данных операций." << endl;	

	return 0;
}
