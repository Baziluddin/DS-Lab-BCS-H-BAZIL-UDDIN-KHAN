#include <iostream>
using namespace std;

class Stack
{
   private:
    int Top;
    int Size;
    int * arr;

   public:  
   Stack(int size)  
   {  
      Top = -1;  
       Size = size;  
      arr = new int[size];  
    }  

    void Push(int x)  
    {  
       if(Top == Size-1)  
      {  
         cout << " Cant Add " << endl;  
      }  
      else  
      {  
        Top++;  
        arr[Top] = x;  
      }  
    }  

 
    void Pop()  
    {  
      if(Top == -1)  
      {  
        cout << " Cant Pop No elements. " << endl;  
      }  
      else  
      {  
         int val = arr[Top];  
         Top--;  
         cout << " Successfully Poped : " << val << endl;  
       }  
    }  

    int Peek()  
    {  
      if(Top == -1)  
      {
          cout << " No Top Element Present " << endl;
          return -1;  
      }  
      else  
      {  
          return arr[Top];  
      }  

    }  

    void PrintContent()  
    {  
      for(int y =Top; y >= 0;y--)  
      {  
        cout << " " << arr[y] << endl;  
      }  
    }
    
    ~Stack()
    {
      delete[] arr;
    }

};

int main()
{
  Stack stack(5);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);

  cout << " Printing Original Elements " << endl;  
  stack.PrintContent();  
  stack.Pop();  
  cout << " Printing Updated Elements " << endl;  
   stack.PrintContent();  
   int peek = stack.Peek();  
   cout << " X Peeked Top Element : "  << peek << endl;  
   return 0;

}
