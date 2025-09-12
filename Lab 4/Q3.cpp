#include <iostream>
using namespace std;

void SelectionSort(int arr[],int n)
{
    for(int y =0; y< n;y++)
    {
       int minval = y;
       for(int j = y; j<n;j++)
        {
            if(arr[j] < arr[minval])
            {
                minval = j;
            }
        }
        int Temp = arr[y];
        arr[y] = arr[minval];
        arr[minval] = Temp;
    }
    
    cout << endl <<  " Sorted Selection Sort " << endl;
    for(int y =0; y < n ; y++)
    {
        cout <<  "   " << arr[y] << "  ";
    }
}

int main()
{
    int n;
    cout << " Enter Total Element N " << endl;
    cin >> n;
    
    int* arr= new int[n];
    
    for(int i =0; i < n; i++)
    {
        int num;
        cout << " Enter Element " << endl;
        cin >> num;
        arr[i] = num;
        
    }
    
    cout << " Un Sorted Selection Sort " << endl;
    for(int y =0; y < n ; y++)
    {
        cout <<  "   " << arr[y] << "  ";
    }
  
    SelectionSort(arr,n);
    delete [] arr;

    return 0;
}
