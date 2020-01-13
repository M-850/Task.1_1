// 26. Структура - массив целых чисел.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//using namespace std;
struct IntArray
{
		int* data;
		int size;
};

void create(IntArray* arr, int size) 
{
	arr->size = size;
	arr->data = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr->data[i];
	}
	std::cout << std::endl;
}

int get(IntArray* arr, int index) 
{
	if (index >= arr->size)
	{
		std::cout << "Error!" << std::endl;
		arr->data = nullptr;
		arr->size = 0;
		exit(1);
	}
	else
	{
		return arr->data[index];
	}
}

void set(IntArray* arr, int index, int value)
{
	
	if (index < arr->size)
	{
		arr->data[index] = value;
	}	
	else
	{
		std::cout << "Error!" << std::endl;
		arr->data = nullptr;
		arr->size = 0;
		exit(1);
	}

}

void print(IntArray* arr)
{
	std::cout << "[";
	for (size_t i = 0; i < arr->size; i++)
	{
		std::cout << arr->data[i] << "  ";
	}
	std::cout << "]";
}

void resize(IntArray* arr, int newSize) 
{
	int* NewArray = new int[newSize];
	if (arr->size >= newSize) {
		for (size_t i = 0; i < newSize; i++)
		{
			NewArray[i] = arr->data[i];
		}
	}
	else
	{
		for (size_t i = 0; i < arr->size; i++)
		{
			NewArray[i] = arr->data[i];
		}
		for (size_t i = arr->size; i < newSize; i++)
		{
			NewArray[i] = 0;
		}
	}
	arr->size = newSize;
	arr->data = NewArray;
	NewArray = nullptr;
}

void free(IntArray* arr)
{
	if (arr->size!=0)
	{
		arr->size = 0;
		delete arr->data;
		arr->data = nullptr;
	}
	else
	{
		std::cout << "Error!" << std::endl;
	}
}

int main()
{
	IntArray myarr;
	int size;
	std::cin >> size;
	create(&myarr,size);
	print(&myarr);
	std::cout << std::endl;
	resize(&myarr,50);
	print(&myarr);
	std::cout << std::endl;
	resize(&myarr, 10);
	print(&myarr);
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
