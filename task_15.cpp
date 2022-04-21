
//  15. Определить, какая буква в тексте встречается чаще всего.

#include <iostream>
#include <string>
using namespace std;

void povtor(string str)
{
	string str_1 = "";

	int max = 0;
	int k;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue;

		bool coincidence = false;

		for (int j = 0; j < str_1.length(); j++)
		{
			if (str[i] == str_1[j])
			{
				coincidence = true;
				break;
			}
		}

		if (!coincidence)
		{
			int n = 0;
			for (int j = 0; j < str.length(); j++)
				if (str[i] == str[j]) n++;
			if (n > max)
			{
				max = n;
				k = i;
			}

			str_1 += str[i];
		}
	}

	cout << "\nВ строке чаще всего встречается буква : " << str[k] << "\nОна встречается " << max << " раз.\n";
}


int main()
{
	system("chcp 1251 > 0");

	string str;
	cout << "Введите строку : ";
	getline(cin, str);
	povtor(str);
}