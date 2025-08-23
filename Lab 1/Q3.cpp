#include <iostream>
using namespace std;

class Box
{
private:
    int *num;

public:
    Box(int n)
    {
        num = new int(n);
    }

    Box(Box &b)
    {
        num = new int(*b.num);
    }

    Box& operator=(const Box &b)  
    {
        if(this == &b)
        {
            return *this;
        }
        
        delete num;
        
        num = new int(*b.num); 
        
        return *this;              
    }

    ~Box()
    {
        delete num;
    }
    
    void display()
    {
        cout << " Num is : " << *(num) << endl;
    }
};

int main()
{
    Box b(9);
    Box c(8);
    Box d(b);
    Box e = c;
    
    cout << " Original b value " << endl;
    b.display();
    cout << " Original c value " << endl;
    c.display();
    cout << " Original d value " << endl;
    d.display();
    cout << " Original e value " << endl;
    e.display();
    d = c; 
    cout << "After assigning d = c:" << endl;  
    d.display(); 

    b = c; 
    c.display();  
    b.display();  
    
    
    cout << endl;
    
    Box* b1 = new Box(100);
    Box* b2 = b1;
    b1->display();
    b2->display();
}
