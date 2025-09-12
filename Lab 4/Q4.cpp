#include <iostream>
using namespace std;

int InsertionAndBinarySearch(int number,int arr[],int n)
{
    int Found = -1;
    for(int y =1 ; y<n;y++)
    {
        int j = y;
        int val = arr[j];
        
        while(j > 0 && (arr[j-1] > val))
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
     
    cout << " Sorted Array " << endl;
    for(int t =0; t< n; t++)
    {
        cout << "  " << arr[t] << "  ";
    }
    
    int LowerBound = 0;
    int UpperBound = n-1;
    
    bool InList = false;
    bool FlagFound = false;
    
    while(InList == false && FlagFound == false)
    {
        int mid = ((LowerBound + UpperBound)/2);
        if(arr[mid] == number)
        {
            FlagFound = true;
            Found = mid;
        }
        
        else if(arr[mid] < number)
        {
            LowerBound = mid + 1;
        }
        else
        {
            UpperBound = mid - 1;
        }
        
        if(LowerBound > UpperBound)
        {
            InList = true;
        }
    }
    
    return Found;
}

int main()
{
    int n;
    cout << " Enter N Element " << endl;
    cin >> n;
    
    int * arr = new int[n];
    
    for(int i =0; i < n; i++)
    {
        int num;
        cout << " Enter Num " << endl;
        cin >> num;
        arr[i] = num;
        
    }
    
    int number;
    cout << " Enter Number To be Found "<< endl;
    cin >> number;
    
    int result = InsertionAndBinarySearch(number,arr,n);
    if(result == -1)
    {
        cout << " Not Found " << endl;
    }
    else
    {
        cout << endl <<  " Value found " << arr[result] << " at Position : " << result << endl;
    }
    
    delete [] arr;
    

    return 0;
}
