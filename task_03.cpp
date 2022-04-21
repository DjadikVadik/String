
//  3.	Подсчитать среднюю длину слова во введённом предложении.


#include <iostream>
#include <string>
using namespace std;

void AnaliticStr(string str, int& letter, int& word)
{
	static bool numword;
	static int i = 0;
	if (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'А' && str[i] <= 'Я')
		{
			letter++;

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
		}
		else numword = false;

		i++;
		AnaliticStr(str, letter, word);
	}

	else return;
}

int main() 
{
	system("chcp 1251 > 0");

	int letter = 0;
	int word = 0;
	
	string str;
	cout << "введите строку : ";
	getline(cin, str);

	AnaliticStr(str, letter, word);

	cout << "\n\nВсего букв в строке текста – " << letter << "\n";
	cout << "Слов - " << word << "\n";
	cout << "Средняя длинна слова - " << (double) letter / word << " символов\n";
   
}
