// 30.Токенизатор.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>
char* My_strtok(char* string, const char* delim)
{
	static int counter = 0;
	static char* temp = string;
	static int length = 0;
	bool check = false;
	if (string != NULL)
	{
		while (temp[length] != '\0')
		{
			length++;
		}
		counter = 0;
		temp = string;
	}

	for (size_t i = counter; i < length; i++)
	{
		int j = 0;
		while(delim[j] != '\0')
		{
			if (temp[i] == delim[j])
			{
				check = true;
				break;
			}
			j++;
		}
		if (!check)
		{
			break;
		}
		counter++;
		check = false;
	}
	check = false;
		char* pch = &temp[counter];
		for (size_t i = counter; i < length; i++)
		{
			int j = 0;
			while (delim[j] != '\0')
			{
				if (temp[counter] == delim[j] && !check)
					{
				    temp[counter] = '\0';
					check = true;
					break;
			    	}
				j++;
			}
			counter++;
			if (check)
			{
				break;
			}
		}
		if (!check)
		{
			return nullptr;
		}
		else
		{
			return pch;
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua!";
	int i = 0;
	char* pch = My_strtok(str, " !,.");	 
	while (pch != NULL)                         
	{
		std::cout << pch << "\n";
		pch = My_strtok(NULL, " !,.");
		i++;
	}
	std::cout <<std::endl;
	std::cout << "Words: "<< i << std::endl;
	std::cout << std::endl;
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
