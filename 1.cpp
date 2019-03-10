/*
1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
*/

#include <iostream>

using namespace std;

int main(int argc, char** args)
{
	int N, M;
	int **field;
	int **map;
	int wall_count = -1;
	int N_wall, M_wall;

	setlocale(LC_CTYPE, "Russian");

	cout << "Введите размер поля." << endl;
	cout << "Высота: ";
	cin >> N;
	cout << "Ширина: ";
	cin >> M;

	field = new int*[N];
	for (int i = 0; i < N; i++) field[i] = new int[M];
	map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[M];
		for (int k = 0; k < M; k++) map[i][k] = 1;
	}


	while (wall_count < 0)
	{
		cout << "Введите количество стен: ";
		cin >> wall_count;
		cin.clear();
	}
	while (wall_count > 0)
	{
		N_wall = M_wall = -1;
		while (N_wall < 0 || N_wall >= N)
		{
			cout << "Введите координату стены по вертикали: ";
			cin >> N_wall;
		}
		while (M_wall < 0 || M_wall >= M)
		{
			cout << "Введите координату стены по горизонтали: ";
			cin >> M_wall;
		}
		if (N_wall == 0 && M_wall == 0)
		{
			cout << "Это начальная точка, введите другую позицию для стены." << endl;
			continue;
		}
		map[N_wall][M_wall] = 0;
		wall_count--;
	}
	cout << "Карта стен:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)	cout << "[" << map[i][k] << "]";
		cout << endl;
	}
	cout << endl;


	field[0][0] = 1; //старт

	for (int i = 1; i < M; i++)
	{
		if (map[0][i] == 1 && field[0][i - 1] == 1) field[0][i] = 1; // Первая строка 
		else field[0][i] = 0;
	}

	for (int i = 1; i < N; i++)
	{
		if (map[i][0] == 1 && field[i - 1][0] == 1)	field[i][0] = 1;
		else field[i][0] = 0;

		for (int k = 1; k < M; k++)
		{
			if (map[i][k] == 1) field[i][k] = field[i][k - 1] + field[i - 1][k];
			else field[i][k] = 0;
		}
	}

	cout << "Карта возможнных маршрутов: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)	printf("%4d", field[i][k]);
		printf("\n");
	}

	system("Pause");
	return 0;
}

