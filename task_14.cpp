
//   14. Пользователь вводит с клавиатуры арифметическое выражение.
//   Посчитать его значение.Если в выражении встречаются неуместные 
//   символы, выдать сообщение, что выражение введено не корректно.
//   Пример выражения : 25 * 2 – 10 * 4 + (28 / 7.0 * (2 + 3)) = 30.


#include <ctime>      
#include <iostream>
#include <string>

using namespace std;

void NewElement(double*& arr, int& size)
{
	double* arr1 = new double[size + 1];
	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];
	delete[] arr;
	arr = arr1;
	size++;
}

void del_element(double*& arr, int& size, int n)
{
	double* arr1 = new double[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (i < n) arr1[i] = arr[i];
		else if (i == n) continue;
		else arr1[i - 1] = arr[i];
	}

	delete[] arr;
	arr = arr1;
	size--;
}

void del_char(string& arr, int n)
{
	string arr1;
	for (int i = 0; i < arr.length(); i++)
	{
		if (i == n) continue;
		else arr1 += arr[i];
	}
	arr = arr1;
}
double Redstr(string& str)
{
	string str1;
	for (int i = 0; i < str.length(); i++) // убираем пробелы со строки
	{
		if (str[i] == ' ' || str[i] == '=') continue;
		else str1 += str[i];
	}

	for (int i = 0; i < str1.length(); i++) // проверка на коректность
	{
		if (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '.' || str1[i] == '(' || str1[i] == ')' || str1[i] == '+' || str1[i] == '-' || str1[i] == '/' || str1[i] == '*')
			continue;
		else
		{
			cout << "\nВыражение введено не коректно!!!\n";
			return 0;
		}
	}

	str = str1;
	str1 = "";

	int n = 0;
	double* arrd = new double[n];

	for (int i = 0; i < str.length(); i++) // сохраняем числа в массив
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
		{
			str1 += str[i];

			if (i == str.length() - 1)
			{
				NewElement(arrd, n);
				arrd[n - 1] = stod(str1);
				str1 = "";
			}
		}
	
		else if (str[i] == '(' || str[i] == ')')
		{
			if (str1 != "")
			{
				NewElement(arrd, n);
				arrd[n - 1] = stod(str1);
				str1 = "";
			}
			NewElement(arrd, n);
			arrd[n - 1] = 0;
		}

		else if (str1 != "")
		{
			NewElement(arrd, n);
			arrd[n - 1] = stod(str1);
			str1 = "";
		}
	}

	str1 = "";
	string mask;
	for (int i = 0; i < str.length(); i++) // содаем строку(маску) для работы с числами
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || (str[i] == ')' && str[i - 1] == ')'))
			mask += str[i];
		else if (str[i] == ')') mask += "_)";
	}

	int start; 
	int finish;
	bool bracket;
	bool operation;
	
	do // работа с выражениями в скобках если такие есть
	{
		bracket = false;
		bool bracket2 = false;
		for (int i = 0; i < mask.length(); i++)
		{
			if (mask[i] == '(') // проверка начала выражения в скобках
			{
				bracket = true;
				start = i;
			}

			else if (mask[i] == ')') // проверка конца выражения в скобках
			{
				bracket2 = true;
				finish = i;
				break;
			}
		}

		if (bracket && !bracket2)
		{
			cout << "\nОшибка!!! В выражении нет закрывающей скобки!!!\n";
			return 0;
		}

		if (!bracket && bracket2)
		{
			cout << "\nОшибка!!! В выражении нет открывающей скобки!!!\n";
			return 0;
		}

		if (bracket && bracket2)
		{
			do
			{
				operation = false;
				for (int i = start + 1; i < finish; i++)
				{
					if (mask[i] == '*')
					{
						arrd[i] *= arrd[i + 1];
						del_element(arrd, n, i + 1);
						del_char(mask, i);
						finish--;
						operation = true;
					}

					else if (mask[i] == '/')
					{
						arrd[i] /= arrd[i + 1];
						del_element(arrd, n, i + 1);
						del_char(mask, i);
						finish--;
						operation = true;
					}
				}
					
			} while (operation);

			do
			{
				operation = false;
				for (int i = start + 1; i < finish; i++)
				{
					if (mask[i] == '+')
					{
						arrd[i] += arrd[i + 1];
						del_element(arrd, n, i + 1);
						del_char(mask, i);
						finish--;
						operation = true;
					}

					else if (mask[i] == '-')
					{
						arrd[i] -= arrd[i + 1];
						del_element(arrd, n, i + 1);
						del_char(mask, i);
						finish--;
						operation = true;
					}

					
				}

			} while (operation);

			del_element(arrd, n, start);
			del_char(mask, start);
			finish--;
			del_element(arrd, n, finish);
			del_char(mask, finish);

			for (int i = start; i < finish; i++)
				if (mask[i] == '_' && mask[i + 1] != ')') del_char(mask, i);
		}

	} while (bracket);

	do
	{
		operation = false;
		for (int i = 0; i < mask.length(); i++)
		{
			if (mask[i] == '*')
			{
				arrd[i] *= arrd[i + 1];
				del_element(arrd, n, i + 1);
				del_char(mask, i);
				finish--;
				operation = true;
			}

			else if (mask[i] == '/')
			{
				arrd[i] /= arrd[i + 1];
				del_element(arrd, n, i + 1);
				del_char(mask, i);
				finish--;
				operation = true;
			}
		}

	} while (operation);

	do
	{
		operation = false;
		for (int i = 0; i < mask.length(); i++)
		{
			if (mask[i] == '+')
			{
				arrd[i] += arrd[i + 1];
				del_element(arrd, n, i + 1);
				del_char(mask, i);
				operation = true;
			}

			else if (mask[i] == '-')
			{
				arrd[i] -= arrd[i + 1];
				del_element(arrd, n, i + 1);
				del_char(mask, i);
				operation = true;
			}
		}

	} while (operation);

	return arrd[0];
}

int main()
{
	system("chcp 1251 > 0");

	string str = "25 * 2 - 10 * 4 + (28 / 7.0 * (2 + 3))";
	cout << "Результат выражения :\n";
	cout << str << " = " << Redstr(str) << "\n";
	
}