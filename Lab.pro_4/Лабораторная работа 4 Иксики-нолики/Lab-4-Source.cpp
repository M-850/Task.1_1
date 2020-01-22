#include "Lab_4_Header.h"
#include "Windows.h"
#include "ctime"
#include <iostream>
#include <vector>
Game initGame(char userChar) 
{
	Game game;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			game.bord[i][j] = ' ';
		}
	}
	srand(time(NULL));
	game.isUserTurn = rand() % 2;
	game.userChar = userChar;
	game.userChar == '0' ? game.botChar = 'X' : game.botChar = '0';
	game.status = PLAY;

	return game; 
}

void updateDisplay(const Game game)
{
	system("cls");
	std::cout << "_______________" << std::endl;
	std::cout << "  | a | b | c |" << std::endl;
	std::cout << "_______________" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << i + 1 <<" | " << game.bord[i][0] << " | " << game.bord[i][1] << " | " << game.bord[i][2] << " | " << std::endl;
		std::cout << "_______________" << std::endl;
	}

}

void botTurn(Game* game)
{
	int x = -1, y = -1, max = 0;
	int** temparr = new int* [3];
	for (size_t i = 0; i < 3; i++)
	{
		temparr[i] = new int[3];
		for (size_t j = 0; j < 3; j++)
		{
			temparr[i][j] = 0;
		}
	}
	int c = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == game->userChar)
			{
				temparr[0][i]++;
				temparr[1][j]++;
				if (i == j)
				{
					temparr[2][0]++;
				}
				if (i + j == 2)
				{
					temparr[2][1]++;
				}
			}
		}
	}
	temparr[2][2] = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (temparr[i][j] > max)
			{
				max = temparr[i][j];
				x = i;
				y = j;
			}
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		if (x == 2 && y == 0)
		{
			int j = i;
			if ((game->bord[i][j] != game->botChar) && (game->bord[i][j] != game->userChar))
			{
				game->bord[i][j] = game->botChar;
				break;
			}
		}
		else if (x == 2 && y == 1)
		{
			int j = 2 - i;
			if ((game->bord[i][j] != game->botChar) && (game->bord[i][j] != game->userChar))
			{
				game->bord[i][j] = game->botChar;
				break;
			}
		}
		else if (x == 0)
		{
			if (game->bord[y][i] != game->botChar && game->bord[y][i] != game->userChar)
			{
				game->bord[y][i] = game->botChar;
				break;
			}
		}
		else if (x == 1)
		{
			if (game->bord[i][y] != game->botChar && game->bord[i][y] != game->userChar)
			{
				game->bord[i][y] = game->botChar;
				break;
			}
		}
		else
		{
			game->bord[1][1] = game->botChar;
			break;
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		delete[]temparr[i];
	}

}

void userTurn(Game* game)
{
	int x,y;
	char y_litter;
	bool check = true;
	while (check)
	{
		std::cin >> x;
		std::cin >> y_litter;
		while (x != 1 && x != 2 && x != 3)
		{
			std::cout << "Error!" << std::endl;
			std::cin >> x;
			std::cin >> y_litter;
		}
	
		switch (y_litter)
		{
		case 'a':
			y = 0;
			break;
		case'b':
			y = 1;
			break;
		case'c':
			y = 2;
			break;
		default:
			std::cout << "Error!" << std::endl;
			check = true;
			break;
		}

		if (game->bord[x-1][y] == ' ')
		{
			game->bord[x-1][y] = game->userChar;
			check = false;

		}
		else
		{
			std::cout << "Error!" << std::endl;
			check = true;
		}


		
	}
}
bool updateGame(Game* game)
{
	bool turn = true;
	int Bot_Arr[8] = {};
	int User_Arr[8] = {};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == ' ')
			{
				turn = false;
				continue;
			}
			game->bord[i][j] == game->userChar ? User_Arr[i]++ : Bot_Arr[i]++;
			if (game->bord[j][i] == game->userChar)
			{
				User_Arr[j + 3]++;
			}
			else if(game->bord[j][i] == '0')
			{
				Bot_Arr[j + 3]++;
			}
			
			if (i == j)
			{
				game->bord[i][j] == game->userChar ? User_Arr[6]++ : Bot_Arr[6]++;
			}
			if (j == (2 - i))
			{
				game->bord[i][j] == game->userChar ? User_Arr[7]++ : Bot_Arr[7]++;
			}
		
		}
		if (User_Arr[0] == 3 || User_Arr[1] == 3 || User_Arr[2] == 3 || User_Arr[3] == 3 || User_Arr[4] == 3 || User_Arr[5] == 3 || User_Arr[6] == 3 || User_Arr[7] == 3)
		{
			game->status = USER_WIN;
			turn = true;
			break;
		}
 		else if (Bot_Arr[0] == 3 || Bot_Arr[1] == 3 || Bot_Arr[2] == 3 || Bot_Arr[3] == 3 || Bot_Arr[4] == 3 || Bot_Arr[5] == 3 || Bot_Arr[6] == 3 || Bot_Arr[7] == 3)
		{
			game->status = BOT_WIN;
			turn = true;
			break;
		}
	}

	if (turn && game->status != USER_WIN && game->status != BOT_WIN)
	{
		game->status = NOT_WIN;
		return true;
	}
	game->isUserTurn == true ? game->isUserTurn = false : game->isUserTurn = true;
	return turn;
}
