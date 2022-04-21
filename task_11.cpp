
//  11. Для проверки знаний учеников после летних каникул, учитель младших 
//  классов решил начинать каждый урок с того, чтобы задавать каждому ученику 
//  пример из таблицы умножения.Но в классе 25 человек, а примеры среди них 
//  не должны повторяться.В помощь учителю напишите программу, которая будет 
//  выводить на экран 25 случайных примеров из таблицы умножения(от 2 * 2 
//  до 9 * 9, потому что задания по умножению на 1 и на 10 — слишком просты).
//  При этом среди примеров не должно быть повторяющихся
//  (примеры 2 * 3 и 3 * 2 и им подобные пары считать повторяющимися).

#include <iostream>
#include <string>
#include <regex>

using namespace std;

void DelNumElement(string*& arr, int& size, int num);

void exesise();

int main();




void DelNumElement(string*& arr, int& size, int num)  //  j) функция удаления элемента по указанному индексу
{
	string* arr1 = new string[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) continue;
		else if (i > num) arr1[i - 1] = arr[i];
	}

	delete[] arr;
	size--;
	arr = arr1;
}

void exesise()    // создаем массив из возможных примеров и выдаем 25 случайных примеров
{
	string s = "23456789";
	
	int n = 0;
	for (int i = 0; i < s.length(); i++)       // считаем сколько всего возможно таких примеров
		for (int j = i; j < s.length(); j++)
			n++;
	
	string* str = new string[n];
	n = 0;
	for (int i = 0; i < s.length(); i++)         // заполняем массив возможными примерами
		for (int j = i; j < s.length(); j++)
		{
			str[n] = str[n] + s[i] + " * " + s[j] + " = ?";
			n++;
		}

	for (int i = 0; i < 25; i++)  // выводим на экран случайные примеры
	{
		int x = rand() % n;
		cout << i + 1 << ")  " << str[x] << "\n";
		DelNumElement(str, n, x);
	}
		
		
}

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	exesise();

}
