#include <iostream>
using namespace std;

class SafePointer
{
    private:
    int * ptr;
    
    public:
    SafePointer()
    {
        ptr = new int(0);
    }
    
    SafePointer(int val)
    {
        ptr = new int(val);
    }
    
    void setValue(int val)
    {
       * ptr = val;
    }
    
    int getValue()
    {
        return*(ptr);
    }
    
    void release()
    {
        delete ptr;
        ptr = nullptr;
    }
    
    ~SafePointer()
    {
      delete ptr;
      ptr = nullptr;
     }
};


int main() 
{
   SafePointer pointer[5] = { SafePointer(7), SafePointer(8), SafePointer(9), SafePointer(20), SafePointer(2) };
 
   
   cout << " Values Are " << endl;
   for(int y =0; y< 5;y++)
   {
       cout << " Value at " << y+1 << " is : " << pointer[y].getValue() << endl;
   }
   
   pointer[0].setValue(89);
   pointer[2].setValue(21);
   pointer[4].setValue(897);
   
   cout << " Updated Values Are " << endl;
   for(int y =0; y< 5;y++)
   {
       cout << " Value at " << y+1 << " is : " << pointer[y].getValue() << endl;
   }
   
   
    return 0;
}
