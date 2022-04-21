
//   18. Строка состоит из слов, разделённых одним или несколькими 
//   пробелами. Переставьте слова в алфавитном порядке.

#include <iostream>
#include <string>
using namespace std;

void NewElement(string*& str, int& size);

void DelElement(string*& str, int& size, int num);

void Words(string str);

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

void DelElement(string*& str, int& size, int num) // удаление элемента по номеру
{
	string* str1 = new string[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (i < num) str1[i] = str[i];
		else if (i == num) continue;
		else str1[i - 1] = str[i];
	}

	delete[] str;
	str = str1;
	size--;
}

void Words(string str)
{
	int n = 0;
	string* strArr = new string[n];

	bool word = false;

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'А' && str[i] <= 'Я') && !word)
			NewElement(strArr, n);

		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'А' && str[i] <= 'Я')
			word = true;
		else word = false;

		if (word) strArr[n - 1] += str[i];
	}

	string str_1 = "";
	int iter = n;
	for (int i = 0; i < iter; i++)
	{
		int k = 0;
		for (int j = 0; j < n; j++)
			if (strArr[k][0] > strArr[j][0]) k = j;
		str_1 = str_1 + strArr[k] + " ";
		DelElement(strArr, n, k);
	}

	cout << "\nИзмененная строка: \n" << str_1 << "\n";
}

int main()
{
	system("chcp 1251 > 0");

	string str;
	cout << "Введите строку : ";
	getline(cin, str);
	Words(str);
}