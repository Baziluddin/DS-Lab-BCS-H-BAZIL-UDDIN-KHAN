#include <iostream>
using namespace std;


bool isSafe(int ** grid, int row, int col, int num) 
{
    for (int u = 0; u < 9; u++) 
    {
        if (grid[row][u] == num || grid[u][col] == num)
        {
            return false;
        }
    }

    int Row = row - row % 3;
    int Col = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[Row + i][Col + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int ** grid)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            { 
                for (int num = 1; num <= 9; num++) 
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                        {
                            return true;
                        }


                    grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true; 
}

int main()
{
    int ** grid;
    grid = new int*[9];
    for(int u =0; u<9;u++)
    {
        grid[u] = new int[9];
    }
    
    for(int r =0; r < 9;r++)
    {
         for(int i =0; i < 9;i++)
         {
             grid[r][i] = 0;
         }
    }

    if (solveSudoku(grid))
    {
        cout << " Solved Sudoku " << endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } 
    else
    {
        cout << " No solution exists For Sakhadu . " << endl;
    }
    
    for(int r =0; r<9;r++)
    {
        delete grid[r];
    }

    delete[]  grid;
    return 0;
}
