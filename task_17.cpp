
//   17. Написать программу, которая проверяет корректность email, указанного с клавиатуры.

#include <iostream>
#include <string>
#include <regex>
using namespace std;


int main()
{
	system("chcp 1251 > 0");

	string str;
	cout << "Введите ваш эмеил : ";
	getline(cin, str);
	
	regex value("([\\d\\w\._-]{2,20}@[\\w]+\.[a-z]{2,5})");

	if (regex_match(str, value)) cout << "\nЭмеил коректный!!!\n";
	else cout << "\nЭмеил не коректный!!!\n";
}