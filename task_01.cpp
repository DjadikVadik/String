
//  1.	Ввести с клавиатуры строку текста, а затем один символ.Показать 
//  на экран индексы и количество совпадений(ищем вхождения символа в строку).


#include <iostream>
#include <string>
using namespace std;

int coincidences(string s, char c)
{
	static int n = 0;
	static int i = 0;
	if (s[i] != '\0')
	{
		if (s[i] == c)
		{
			cout << "символ совпадает с элементом номер :" << i << "\n";
			n++;
			i++;
		}
		else i++;
		coincidences(s, c);
	}
	return n;
}

int main()
{
	system("chcp 1251 > 0");

	string s;
	cout << "введите строку :";
	getline(cin, s);

	char c;
	cout << "введите символ :";
	cin >> c;
	cout << "\n\n";

	cout << "указанный символ повторяется в строке " << coincidences(s, c) << " раз\n";
}
