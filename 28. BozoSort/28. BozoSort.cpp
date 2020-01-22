// 28. BozoSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<ctime>
#include<vector>
#include<Windows.h>
enum Order 
{
	ASC, 
	DESC 
};

void BozoSort(int &a, int &b, int &c, Order order = ASC) 
{
	bool check = true;
	while (check)
	{
		int index = rand() % 3;
		int temp;
		switch (index)
		{
		case 0:
			temp = a;
			a = b;
			b = temp;
			break;
		case 1:
			temp = a;
			a = c;
			c = temp;
			break;
		default:
			temp = b;
			b = c;
			c = temp;
			break;
		}
		if (order == ASC)
		{
			if (a < b && b < c) 
			{
				check = false;
			}
		}
		else
		{
			if (a > b && b > c)
			{
				check = false;
			}
		}
	}
}
void BozoSort(std::vector<int> &vec, int quantity, Order order = ASC)
{
	bool check = true;
	int temp;
	while (check)
	{
		check = false;
		int index1 = rand() % quantity;
		int index2 = rand() % quantity;
		temp = vec[index1];
		vec[index1] = vec[index2];
		vec[index2] = temp;

		for (size_t i = 0; i < quantity-1; i++)
		{
			if (order == ASC)
			{
				if (vec[i] > vec[i + 1])
				{
					check = true;
					break;
				}
			}
			else
			{
				if (vec[i] < vec[i + 1])
				{
					check = true;
					break;
				}
			}
		}
	}

}
void BozoSort( int *arr, int quantity , Order order = ASC)
{
	bool check = true;
	int temp;
	while (check)
	{
		check = false;
		int index1 = rand() % quantity;
		int index2 = rand() % quantity;
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
		for (size_t i = 0; i < quantity - 1; i++)
		{
			if (order == ASC)
			{
				if (arr[i] > arr[i+1])
				{
					check = true;
					break;
				}
			}
			else
			{
				if (arr[i] < arr[i+1])
				{
					check = true;
					break;
				}
			}
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int a, b, c, quantity;
	std::cin >> quantity;
	std::vector<int>vectorfirst(quantity);
	int* arr = new int[quantity];
	for (size_t i = 0; i < quantity; i++)
	{
		std::cin >> vectorfirst[i];
		arr[i] = vectorfirst[i];
		if (i < 3)
		{
			i == 0 ? a = vectorfirst[i] : 
			i == 1 ? b = vectorfirst[i] :
			c = vectorfirst[i];
		}
			
	}
	std::cout << "_____________________________" << std::endl;
	std::cout << "Обычный массив целых чисел" << std::endl;
	std::cout << "____________________________" << std::endl;
	BozoSort(arr, quantity);
	for (size_t i = 0; i < quantity; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "____________________________" << std::endl;
	BozoSort(arr, quantity, DESC);
	for (size_t i = 0; i < quantity; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "____________________________" << std::endl;
	std::cout << "Вектор целых чисел" << std::endl;
	std::cout << "_____________________________" << std::endl;
	BozoSort(vectorfirst, quantity);
	for (size_t i = 0; i < quantity; i++)
	{
		std::cout << vectorfirst[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "____________________________" << std::endl;
	BozoSort(vectorfirst, quantity, DESC);
	
	for (size_t i = 0; i < quantity ; i++)
	{
		std::cout << vectorfirst[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "_____________________________" << std::endl;
	BozoSort(a, b, c);
	std::cout << "Три отдельных целых числа " << std::endl;
	std::cout << "_____________________________" << std::endl;
	std::cout << a << " " << b << " " << c << " " << std::endl;
	std::cout << "_____________________________" << std::endl;
	BozoSort(a, b, c, DESC);
	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << "_____________________________" << std::endl;
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
