#include <iostream>
using namespace std;


void CombSort(int arr[], int n)
{
    bool Flag = false;
    int Gap = n;
    
    int Totalcomp = 0;
    int Totalswap = 0;

    while (Gap > 1 || Flag == false)
    {
        Gap = (Gap/1.3);
        if(Gap < 1)
        {
            Gap = 1;
        }
        
        Flag = true;
        
        for(int j =0; j+Gap < n;j++)
        {
            Totalcomp++;
            if(arr[j] > arr[j+Gap])
            {
                Totalswap++;
                int Temp = arr[j];
                arr[j] = arr[j+Gap];
                arr[j+Gap] = Temp;
                Flag = false;
                
            }
        }
    }
    
    for(int i =0; i < n; i++)
    {
        int num;
        cout << " " << arr[i] << "  ";
    }
    
    cout << endl;
    cout << " Total Comparisons Performed Are "<< Totalcomp << " and Total Swaps Performed Are " << Totalswap << endl;
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
    
    
    CombSort(arr,n);
    delete [] arr;
    
    return 0;
}
