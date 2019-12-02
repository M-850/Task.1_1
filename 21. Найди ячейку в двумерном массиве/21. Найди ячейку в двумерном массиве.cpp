// 21. Найди ячейку в двумерном массиве.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[10][8]{0};
	srand(time(NULL));
	bool check = false;
	int row, collum;
	row = rand() % 10;
	collum = rand() % 8;
	arr[row][collum] = 2;
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < 5; i++)
	{
		int UserRow, UserCollum;
		cin >> UserRow >> UserCollum;
		if (UserRow > 9 || UserCollum > 7 || UserRow < 0 || UserCollum < 0) {
			cout << "Выход за границу массива" << endl;
			i--;
		}
		else if (arr[UserRow][UserCollum] == arr[row][collum])
		{
			check = true;	
			break;
		}
		else {
			 if ((arr[UserRow][UserCollum] == 1)) {
				cout << "Эту уже проверяли" << endl;
				i--;
			}
			else {
				cout << "Нет" << endl;
				arr[UserRow][UserCollum] = 1;
			}
			
			
		}

	}
	if (check) {
		cout << "Вы угадали" << endl;
	}
	else {
		cout << "GAME OVER" << endl;
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
