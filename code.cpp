﻿// v1.0 рисует узор по типу game of life но клетки не стираются
// v2.1 добавлена анимациия

#include <iostream>
using namespace std;

void main() {
	//setlocale(LC_ALL, "ru");

	const int size = 51;
	int field[size][size]{};
	int num = 0;

	// менять эти параметры для разных узоров
	//=======================//
	int mk = 3;
	int lk = 2;

	int gen = 1;

	int graph = 2;
	int start = 2;
	int ageOfDeath = 2;
	int rule = 1;
	//=======================//

	if (start == 0)
	{
		field[size / 2][size / 2] = 2;
	}
	if (start == 1)
	{
		field[size / 2][size / 2] = 2;
		field[size / 2][size / 2 + 1] = 2;
		field[size / 2 + 1][size / 2] = 2;
		field[size / 2 + 1][size / 2 + 1] = 2;
	}
	if (start == 2)
	{
		field[size / 2][size / 2] = 2;

		field[size / 2 - 1][size / 2] = 2;
		field[size / 2 + 1][size / 2] = 2;

		field[size / 2][size / 2 + 1] = 2;
		field[size / 2][size / 2 - 1] = 2;
	}
	if (start == 3)
	{
		field[size / 2][size / 2] = 2;
		field[size / 2][size / 2 - 1] = 2;
	}

	while (true)
	{
		if (gen == 4)
		{
			cout << endl;
		}
		//																life
		for (int i = 0 + 1; i < size - 1; i++)
		{
			for (int j = 0 + 1; j < size - 1; j++)
			{
				if (rule == 1)
				{
					//
					for (int a = -1; a <= 1; a++)
					{
						for (int b = -1; b <= 1; b++)
						{
							//
							if (a != 0 || b != 0)
							{
								//if (field[i + a][j + b] == 2)
								//{
								//	num++;
								//}
								if (field[i + a][j + b] >= 2)
								{
									num++;
								}
							}
						}
					}
					if (num <= mk && num >= lk && field[i][j] == 0)
					{
						field[i][j] = 1;
					}
					num = 0;
				}
				if (rule == 2)
				{
					//
					if (field[i - 1][j] >= 2)
					{
						num++;
					}
					if (field[i][j - 1] >= 2)
					{
						num++;
					}
					if (field[i][j + 1] >= 2)
					{
						num++;
					}
					if (field[i + 1][j] >= 2)
					{
						num++;
					}
					//
					if (num <= mk && num >= lk && field[i][j] == 0)
					{
						field[i][j] = 1;
					}
					num = 0;

				}
			}
		}


		//draw

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (graph == 1)
				{
					if (field[i][j] == 0)
					{
						cout << "  ";
					}
					else
					{
						cout << field[i][j] << " ";
					}
				}
				else
				{
					if (field[i][j] == 0)
					{
						cout << "  ";
					}
					if (field[i][j] == 1)
					{
						//cout << "::";
						printf("%c", (char)176);
						printf("%c", (char)176);
					}
					if (field[i][j] >= 2)
					{
						//cout << "⬛⬛";
						//printf("%c", (char)254u);
						printf("%c", (char)177);
						printf("%c", (char)177);
					}
				}
			}
			cout << endl;
		}
		cout << "generation = " << gen << endl;
		system("pause");
		//system("cls");

		//																		death

		if (ageOfDeath != 0)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (field[i][j] >= ageOfDeath)
					{
						field[i][j] = 0;
					}
				}
			}
		}

		//for (int i = 0; i < size; i++)
		//{
		//	for (int j = 0; j < size; j++)
		//	{
		//		if (field[i][j] == 1)
		//		{
		//			field[i][j] = 2;
		//		}
		//	}
		//}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (field[i][j] > 0)
				{
					field[i][j]++;
				}
			}
		}

		if (gen == 3)
		{
			cout << endl;
		}

		gen++;
	}
}
