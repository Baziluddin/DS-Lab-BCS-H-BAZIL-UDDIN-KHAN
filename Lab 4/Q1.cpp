#include <iostream>
using namespace std;

int LinearSearch(int number,int arr[],int n)
{
    int Found = -1;
    for(int y =0; y<n;y++)
    {
       if(arr[y] == number)
       {
         Found = y;
         return Found;
       }

    }  
     return Found;

}

int main()
{
int n;
cout << " Enter N Element " << endl;
cin >> n;

int arr[n];  
  
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
  
int result = LinearSearch(number,arr,n);  
if(result == -1)  
{  
    cout << " Not Found " << endl;  
}  
else  
{  
    cout << " Value found " << arr[result] << " at Position : " << result << endl;  
}  
  

return 0;

}

