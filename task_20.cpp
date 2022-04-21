
//     20. Напишите программу, которая будет печатать ромбовидный рисунок на основе 
//     имеющейся строки(максимальная длина – 50 символов).Пример вывода, если строка "testing":
//     
//           t
//          te
//         tes
//        test
//       testi
//      testin
//     testing
//     esting
//     sting
//     ting
//     ing
//     ng
//     g



#include <iostream>
#include <string>
using namespace std;

void romb_show(string str)
{
	cout << "\nНаша строка напечатана в виде ромба : \n\n";
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length() - 1 - i; j++)
			cout << " ";
		for (int k = 0; k <= i; k++)
			cout << str[k];
		cout << "\n";
	}

	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = 1 + i; j < str.length(); j++)
			cout << str[j];
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	system("chcp 1251 > 0");

	string str;
	cout << "Введите строку : ";
	getline(cin, str);
	romb_show(str);
}