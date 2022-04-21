
//  6. Показать на экране фразу «ЭТО СПАМ!», если введённая с клавиатуры 
//  строка содержит слова вроде «viagra» или «XXX», иначе показать фразу 
//  «это не спам».Регистр строки не имеет значения.Предусмотреть возможность 
//  добавления новых нежелательных слов(организовать массив).
//  
//  «buy ViAgRA now» = > ЭТО СПАМ!
//  «free xxxxx» = > ЭТО СПАМ!
//  «innocent rabbit» = > это не спам


#include <iostream>
#include <string>
#include <regex>


using namespace std;

void strSpam(string str)
{
	string str1 = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'A' && str[i] <= 'Z')
			str1 += char(str[i] + 32);

		else if (str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'a' && str[i] <= 'z')
			str1 += str[i];

		else continue;
	}

	regex viagra("viagra");
	regex xxx("xxx");

	if (regex_search(str1, viagra))
		cout << "ЭТО СПАМ!!!\n";
	else if (regex_search(str1, xxx))
		cout << "ЭТО СПАМ!!!\n";
	else cout << "это не спам.\n";
}

int main()
{
	system("chcp 1251 > 0");

	string str;

	cout << "Введите строку: ";
	getline(cin, str);
	strSpam(str);
}
