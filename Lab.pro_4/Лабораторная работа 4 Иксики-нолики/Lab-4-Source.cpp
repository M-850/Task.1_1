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
	int max = -1, counter = 0;
	bool check = true;
	int User_Arr[8] = {};
	int Bot_Arr[8] = {};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == game->userChar)  
			{
				User_Arr[i]++;
				User_Arr[j + 3]++;
			}
			else if (game->bord[i][j] == game->botChar)
			{
				Bot_Arr[i]++;
				Bot_Arr[j + 3]++;
			}
			if  (i == j && game->bord[i][j] == game->userChar)
			{
				User_Arr[6]++;
			}
			else if (i == j && game->bord[i][j] == game->botChar)
			{
				Bot_Arr[6]++;
			}
			if ((i + j) == 2 && game->bord[i][j] == game->userChar)
			{
				User_Arr[7]++;
			}
			else if ((i + j) == 2 && game->bord[i][j] == game->botChar)
			{
				Bot_Arr[7]++;
			}
		}
	}
	for (size_t i = 0; i < 8; i++)
	{
		if (max == User_Arr[i] && (User_Arr[i] + Bot_Arr[i]) < 3)
		{
			counter++;
		}
		else if ((User_Arr[i] + Bot_Arr[i]) == 3)
		{
			User_Arr[i] = -2;
		}
		if (User_Arr[i] > max && (User_Arr[i] + Bot_Arr[i]) < 3)
		{ 
			max = User_Arr[i];
			counter = 1;
		}
		else if ((User_Arr[i] + Bot_Arr[i]) == 3)
		{
			User_Arr[i] = -2;
		}
		
	}
	int temp = rand() % counter;
	
	counter = 0;
	if (max > 0)
	{
		for (size_t i = 0; i < 8; i++)
		{
			if (max == User_Arr[i])
			{
				if (counter == temp)
				{
				if (i < 3)
				{
					for (size_t j = 0; j < 3; j++)
					{
						if (game->bord[i][j] == ' ')
						{
							game->bord[i][j] = game->botChar;
							check = false;
							break;
						}
					}
				}
				if (i > 2 && i < 6)
				{
					for (size_t j = 0; j < 3; j++)
					{
						if (game->bord[j][i - 3] == ' ')
						{
							game->bord[j][i - 3] = game->botChar;
							check = false;
							break;
						}
					}
				}
				if (i == 6)
				{
					for (size_t j = 0; j < 3; j++)
					{
						if (game->bord[j][j] == ' ')
						{
							game->bord[j][j] = game->botChar;
							check = false;
							break;
						}
					}
				}
				if (i == 7)
				{
					int c = 2;
					for (size_t j = 0; j < 3; j++)
					{

						if (game->bord[c - j][j] == ' ')
						{
							game->bord[c - j][j] = game->botChar;
							check = false;
							break;
						}
					}
				}
				}
				counter++;
				if (!check)
				{
					break;
				}
			}
		}
	}
	if (max == 0)
	{
			game->bord[1][1] = game->botChar;
	}

	

}

void userTurn(Game* game)
{
	int x, y;
	char y_litter, x_litter;
	bool check = false;
	do
	{
		check = false;
		std::cin >> x_litter;
		std::cin >> y_litter;
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
		if (check)
		{
			continue;
		}
		switch (x_litter)
		{
		case '1':
			x = 0;
			break;
		case'2':
			x = 1;
			break;
		case'3':
			x = 2;
			break;
		default:
			std::cout << "Error!" << std::endl;
			check = true;
			break;
		}
		if (check)
		{
			continue;
		}
		if (game->bord[x][y] == ' ')
		{
			game->bord[x][y] = game->userChar;
			check = false;

		}
		else
		{
			std::cout << "Error!" << std::endl;
			check = true;
		}
	} while (check);
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
