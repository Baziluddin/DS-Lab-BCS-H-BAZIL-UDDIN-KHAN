#include <iostream>
using namespace std;

void PrintArray(int arr[],int Size)
{
    for(int y=0; y< Size;y++)
    {
        cout << " Element at Position : " << y << " : " << arr[y] << endl;
    }
}

int UpdateValue(int position ,int size,int arr[])
{
    if(position >=0 && position < size)
    {
        int newValue;
        cout << " Enter New Value At Position : " << position << endl;
        cin >> newValue;
        arr[position] = newValue;
        return 1;
    }
    else
    {
        cout << " Out Of Bound "<< endl;
        return -1;
    }
}

int main()
{
    int Size;
    cout << " Enter The Size Of Array " << endl;
    cin >> Size;
    
    int * array;
    array = new int[Size];
    
    for(int y =0;y< Size;y++)
    {
        array[y] = 0;
    }
    
     cout << " Original Array " << endl;
     PrintArray(array,Size);
     
     int pos1;
     cout << " Enter Position for value update : " << endl;
     cin >> pos1;
    
    int y = UpdateValue(pos1,Size,array);
    if(y != -1)
    {
       cout << " Updated Array " << endl;
       PrintArray(array,Size);
    }
    
    int pos2;
     cout << " Enter Position for value update : "  << endl;
     cin >> pos2;
    
    int z = UpdateValue(pos2,Size,array);
    if(z != -1)
    {
       cout << " Updated Array " << endl;
       PrintArray(array,Size);
    }
    
    delete[] array;
    return 0;
}
