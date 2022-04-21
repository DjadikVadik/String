
//   13. Напишите программу, которая найдет максимальное количество цифр, 
//   расположенных между двумя девятками в числе Pi.Ограничить этот поиск 
//   одним миллионом знаков после запятой.Например:  в начале числа Pi, 
//   между двумя девятками находятся 6 чисел, потом одно и тд : 3.14159265358979323846

#include <iostream>
#include <string>

using namespace std;

int** createArr(int n)   // создаем массив для вычисления цифр числа 'p' и заполняем его входными данными
{
	int x = 10 * n / 3;

	int** Arr = new int* [5];

	for (int i = 0; i < 5; i++)
		Arr[i] = new int[x];

	int y = 3;

	for (int i = 0; i < x; i++)
	{
		Arr[4][i] = 2;

		if (i > 0) 
		{
			Arr[0][i] = y;
			y += 2;
		}
	}

	Arr[2][x - 1] = 0;

	return Arr;
}

void DeleteArr(int**& Arr)
{
	for (int i = 0; i < 5; i++)
		delete[] Arr[i];

	delete[] Arr;
}

void createNum(int** Arr, int n, string& str)
{
	int x = 10 * n / 3;
	int y = 0; // промежуточное число для хранения цифр

	for (int i = 0; i < n; i++)
	{
		for (int j = x - 1; j >= 0; j--)
		{
			if (j != 0)
			{
				Arr[1][j] = Arr[4][j] * 10;
				Arr[3][j] = Arr[1][j] + Arr[2][j];
				Arr[4][j] = Arr[3][j] % Arr[0][j];
				Arr[2][j -1] = (Arr[3][j] / Arr[0][j]) * j;
			}

			else
			{
				Arr[1][j] = Arr[4][j] * 10;
				Arr[3][j] = Arr[1][j] + Arr[2][j];
				Arr[4][j] = Arr[3][j] % 10;
				y *= 10;
				y += Arr[3][j] / 10;
			}
		}

		int z = 0;

		if (y >= 10000)
		{
			z = y / 10000;
			str += to_string(z);
			y = y - (z * 10000);
		}
	}

	str += to_string(y);

}

int main()
{
	system("chcp 1251 > 0");

	int n;
	cout << "Введите необходимое количество цифр числа 'pi' : ";
	cin >> n;

	string str;
	int** Arr = createArr(n);

	createNum(Arr, n, str);
	DeleteArr(Arr);

	cout << "\nЦыфры числа 'pi' : " << str << "\n";

	bool start = false;
	int max = 0;
	int curent = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '9')
		{
			start = true;
			if (curent > max) max = curent; 
			curent = 0;
		}

		if (start && str[i] != '9') curent++;
	}

	cout << "\nМаксимальное количество цифр между 9ми в числе 'pi' указанной длинны = " << max << "\n";
}