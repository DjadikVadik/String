
//  2.	Написать программу, подсчитывающую количество слов, а также гласных 
//  и согласных букв в строке, введённой пользователем.Дополнительно выводить
//  количество знаков пунктуации, цифр и других символов.Учесть, что между 
//  словами(а также до и после слов) может быть более одного пробела!
//  Пример вывода программы :
// 
//  Всего символов в строке текста – 38, из них :
//  Слов – 6
//  Гласных букв - 12
//  Согласных букв - 21
//  Знаков пунктуации - 2
//  Цифр – 0
//  Других символов – 3



#include <iostream>
#include <string>
using namespace std;

void AnaliticStr(string str, int& symbol, int& word, int& vowels, int& consonants, int& punctuation, int& numbers, int& other)
{
	static bool numword;
	static int i = 0;
	if (str[i] != '\0')
	{
		symbol++;
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'А' && str[i] <= 'Я')
		{
			if (i == 0)
			{
				numword = true;
				word++;
			}
			else if (!numword)
			{
				numword = true;
				word++;
			}
			if (str[i] == 'а' || str[i] == 'е' || str[i] == 'ё' || str[i] == 'и' || str[i] == 'о'
				|| str[i] == 'у' || str[i] == 'ы' || str[i] == 'э' || str[i] == 'ю' || str[i] == 'я'
				|| str[i] == 'А' || str[i] == 'Е' || str[i] == 'Ё' || str[i] == 'И' || str[i] == 'О'
				|| str[i] == 'У' || str[i] == 'Ы' || str[i] == 'Э' || str[i] == 'Ю' || str[i] == 'Я'
				|| str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
				|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') vowels++;

			else consonants++;
		}
		else
		{
			numword = false;

			if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '\'' || str[i] == '"' || str[i] == '!' || str[i] == '?' || str[i] == '-')
				punctuation++;

			else if (str[i] >= 0 && str[i] <= 9)
				numbers++;
			else other++;
		}

		i++;
		AnaliticStr(str, symbol, word, vowels, consonants, punctuation, numbers, other);
	}

	else return;
}

int main() 
{
	system("chcp 1251 > 0");

	int symbol = 0;
	int word = 0;
	int vowels = 0;
	int consonants = 0;
	int punctuation = 0;
	int numbers = 0;
	int other = 0;

	string str;
	cout << "введите строку : ";
	getline(cin, str);

	AnaliticStr(str, symbol, word, vowels, consonants, punctuation, numbers, other);

	cout << "\n\nВсего символов в строке текста – " << symbol << ", из них :\n";
	cout << "Слов - " << word << "\n";
	cout << "Гласных букв - " << vowels << "\n";
	cout << "Согласных букв - " << consonants << "\n";
	cout << "Знаков пунктуации - " << punctuation << "\n";
	cout << "Цифр - " << numbers << "\n";
	cout << "Других знаков - " << other << "\n";
}
