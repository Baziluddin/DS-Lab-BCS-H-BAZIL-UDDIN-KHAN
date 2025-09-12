#include <iostream>
using namespace std;


int InterpolationSearch(int arr[], int n, int num)
{
    int LowerBound = 0;
    int HigherBound  = n - 1;

    while (LowerBound <= HigherBound && num >= arr[LowerBound] && num  <= arr[HigherBound])
    {
        if (LowerBound  == HigherBound)
        {
            if (arr[LowerBound] == num)
            {
                 return LowerBound;
            }
            
            return -1;
        }

        int Position = LowerBound + ((double)(HigherBound - LowerBound) / (arr[HigherBound] - arr[LowerBound])) * (num - arr[LowerBound]);


        if (arr[Position] == num)
        {
            return Position;
        }
        
        if (arr[Position] < num)
        {
             LowerBound = Position + 1;   
        }
            
        else
        {
          HigherBound =  Position - 1; 
        }
    }
    return -1; 
}

int main()
{
    int n;
    cout << " Enter N Element " << endl;
    cin >> n;
    
    int *arr = new int[n];
    
    for(int i =0; i < n; i++)
    {
        int num;
        cout << " Enter Num " << endl;
        cin >> num;
        arr[i] = num;
        
    }
    
    cout << " Sorting The Array " << endl;
    for(int i =0; i < n; i++)
    {
        
        for(int j =0; j < n-1; j++)
        {
             if(arr[j] > arr[j+1])
             {
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
        
        }
    
       
        
    }
    
    
    
    int number;
    cout << " Enter Number To be Found "<< endl;
    cin >> number;
    
    int result = InterpolationSearch(arr,n,number);
    
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
