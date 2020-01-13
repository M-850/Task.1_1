// 25.Студенты.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include<string.h>
using std::vector;
using namespace std;

struct Stundent 
{
	char name [100];
	int group;
	int sec[5];
};
int main()
{
	Stundent stud[10];
	for (size_t i = 0; i < 10; i++)
	{
		cin >> stud[i].group >> stud[i].name;
		for (size_t j = 0; j < 5; j++)
		{
			cin >> stud[i].sec[j];
		}
		cout << endl;

	}
	vector<int>bad;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (stud[i].sec[j] < 3)
			{
				bad.push_back(i);
				break;
			}
		}
	}
	if (bad.size() == 0) {
		cout << "Not find" << endl;
		return 0;
	}
	else {
		for (size_t i = 0; i < bad.size() - 1; i++)
		{
			for (size_t j = 1 + i; j < bad.size(); j++)
			{
				if (strcmp(stud[bad[i]].name, stud[bad[j]].name) > 0)
				{
					int value = bad[i];
					bad[i] = bad[j];
					bad[j] = value;
				}
			}

		}

		for (size_t i = 0; i < bad.size(); i++)
		{
 			cout << stud[bad[i]].name << '\t' << stud[bad[i]].group << endl;
		}
		return 0;
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
