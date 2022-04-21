
//   19. В виде строк вводятся два очень длинных целых числа.Найти их сумму.

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a);

void long_Sum(string str_1, string str_2);

int main();




int ctoi(char a)
{
	if (a == '0') return 0;
	else if (a == '1') return 1;
	else if (a == '2') return 2;
	else if (a == '3') return 3;
	else if (a == '4') return 4;
	else if (a == '5') return 5;
	else if (a == '6') return 6;
	else if (a == '7') return 7;
	else if (a == '8') return 8;
	else if (a == '9') return 9;
}

void long_Sum(string str_1, string str_2)
{
	string str_3 = "";

	if (str_1.length() < str_2.length())
	{
		while (str_1.length() != str_2.length())
		{
			char x = str_1[str_1.length() - 1];
			for (int i = str_1.length() - 1; i > 0; i--) 
				str_1[i] = str_1[i - 1];
	
			str_1[0] = '0';
			str_1 += x;
		}
	}

	else if (str_1.length() > str_2.length())
	{
		while (str_1.length() != str_2.length())
		{
			char x = str_2[str_2.length() - 1];
			for (int i = str_2.length() - 1; i > 0; i--)
				str_2[i] = str_2[i - 1];
		
			str_2[0] = '0';
			str_2 += x;
		}
	}

	int x = 0;

	for (int i = str_1.length() - 1; i >= 0; i--)
	{
		int y = ctoi(str_1[i]) + ctoi(str_2[i]) + x;

		if (y >= 10) x = y / 10;
		else x = 0;

		str_3 += to_string(y - (x * 10));
	}

	if (x != 0) str_3 += to_string(x);

	for (int i = 0; i < str_3.length() / 2; i++)
		swap(str_3[i], str_3[str_3.length() - 1 - i]);

	cout << "\nСумма этих чисел равна : \n" << str_3 << "\n\n";

}


int main()
{
	system("chcp 1251 > 0");

	string str_1, str_2;

	cout << "Введите  два очень длинных целых числа : \n";

	getline(cin, str_1);

	getline(cin, str_2);

	long_Sum(str_1, str_2);
}