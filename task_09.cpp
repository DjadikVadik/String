
//  9. Написать программу, проверяющую является ли одна строка анаграммой 
//  для другой  строки.Пробелы и пунктуация, разница в больших и маленьких
//  буквах должны игнорироваться.Обе строки вводятся с клавиатуры.
//  
//  Пример анаграммы :
//  Строка 1 : Аз есмь строка, живу я, мерой остр.
//  Строка 2 : За семь морей ростка я вижу рост!


#include <iostream>
#include <string>
#include <regex>

using namespace std;

void strAnogramm(string str1, string str2)
{
	string str_1 = "";
	string str_2 = "";

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= 'А' && str1[i] <= 'Я' || str1[i] >= 'A' && str1[i] <= 'Z')
			str_1 += char(str1[i] + 32);

		else if (str1[i] >= 'а' && str1[i] <= 'я' || str1[i] >= 'a' && str1[i] <= 'z')
			str_1 += str1[i];

		else continue;
	}

	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] >= 'А' && str2[i] <= 'Я' || str2[i] >= 'A' && str2[i] <= 'Z')
			str_2 += char(str2[i] + 32);

		else if (str2[i] >= 'а' && str2[i] <= 'я' || str2[i] >= 'a' && str2[i] <= 'z')
			str_2 += str2[i];

		else continue;
	}

	for (int i = 0; i < str_1.length(); i++)
		for (int j = 0; j < str_2.length(); j++)
			if (str_1[i] == str_2[j])
			{
				str_1[i] = ' ';
				str_2[j] = ' ';
			}

	if (str_1 == str_2) cout << "Одна строка является анограммой для другой!!!\n";
	else cout << "Строки не являются анограммами!!!\n";

}

int main()
{
	system("chcp 1251 > 0");

	string str1 = "Аз есмь строка, живу я, мерой остр.";
	string str2 = "За семь морей ростка я вижу рост!";

	strAnogramm(str1, str2);
}
