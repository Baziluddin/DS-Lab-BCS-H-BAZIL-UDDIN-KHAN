#include <iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{
    for(int y =0; y< n;y++)
    {
       for(int j = 0; j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
    cout << endl <<  " Sorted BubbleSort " << endl;
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
    
    int *arr = new int[n];
    
    for(int i =0; i < n; i++)
    {
        int num;
        cout << " Enter Element " << endl;
        cin >> num;
        arr[i] = num;
        
    }
    
    cout << " Unsorted Array " << endl;
    for(int i =0; i < n; i++)
    {
        cout << " " << arr[i] << "  ";
    }
    
    
    
    BubbleSort(arr,n);
    delete [] arr;

    return 0;
}
