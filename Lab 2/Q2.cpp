#include <iostream>
using namespace std;


void PrintArray(int **arr,int Rows,int Columns )
{
    for(int i=0; i< Rows;i++)
    {
        for(int j =0; j< Columns;j++)
        {
           cout << arr[i][j] <<
           "   ";
        }
        cout << endl;
    }
}

void FillSeats(int Rows,int Columns,int **arr)
{
    for(int i =0; i < Rows;i++)
    {
        for(int j =0; j < Columns;j++)
        {
            int input;
            cout << " Enter to Occup Seat enter (1) else empty(0) " << endl;
            cin >> input;
            if(input == 0 || input == 1)
            {
                arr[i][j] = input;
            }
            else
            {
                cout << " Out Of Bounds " << endl;
            }
        }
    }
    
}

int main()
{
    int Rows;
    cout << " Enter Rows(Benches) for Array " << endl;
    cin >> Rows;
    
    int Columns;
    cout << " Enter Columns(Seats) for Array " << endl;
    cin >> Columns;
    
    int ** array;
    array = new int*[Rows];
    
    for(int i =0; i < Rows;i++)
    {
        array[i] = new int[Columns];
    }
    
    for(int i =0; i < Rows;i++)
    {
        for(int j =0; j < Columns;j++)
        {
            array[i][j] =0;
        }
    }
    
    cout << " Original 2d Array " << endl;
    cout << endl;
    PrintArray(array,Rows,Columns);
    
    FillSeats(Rows,Columns,array);
    cout << " Updated 2d Array " << endl;
    cout << endl;
    PrintArray(array,Rows,Columns);
    
    for(int y =0; y< Rows;y++)
    {
        delete[] array[y];
    }
    delete[] array;
}
