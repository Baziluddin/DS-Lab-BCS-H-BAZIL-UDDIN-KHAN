// Q9
#include <iostream>
using namespace std;

void SparseMatrix(int ** Matrix,int Rows,int Cols)
{
    
    int Count =0;
    
     for(int i =0; i < Rows;i++)
    {
         for(int j =0; j < Cols; j++)
         {
           if(Matrix[i][j] !=0)
           {
              Count++;
           }
         }
    }
    
    int * TempRow = new int[Count];
    
    int * TempVal = new int[Count];
    
    int * TempCol = new int[Count];
    int index =0;
    
    for(int i =0; i < Rows;i++)
    {
         for(int j =0; j < Cols; j++)
         {
           if(Matrix[i][j] !=0)
           {
               TempRow[index] = i;
               TempVal[index] = Matrix[i][j];
               TempCol[index] = j;
               index++;
           }
         }
    }
    
   cout << " Rows  Cols  Value " << endl;
   for(int i =0; i < Count;i++)
    {
        cout << " " << TempRow[i] << "      " << TempCol[i] <<  "      " << TempVal[i] << endl;
    }
     delete []TempRow;
     delete []TempCol;
     delete []TempVal;
}



int main()
{
    int Rows;
    int Cols;
    
    cout << " Enter Row " << endl;
    cin >> Rows;
    
    cout << " Enter Col " << endl;
    cin >> Cols;
    
    int ** Matrix;
    Matrix = new int*[Rows];
    for(int i =0; i < Rows;i++)
    {
        Matrix[i] = new int[Cols];
    }
    
    
     for(int i =0; i < Rows;i++)
    {
         for(int j =0; j < Cols; j++)
         {
            int Element;
            cout << " Enter Element " << endl;
            cin >> Element;
            Matrix[i][j] = Element;
         }
    }

    cout << " Matrix In Normal Form " << endl;
    
    for(int i =0; i < Rows;i++)
    {
         for(int j =0; j < Cols; j++)
         {
            cout << Matrix[i][j] << "  ";
         }
         cout << endl;
    }
    
   cout << " Matrix in Compressed form " << endl;
    SparseMatrix(Matrix,Rows,Cols);
    
    for(int i =0; i < Rows;i++)
    {
        delete [] Matrix[i];
    }
    
    delete [] Matrix;
    
    

    return 0;
}
