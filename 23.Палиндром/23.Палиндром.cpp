// 23.Палиндром.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
using std::vector;
template<typename T> 
bool Palindrome(T str)
{
	int c = 0; 
	bool check = true;
	for (char i = 0; ; i++)
	{
		if (str[i] == '\0') {
			break;
		}		
		else {
			c++;
		}
	}
	cout << c;
	if (c == 0) {
		return false;
	}
	for (int i = 0; i < (c/2); i++)
	{
		if (str[i] != str[c - i - 1])
		{
			return false;
		}
	}
	return check;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char a;
	vector<char>str;
	for (int i = 0;; i++)
	{
		a = cin.get();

		if (a == '\n')
		{
			a = '\0';
			str.push_back(a);
		break;
		}
		else if (isalnum(a))
		{
			str.push_back(tolower(a));
		}
		
		
	}
	//for (int i = 0; i < str.size(); i++)
	//{
	//	cout << str[i];
	//}

	//
	//char str[20];
	//

	//for (int i = 0; i < 20; i++)
	//{
	//	a = cin.get();
	//	if (a == '\n')
	//	{
	//		str[i] = '\0';
	//		break;
	//	}
	//	else if (isalnum(a))
	//	{
	//		str[i] = toupper(a);
	//	}
	//	else 
	//	{
	//		i--;
	//	} 

	//	
	//}
	if (Palindrome(str)) {
		cout << "Палиндром" << endl;
	}
	else {
		cout << "Не палиндром" << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
