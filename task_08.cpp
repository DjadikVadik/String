
//  8. Напишите программу, которая генерирует пароль указанной длины.

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string NewPasword(int n)
{
	string str = "";

	for (int i = 0; i < n;)
	{
		char x = rand() % 255 + 1;
		if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9')
		{
			str += x;
			i++;
		}
	}

	return str;
}

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	int n;
	cout << "Введите количество символов пароля: ";
	cin >> n;

	cout << "\nваш пароль:  " << NewPasword(n) << "\n";
}
