#include <iostream>
using namespace std;

int Abs(int x)
{
   return (x < 0) ? -x : x;
}

bool isSafe(int board[], int row, int col)
{
      for (int i = 0; i < row; i++)
      {
        if (board[i] == col || Abs(board[i] - col) == Abs(i - row))
        {
            return false;
        }
       }
   return true;
}

int solutions = 0;

void solveNQueens(int board[], int row, int n)
{
   if (row == n)
   {
     solutions++;
     cout << "Solution " << solutions << ": ";
     cout << endl;
     for (int i = 0; i < n; i++)
     {
       for (int j = 0; j < n; j++)
       {
          if (board[i] == j)
           {
               cout << "Q ";
            }

            else  
            {  
                cout << ". ";  
            }  
        }  
        cout << endl;  
      }  
      
      cout << endl;  
      return;  
    }  


    for (int col = 0; col < n; col++)   
    {  
       if (isSafe(board, row, col))   
        {  
        board[row] = col;  
        solveNQueens(board, row + 1, n);   
         board[row] = -1;          
        }  
    }

}

int main()
{
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;

    int board[20];    
  
    for (int i = 0; i < n; i++)  
    {  
      board[i] = -1;  
    }  
      
     solveNQueens(board, 0, n);  

    if (solutions == 0)  
    {  
       cout << " So No solution exists for the " << n << " queens.  ";  
     }  
      
    else  
    {  
      cout << " The Total Solutions = " << solutions << endl;  
    }  
  
   return 0;

}

