
//  16. Дан неупорядоченный массив строк.Упорядочить строки – сначала по длине, затем по алфавиту.

#include <iostream>
#include <string>
using namespace std;

void sort_long(string*& str, int size);

void sort_alphabet(string*& str, int size);

void show(string*& str, int size);

int main();





void sort_long(string*& str, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;

		for (int j = i + 1; j < size; j++)
			if (str[k].length() > str[j].length()) k = j;

		swap(str[i], str[k]);
	}
}

void sort_alphabet(string*& str, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;

		for (int j = i + 1; j < size; j++)
			if (str[k][0] > str[j][0]) k = j;

		swap(str[i], str[k]);
	}
}

void show(string*& str, int size)
{
	for (int i = 0; i < size; i++)
		cout << str[i] << "\n";
}

int main()
{
	system("chcp 1251 > 0");

	int n = 5;
	string* str = new string[n];

	str[0] = "Ліберхейн Артем Геннадійович";
	str[1] = "Боярський Андрій Володимирович";
	str[2] = "Марченко Дмитро Сергійович";
	str[3] = "Поліщук Тимур Амінулла";
	str[4] = "Кандур Артем Миколайович";

	cout << "Массив до сортировки:\n\n";
	show(str, n);
	cout << "-----------------------------------";

	cout << "\nМассив отсортирован по длинне:\n\n";
	sort_long(str, n);
	show(str, n);
	cout << "-----------------------------------";

	cout << "\nМассив отсортирован по алфавиту:\n\n";
	sort_alphabet(str, n);
	show(str, n);
	cout << "-----------------------------------";
}