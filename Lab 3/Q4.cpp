#include <iostream>
using namespace std;

class Node
{
    public:
    Node * Next;
    int Data;
    
    Node(){
        Data =0;
        Next = nullptr;
    }
    
    Node(int data){
        Data = data;
        Next = nullptr;
    }
};

class CircularList
{
    private:
    Node * Head;
    Node * Tail;
    
    public:
    CircularList()
    {
        Head = nullptr;
        Tail = nullptr;
    }
    
    void InsertAtPos(int pos,Node * node)
    {
        
        if(pos == 1)
        {
            if(Head == nullptr && Tail == nullptr)
            {
                Head = node;
                Tail = node;
                node->Next = Head;
                return;
            }
            else
            {
                node->Next = Head;
                Tail->Next = node;
                
                Head = node;
                return;
            }
        }
        
        int count = 1;
        Node * Temp = Head;
        while(count < pos -1 && Temp->Next != Head)
        {
            count++;
            Temp = Temp->Next;
        }
        
        node->Next = Temp->Next;
        Temp->Next = node;
        
    }
    
    void Delete(int pos)
    {
        if(pos == 1)
        {
            Node * Temp = Head;
            Head = Head->Next;
            Tail->Next = Head;
            delete Temp;
            return;
            
        }
        Node * Temp = Head;
        int count = 1;
        
        while(Temp != Head && count < pos-1)
        {
            Temp = Temp->Next;
            count++;
        }
        
        Node * DeTemp = Temp->Next;
        Temp->Next = DeTemp->Next;
        delete DeTemp;
        
    }
    
    int Winner(int k, int n)
    {
       Node * Temp = Head;
       int Length = n;

       while (Temp->Next != Temp)   
       {
         int i = 1;
          while(i < k-1)
          {
            Temp = Temp->Next;
            i++;
          }

          Node* node = Temp->Next;
          Temp->Next = node->Next;
         
          if (node == Head)
          {
            Head = node->Next;
          }
          delete node;
          Temp = Temp->Next;
        }
      Head = Temp;  
      return Head->Data;
    }
    
    

    void Print(CircularList * l)
    {
        Node*Temp=Head;
        while (true)
        {
          cout << Temp->Data << " -> ";
          Temp = Temp->Next;
          if (Temp == Head) 
          {
              break;  
          }
        }
    }
    
    
};


int main()
{
    int k;
    int N;

    cout << " Enter K " << endl;
    cin >> k;
    cout << " Enter N(Persons) " << endl;
    cin >> N;
    
    
    CircularList * list = new CircularList();
    for(int i = 1; i <= N; i++)
    {
        Node* newNode = new Node(i);
        list->InsertAtPos(i, newNode);
    }
    
    
    list->Print(list);
    
    int val = list->Winner(k,N);
    cout << endl << " Winner " << val;
    
    return 0;
}
