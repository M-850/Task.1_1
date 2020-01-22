// 29. Аргументы командной строки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include<string>

enum Argument
{
	HELP,
	HELLO,
	BUY,
	ARG_ERROR,
	QUESTION,
	QUESTION_ANSWER
};
void CMD(const int argc,char* argv[]) 
{
	std::cout << system("echo %cd%\\29. Аргументы командной строки.exe \n");
	std::string User_Name;
	Argument answer = ARG_ERROR;
	bool check_n = false;
	bool check_w = false;
	if (std::string(argv[argc-1]) == "-n")
	{
		std::cout << "Error!" << std::endl;
		exit(1);
	}
	for (size_t i = argc - 1; i >= 1; i--)
	{
		if (std::string(argv[i]) == "-help")
		{
			std::cout << "		-help	Отображает информацию о поддерживаемых аргументах командной строки." << std::endl;
			std::cout << "      -n      Выводит на экран сообщение: \"Привет, <имя>\" " << std::endl;
			std::cout << "      -b      Если задана данный ключ программа выводит в сообщение вместо \"Привет\" - \"Пока\"."<< std::endl;
			std::cout << "              Например -n Ivan - \"Привет Ivan\" -n Ivan -b - \"Пока Ivan\""  << std::endl;
			std::cout << "      -w 	    Если задан данный ключ, то программа спрошивает у пользователя как его зовут" << std::endl;
			std::cout << "              и если задан -n, то в сообщении \"Привет, <имя>\"" << std::endl;
			std::cout << "              вместо <имя> выводится то имя которое введёл пользователь." << std::endl;
			exit(1);
		}
		else if (std::string(argv[i]) == "-b" && std::string(argv[i-2]) == "-n" && !check_w && !check_n)
		{
			User_Name = std::string(argv[i - 1]);
			check_n = true;
			answer = BUY;
		}
		else if (std::string(argv[i - 1]) == "-n" && !check_w && !check_n)
		{
			User_Name = std::string(argv[i]);
			check_n = true;
			answer = HELLO;
		}
		
			
			if (std::string(argv[i]) == "-w" && !check_w)
			{
				check_w = true;
				answer = QUESTION;
			}
			else if (std::string(argv[i]) == "-n" )
			{
				check_n = true;
			}
			
	}
	if (check_n && check_w)
	{
		answer = QUESTION_ANSWER ;
	}
	if (answer == HELLO)
	{
		std::cout << "Привет, " << User_Name << std::endl;
	}
	else if (answer == BUY)
	{
		std::cout << "Пока, " << User_Name << std::endl;
	}
	else if (answer == QUESTION)
	{
		std::cout << "Как тебя зовут?" << std::endl;
		std::cin >> User_Name;
	}
	else if (answer == QUESTION_ANSWER) 
	{
		std::cout << "Как тебя зовут?" << std::endl;
		std::cin >> User_Name;
		std::cout << "Привет, " << User_Name << std::endl;
	}
	else if (answer == ARG_ERROR)
	{
		std::cout << "Error!" << std::endl;
	}
	
}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	CMD(argc, argv);
	
	return 0;
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
