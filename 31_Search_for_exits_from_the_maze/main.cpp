#include<iostream>
#include<windows.h>
#include<string>

void Maze_Exits(const std::string maze[], int row, int col, int arr_size)
{
    static bool chek;
    static int counter = 0;
    static int** maze_way;
    if (counter == 0) {
        int col_size = maze[0].size();
        maze_way = new int* [arr_size];
        for (size_t i = 0; i < arr_size; i++)
        {
            maze_way[i] = new int[col_size];
            for (size_t j = 0; j < col_size; j++)
            {
                maze_way[i][j] = 0;
            }
        }
    }
    if ((counter == 0) && (row < 0 || col < 0 || row > 24 || col > 26 || maze[row].at(col) == '#'))
    {
        std::cout << "Не верные координаты" << std::endl;
    }
    else
    {
        maze_way[row][col] = 1;
        if (maze[row].at(col) != ' ')
        {
            std::cout << maze[row].at(col) << " ";
            counter++;
            chek = true;
        }
        else {
            counter++;
            if ((row + 1) < 25 && col < 27 && maze[row + 1].at(col) != '#' && maze_way[row + 1][col] != 1)
            {
                Maze_Exits(maze, (row + 1), col, 25);
            }
            if ((row - 1) >= 0 && col >= 0 && maze[row - 1].at(col) != '#' && maze_way[row - 1][col] != 1)
            {
                Maze_Exits(maze, (row - 1), col, 25);
            }
            if (row < 25 && (col - 1) >= 0 && maze[row].at(col - 1) != '#' && maze_way[row][col - 1] != 1)
            {
                Maze_Exits(maze, row, (col - 1), 25);
            }
            if (row >= 0 && (col + 1) < 27 && maze[row].at(col + 1) != '#' && maze_way[row][col + 1] != 1)
            {
                Maze_Exits(maze, row, (col + 1), 25);
            }
            counter--;
        }
        if (counter==0)
        {
            if (!chek) {
                std::cout << "Выхода нет" << std::endl;
            }
            for (size_t i = 0; i < arr_size; i++)
            {
                delete[] maze_way[i];
            }
        }
    }
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    std::string maze[25] = {
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
    };
    int row;
    int col;
    std::cin >> col;
    std::cin >> row;
    Maze_Exits(maze, row, col,25);
}
