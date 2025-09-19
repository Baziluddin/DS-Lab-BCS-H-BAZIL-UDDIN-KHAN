#include <iostream>
using namespace std;



int SumTail(int n,int Total)
{
    if(n == 0)
    {
        return Total;
    }
    
    else 
    {
        return SumTail(n-1,Total+n);
    }
}

int SumNonTail(int n)
{
    if(n == 0)
    {
        return 0;
    }
    
    else 
    {
        return n + SumNonTail(n-1);
         
    }
}

// Explaining difference between the 2 calls is that in sum Tail like our main we pass 12,0 then every time in function if base case is not reached then it deincrements the value of number and add total in it and ad it is the last call to be achieved but in and in Non Tail recursion it is run time so it waits for the output at runtime while adding the value to function call to get return the value.


int main() {
    
  int total = SumTail(12,0);
  cout << " Total Sum   using Tail Recursion is : " << total << endl;
  
   int Total = SumNonTail(12);
  cout << " Total Sum using Non Tail Recursion  is : " << Total << endl;
  
  
    

    return 0;
}
