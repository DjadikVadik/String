
// 4.	Определить, является ли строка палиндромом. Примеры палиндромов:
//      Аргентина манит негра.
//      Лёша на полке клопа нашёл.
//      Нажал кабан на баклажан.
//      Я так нежен, Катя.
//      Мокнет Оксана с котенком…
//      На вид енот – это не диван…
//      Юра, хватит!- А в харю ?



#include <iostream>
#include <string>


using namespace std;

void strPolindrom(string str)
{
	string str1 = "";
	string str2 = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'A' && str[i] <= 'Z')
			str1 += char(str[i] + 32);

		else if (str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'a' && str[i] <= 'z')
			str1 += str[i];

        else continue;
	}

	for (int i = str1.length() - 1; i >= 0; i--)
		str2 += str1[i];

	if (str1 == str2) cout << "Строка является палиндромом!!!\n";
	else cout << "Строка не является палиндромом!!!\n";
}

int main() 
{
	system("chcp 1251 > 0");
 
	string str = "Юра, хватит!- А в харю ?";
	
	strPolindrom(str);
}
