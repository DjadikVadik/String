
// 5.	Посчитать, сколько раз определённое слово содержится в строке текста.


#include <iostream>
#include <string>
#include <regex>


using namespace std;

void Matches(std::string str,regex reg) 
{
    sregex_iterator current(str.begin(), str.end(), reg);
    sregex_iterator last;

    int n = 0;
    
    while (current != last) 
    {
        current++;
        n++;
    }

    cout << "Слово встречается в строке " << n << " раз\n";
}

int main() 
{
	system("chcp 1251 > 0");
 
    string str;
    cout << "Введите строку : ";
    getline(cin, str);

    string s;
    cout << "Введите слово : ";
    getline(cin, s);
	
    regex rgx(s);
  
    Matches(str, rgx);
}
