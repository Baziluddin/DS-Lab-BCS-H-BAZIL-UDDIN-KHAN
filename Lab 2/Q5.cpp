#include <iostream>
using namespace std;

int** AdditionMatrix(int ** arr1,int **arr2,int rows,int cols)
{
    int ** temp = new int*[rows];
    for(int y =0; y<rows;y++)
    {
        temp[y]= new int[cols];
    }
    
    for(int y =0; y<rows;y++)
    {
        for(int j =0; j< cols;j++)
        {
            temp[y][j] = arr1[y][j] + arr2[y][j];
        }
    }
    return temp;
}

int ** SubtractionMatrix(int ** arr1,int ** arr2,int rows,int cols)
{
     int ** temp = new int*[rows];
    for(int y =0; y<rows;y++)
    {
        temp[y] = new int[cols];
    }
    
    for(int i =0;i<rows;i++)
    {
        for(int j =0; j< cols;j++)
        {
            temp[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    return temp;
    
}


int main()
{
   int rows;
   int cols;
   cout << "Enter Rows For The Array " << endl;
   cin >> rows;
   cout << "Enter Cols For The Array " << endl;
   cin >> cols;
   int ** arr1;
   int ** arr2;
   
   if(rows >0 &&  cols >0)
   {
         arr1 = new int*[rows];
   arr2 = new int*[rows];
   for(int y =0; y<rows;y++)
   {
       arr1[y] = new int[cols];
       arr2[y] = new int[cols];
   }
   
   int element1;
   for(int y =0; y<rows;y++)
    {
        for(int j =0; j< cols;j++)
        {
           cout << " Enter Element For array 1 : " << endl;
           cin >> element1;
           arr1[y][j] = element1;
        }
    }
    
   int element2;
   for(int y =0; y<rows;y++)
    {
        for(int j =0; j< cols;j++)
        {
           cout << " Enter Element For array 2 : " << endl;
           cin >> element2;
           arr2[y][j] = element2;
        }
    }
    
    int ** arr = AdditionMatrix(arr1,arr2,rows,cols);
    cout << " Addition Array " << endl;
    for(int y =0; y<rows;y++)
    {
        for(int j =0; j< cols;j++)
        {
           cout << arr[y][j] <<  " ";
          
        }
        cout << endl;
    }
   int ** brr = SubtractionMatrix(arr1,arr2,rows,cols);
    cout << " Subtraction Array " << endl;
    for(int y =0; y<rows;y++)
    {
        for(int j =0; j< cols;j++)
        {
           cout << brr[y][j] <<  " ";
        }
        cout << endl;
    }
    
    for(int y =0; y< rows;y++)
    {
        delete [] arr1[y];
        delete [] arr2[y];
        delete [] arr[y];
        delete []  brr[y];
    }
    
    delete[] arr1;
    delete[] arr2;
    delete [] arr;
    delete [] brr;
       
   }
   
   else
   {
       cout << " Sorry Cant solve Matrix " << endl;
   }
 
}
