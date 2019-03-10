/*
3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.
Здесь алгоритм решения такой же как и в задаче о 8 ферзях.
Разница только в проверке положения коня.
*/

#include <iostream>
#include <iomanip>

using namespace std;

#define field_size 8

int field[field_size][field_size];
int move1[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int move2[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int check_move(int x, int y, int move_num)
{
	int good_move = 0;

	for (int i = 0; (!good_move) && (i < 8); i++)
	{
		int x_move = x + move1[i];
		int y_move = y + move2[i];

		if (x_move >= 0 && x_move <= field_size - 1 && y_move >= 0 && y_move <= field_size - 1 && field[x_move][y_move] == 0)
		{
			field[x_move][y_move] = move_num;
			if (move_num < field_size * field_size)
			{
				good_move = check_move(x_move, y_move, move_num + 1);
				if (!good_move) field[x_move][y_move] = 0;
			}
			else good_move = 1;
		}
	}
	return good_move;
}

int main(int argc, char** args)
{
	setlocale(LC_CTYPE, "Russian");
	
	//field[0][0] = 1; //стартовая позиция
	field[7][7] = 1; //стартовая позиция

	if (check_move(7, 7, 2) == 1) //check_move(0, 0, 2)
	{
		for (int i = 0; i < field_size; i++)
		{
			for (int k = 0; k < field_size; k++)
			{
				cout << "[" << setw(3) <<field[i][k] << "]";
			}
			cout << endl;
		}
	}
	else cout << "Не удалось заполнить все поле." << endl;

	system("Pause");
	return 0;
}

