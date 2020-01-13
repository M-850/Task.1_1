// 24.Функции работы со строками.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;

size_t Strlen(const char* string) 
{
	size_t i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

int strcmp(const char* string1, const char* string2)
{
	int result = 0;
	//if (strlen(string1) > strlen(string2))
	//{
	//	return 1;
	//}
	//else if (strlen(string1) < strlen(string2))
	//{
	//	return -1;
	//}
	int i = 0;
	while(string1[i] != '\0' || string2[i] != '\0')
	{
		if (string1[i] > string2[i])
		{
			return 1;
		}
		else if(string1[i] < string2[i])
		{
			return -1;
		}
		i++;
	} 
	
	return result;
}
char* Strstr(char* string1, const char* string2)
{ 
	int value;
	int j = 0;
	char* ptr = nullptr;
	bool check = false;
	if (Strlen(string1) < Strlen(string2)) {
		return ptr;
	}
	for (size_t i = 0; i <= Strlen(string1) - Strlen(string2) + 1; i++)
	{
		if (string1[i] == string2[j]) {
			if (check == false) {
				value = i;
			}
			check = true;
			j++;
			if (string2[j] == '\0') 
			{
				ptr = &string1[value];
				return ptr;
			}
		}
		else
		{
			check = false;
			j = 0;
		}
		
	}
	return nullptr;
}
char* Strcat(char* destptr, const char* srcptr)
{
	int sizeDest = strlen(destptr);
	int sizeSrc = strlen(srcptr);
	for (int i = 0; i <= sizeSrc; i++)
	{
		destptr[i + sizeDest] = srcptr[i];
	}
	return destptr;
}

//char* Strcat(char* destptr, const char* srcptr)
//{
//	int sizeDest = strlen(destptr);
//	int sizeSrc = strlen(srcptr);
//	char* str = new char[sizeDest + 1];
//	 for (int i = 0; i <= sizeDest; i++)
//	 {
//		 str[i] = destptr[i];
//	 }
//	//  delete[] destptr;
//	 destptr = new char[sizeDest + sizeSrc + 1];
//	 for (int i = 0; i < sizeDest; i++)
//	 {
//		 destptr[i] = str[i];
//	 }
//	 delete[]str;
//	 str = nullptr;
//	 for (int i = 0; i <= sizeSrc; i++)
//	 {
//		 destptr[i+sizeDest] = srcptr[i];
//	 }
//	return destptr;
//}

int main()
{	setlocale(LC_ALL, "Russian");
char str1[100];
char str2[100];
cin.getline(str1, 100,'\n');
cin.getline(str2, 100,'\n');
cout <<"1. "<< Strlen(str1) << "  " << Strlen(str2) << endl;
//Strcat(str1, str2);
//cout << str1 << endl;
 
//	//SetConsoleCP(1251);
//	//SetConsoleOutputCP(1251);
//	char* str1 = new char[1];
//	char* str2 = new char[1];
//
//	for (int i = 0;; i++)
//	{
//
//		str1[i] = cin.get();
//		if (str1[i] == '\n') {
//			str1[i] = '\0';
//			break;
//		}
//		char* str = new char[i + 2];
//		for (int j = 0; j <= i; j++)
//		{
//			str[j] = str1[j];
//		}
//		delete[] str1;
//		str1 = nullptr;
//		str1 = str;
//		str = nullptr;
//	}
//
//	for (int i = 0;; i++)
//	{
//
//		str2[i] = cin.get();
//		if (str2[i] == '\n') {
//			str2[i] = '\0';
//			break;
//		}
//		char* str = new char[i + 2];
//		for (int j = 0; j <= i; j++)
//		{
//			str[j] = str2[j];
//		}
//		delete[] str2;
//		str2 = nullptr;
//		str2 = str;
//		str = nullptr;
//	}
//
 cout << "2. ";
	if (strcmp(str1, str2) > 0)
	{
		cout << "Первая сторока больше " << endl;
		
	}
	else if (strcmp(str1, str2) < 0) {
		cout << "Вторая строка больше " << endl;
	}
	else {
		cout << "Строки равны " << endl;
	}
	char* ptr1 = Strstr(str1, str2);
	char* i = 0;
	if (ptr1 != 0)
	{
		cout << "3. " << int(ptr1 - str1) << endl;
	}
	else 
	{
		cout << "Строка 2 не входит в строку 1" << endl;
	}
	Strcat(str1, str2);
	cout << "4. "<< str1 << endl;
//cout <<	Strcat(str1, str2) << endl;
//cout << str1 << endl;
//	for (int i = 0; i < strlen(str1); i++)
//	{
//		cout << str1[i] << endl;
//	}
//	/*for (int i = 0; ; i++)
//	{
//		cout << str1[i];
//		if (str1[i] == '\0') {
//			break;
//		}
//	}
//	for (int i = 0; ; i++)
//	{
//		cout << str2[i];
//		if (str2[i] == '\0') {
//			break;
//		}
//	}
//	*/
//
//	delete[]str1;
//	delete[]str2;
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
