
//     21. Написать программу, которая представляет собой простую версию базы данных 
//     по хранению логинов - паролей.Возможности программы :
//     
//     1) добавление пользователя(с клавиатуры указывается логин и пароль).Если такого 
//     логина ещё нет в базе, тогда в массив добавляется новый пользователь(при этом 
//     	в отдельном массиве фиксируется время создания пользователя).
//     
//     2) редактирование паролей(с клавиатуры указывается логин для нужного пользователя).
//     
//     3) удаление пользователя(по номеру в массиве, начиная с 0).
//     
//     4) показ всех данных(список всех пользователей - логины и время регистрации).



#include <ctime>      
#include <iostream>
#include <string>

using namespace std;


string** initialArr(int row, int col);

void NewElement(string**& arr, const int row, int& col);

void initial_login(string**& arr, const int row, int& col);

void paswordRed(string**& arr, const int row, int& col);

void del_user(string**& arr, const int row, int& col);

void Show(string**& arr, const int row, const int col);

int main();





string** initialArr(int row, int col)
{
	string** arr = new string * [row];

	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new string[col];
	}

	return arr;
}

void NewElement(string**& arr, const int row, int& col)  // функция добавления новых столбцов
{
	string** arr1 = new string * [row];

	for (size_t i = 0; i < row; i++)
	{
		arr1[i] = new string[col + 1];
	}

	for (size_t i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
	arr = arr1;
	col++;
}

void initial_login(string**& arr, const int row, int& col)
{
	system("cls");
	cout << "Для выхода введите : 0\n\n";
	string login, pasword;
	bool correctness;
	do
	{
		cout << "Введите логин нового пользователя\n(логин может содержать латинские буквы, цыфры и нижнее подчеркивание):";
		getline(cin, login);

		if (login == "0") return;

		for (size_t i = 0; i < col; i++)
			if (arr[0][i] == login)
			{
				correctness = false;
				cout << "\nТакой логин уже существует!!!\n";
				continue;
			}


		for (size_t i = 0; i < login.length(); i++)
		{
			if ((login[i] >= 'a' && login[i] <= 'z') || (login[i] >= 'A' && login[i] <= 'Z') || login[i] == '_' || (login[i] >= '0' && login[i] <= '9'))
				correctness = true;
			else
			{
				correctness = false;
				cout << "\nВы ввели некоректный логин!!!\n";
				break;
			}
		}

	} while (!correctness);

	

	bool big = false;
	bool little = false;
	bool num = false;

	

	do
	{
		cout << "Введите пароль нового пользователя\nпароль должен содержать латинские буквы разных регистров и  цыфры (не менее 6ти символов):";
		getline(cin, pasword);

		if (pasword == "0") return;

		if (pasword.length() < 6) correctness = false;

		else
		{
			for (size_t i = 0; i < pasword.length(); i++)
			{
				if ((pasword[i] >= 'a' && pasword[i] <= 'z') || (pasword[i] >= 'A' && pasword[i] <= 'Z') || (pasword[i] >= '0' && pasword[i] <= '9'))
				{
					correctness = true;

					if (pasword[i] >= 'a' && pasword[i] <= 'z') little = true;
					else if (pasword[i] >= 'A' && pasword[i] <= 'Z') big = true;
					else if (pasword[i] >= '1' && pasword[i] <= '9') num = true;
				}

				else
				{
					correctness = false;
					break;
				}
			}
		}

		if (!correctness || !little || !big || !num) cout << "\nВы ввели некоректный пароль!!!\n";

	} while (!correctness || !little || !big || !num);

	NewElement(arr, row, col);

	time_t timer = time(0);
	char time[26];
	ctime_s(time, 26, &timer);

	arr[0][col - 1] = login;
	arr[1][col - 1] = time;
	arr[2][col - 1] = pasword;

	cout << "\nГотово!!! Для продолжения работы надмите enter!!!\n";
	cin.get();
}

void paswordRed(string**& arr, const int row, int& col)
{
	string login, pasword, new_pasword;
	bool correctness = false;
	cout << "Для выхода введите : 0\n\n";
	system("cls");

	int value;

	do
	{
		cout << "Введите логин пользователя :\n";
		getline(cin, login);

		if (login == "0") return;

		for (size_t i = 0; i < col; i++)
			if (login == arr[0][i])
			{
				correctness = true;
				value = i;
				break;
			}

		if (!correctness) cout << "\nТакого логина нет в базе данных!!!\n";

	} while (!correctness);

	correctness = false;

	do
	{
		cout << "Введите старый пароль пользователя :\n";
		getline(cin, pasword);

		if (pasword == "0") return;

		if (pasword == arr[2][value]) correctness = true;

		else cout << "\nНеверный пароль!!!\n";

	} while (!correctness);

	correctness = false;

	bool big = false;
	bool little = false;
	bool num = false;

	do
	{
		cout << "Введите новый пароль пользователя\nпароль должен содержать латинские буквы разных регистров и  цыфры (не менее 6ти символов):";
		getline(cin, new_pasword);

		if (new_pasword == "0") return;

		if (new_pasword.length() < 6) correctness = false;

		else
		{
			for (size_t i = 0; i < new_pasword.length(); i++)
			{
				if ((new_pasword[i] >= 'a' && new_pasword[i] <= 'z') || (new_pasword[i] >= 'A' && new_pasword[i] <= 'Z') || (new_pasword[i] >= '0' && new_pasword[i] <= '9'))
				{
					correctness = true;

					if (new_pasword[i] >= 'a' && new_pasword[i] <= 'z') little = true;
					else if (new_pasword[i] >= 'A' && new_pasword[i] <= 'Z') big = true;
					else if (new_pasword[i] >= '1' && new_pasword[i] <= '9') num = true;
				}

				else
				{
					correctness = false;
					break;
				}
			}
		}

		if (!correctness || !little || !big || !num) cout << "\nВы ввели некоректный пароль!!!\n";

	} while (!correctness || !little || !big || !num);

	arr[2][value] = new_pasword;

	cout << "\nГотово!!! Для продолжения работы надмите enter!!!\n";
	cin.get();

}

void del_user(string**& arr, const int row, int& col)
{
	system("cls");
	int num;
	cout << "Для выхода введите : -1\n\n";
	cout << "Введите номер пльзователя для удаления: ";
	cin >> num;
	cin.ignore(32767, '\n');
	if (num == -1) return;

	string** arr1 = new string * [row];

	for (size_t i = 0; i < row; i++)
		arr1[i] = new string[col - 1];

	for (size_t i = 0; i < col; i++)
	{
		if (i < num)
		{
			arr1[0][i] = arr[0][i];
			arr1[1][i] = arr[1][i];
			arr1[2][i] = arr[2][i];
		}
		else if (i == num) continue;
		else
		{
			arr1[0][i - 1] = arr[0][i];
			arr1[1][i - 1] = arr[1][i];
			arr1[2][i - 1] = arr[2][i];
		}
	}

	for (size_t i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
	arr = arr1;
	col--;
	cout << "\nГотово!!! Для продолжения работы надмите enter!!!\n";
	cin.get();
}

void Show(string**& arr, const int row, const int col)
{
	system("cls");
	cout << "Список всех пользователей:\n";
	for (size_t i = 0; i < col; i++)
		cout << i << ") " << arr[0][i] << " -- " << arr[1][i];

	cout << "\nДля продолжения работы надмите enter!!!\n";
	cin.get();
}

int main()
{
	system("chcp 1251 > 0");

	int row = 3;
	int col = 0;
	string** arr = initialArr(row, col);

	int n;

	do
	{
		system("cls");
		cout << "Выбирите действие:\n1 - зарегестрировать нового пользователя\n2 - сменить пароль\n3 - удалить пользователя\n4 - покасать всех пользователей\n";
		cin >> n;
		cin.ignore(32767, '\n');
		if (n == 1) initial_login(arr, row, col);
		else if (n == 2) paswordRed(arr, row, col);
		else if (n == 3) del_user(arr, row, col);
		else if (n == 4) Show(arr, row, col);

	} while (true);
}