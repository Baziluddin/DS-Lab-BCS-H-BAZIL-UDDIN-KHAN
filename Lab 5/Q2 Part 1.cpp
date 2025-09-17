//q2 Part 1).
#include <iostream>
using namespace std;

void PrintNumbers(int n)
{
    if(n == 0)
    {
        return ;
    }
    
    else 
    {
        cout << " Number : " << n << endl;
         PrintNumbers(n-1);
    }
}

int main() {
    
    PrintNumbers(10);
    

    return 0;
}
