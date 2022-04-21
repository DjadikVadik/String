
//   12. Напишите программу, которая выведет на экран все возможные 
//   варианты перестановки символов в исходной строке.Избежать 
//   повторения при перестановках.Примерами перестановок символов 
//   строки «AAB» могут быть «AAB», «ABA» и «BAA».

#include <iostream>
#include <string>

using namespace std;

void NewElement(string*& str, int& size);

void Sdvig(int*& arr, int k);

int main();





void NewElement(string*& str, int& size)  // функция добавления элемента массива
{
	string* str1 = new string[size + 1];

	for (int i = 0; i < size; i++)
		str1[i] = str[i];

	delete[] str;
	size++;
	str = str1;
}

void Sdvig(int*& arr, int k)     // функция циклического сдвига влево
{
	int x = arr[0];

	for (int i = 0; i < k; i++)
		arr[i] = arr[i + 1];

	arr[k] = x;
}

int main()
{
	system("chcp 1251 > 0");

	string str;
	cout << "Введите строку: ";
	getline(cin, str);


	int* arr = new int[str.length()];  // создадим массив который будет хранить номера символов строки

	for (int i = 0; i < str.length(); i++) // присвоим каждому символу номер
		arr[i] = i;

	int k = str.length() - 1;  // переменная которая указывает на элемент массива с котрого будет осуществлятся сдвиг
	int n = 1;   // переменная показывает порядковый номер перестановки

	cout << "\nВсе возможные перестаноки символов строки:\n" << n << " - " << str << "\n";

	string* arr_str = new string[n]; // массив неповторяющихся строк
	arr_str[n - 1] = str;   // первый элемент собственно наша строка


	while (k > 0)
	{
		Sdvig(arr, k);

		if (arr[k] != k)  // переставляем номера элементов пока не сделаем круг.. затем уменьшаем "к"
		{
			string str1 = "";  // создаем пустую строку

			for (int i = 0; i < str.length(); i++) // заполняем строку символами которые соответствуют номерам символов строки
				str1 += str[arr[i]];

			bool repetition = false;  // переменная для проверки на повторение

			for (int i = 0; i < n; i++)
				if (arr_str[i] == str1) repetition = true; // проверка на повторение

			if (!repetition)  // если такой перестановки нет ..создаем новый элемент ...вносим эту перестановку в массив....показываем ее на экран
			{
				NewElement(arr_str, n);
				arr_str[n - 1] = str1;
				cout << n << " - " << str1 << "\n";
			}

			k = str.length() - 1;
		}

		else k--;
	}
}