//q2 part 2).
#include <iostream>
using namespace std;

void FunctionB(int n);

void FunctionA(int n)
{
    if(n == 0)
    {
        return ;
    }
    
    else 
    {
        cout << " Function A printing  : " << n << endl;
         FunctionB(n-1);
    }
}

void FunctionB(int n)
{
    if(n == 0)
    {
        return ;
    }
    
    else 
    {
        cout << " Function B printing  : " << n << endl;
         FunctionA(n-2);
    }
}



int main() 
{
    
    FunctionA(12);
    return 0;
    

    return 0;
}
