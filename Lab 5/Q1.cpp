#include <iostream>
using namespace std;

int CalculateFactorial(int n)
{
    if(n == 0 ||n == 1)
    {
        return 1;
    }
    else
    {
        return  n* CalculateFactorial(n-1);
    }
}

int main() {
    
    int n =  CalculateFactorial( 5);
    cout << " n Factorial is :  " << n ;

    return 0;
}
