#include <iostream>
using namespace std;


class Node
{
    public:
    int Data;
    Node * Next;
    
    
    Node(int d)
    {
        Data = d;
        Next = nullptr;
    }
};

class SinglyList
{
    private:
    Node * Head;
    Node * Tail;
    
    public:
    SinglyList()
    {
        Head = nullptr;
        Tail = nullptr;
    }
    
    void InsertAtHead(Node * node)
    {
        if(Head == nullptr && Tail == nullptr)
        {
            Head = node;
            Tail = node;
            return;
        }
        
        node->Next = Head;
        Head = node;
    }
    
    void InsertAtTail(Node * node)
    {
        if(Head == nullptr && Tail == nullptr)
        {
            Head = node;
            Tail = node;
            return;
        }
        
        Tail->Next = node;
        Tail = node;
    }
    
    void InsertAtAnyPosition(int pos,Node * node)
    {
        if(pos == 1)
        {
            InsertAtHead(node);
            return;
        }
        
        Node * Temp = Head;
        int count = 1;
        
        
        while(count < pos-1)
        {
            Temp = Temp->Next;
            count++;
        }
        
        if(Temp->Next == nullptr)
        {
            InsertAtTail(node);
            return;
        }
        
        node->Next = Temp->Next;
        Temp->Next = node;
        
    }
    
    
    void print()
    {
        Node * Temp = Head;
        while(Temp != nullptr)
        {
            cout << "  " << Temp->Data << "  ";
            Temp = Temp->Next;
        }
    }
    
    bool IsPalindrom()
    {
        if (Head == nullptr)
        {
        return true;
        }
        
        int count =0;
        Node * temp = Head;
        Node * Forward = nullptr;
        Node * Backward = nullptr;
        
        while(temp != nullptr)
        {
            temp = temp->Next;
            count++;
        }
        
        
        int middle = (count/2);
        Node * Temp = Head;
        int mid = middle;
        
        for(int i = 0; i < middle; i++)
        {
          Temp  = Temp->Next;
        }
        
        while(Temp != nullptr)
        {
            Forward = Temp;   
            Temp = Temp->Next;  
            Forward->Next = Backward; 
            Backward = Forward;   
        }
        
        Node * T = Head;
        Node * B = Backward;
        
        for(int y =0; y< middle;y++)
        {
            if(T->Data != B->Data)
            {
                return false;
                
            }
            T = T->Next;
            B = B->Next;
        }
        return true;
    }
    
};

int main()
{
    Node * n1 = new Node(2);
    Node * n2 = new Node(3);
    Node * n3 = new Node(2);
    SinglyList list;
    list.InsertAtHead(n1);
    list.InsertAtTail(n2);
   list.InsertAtTail(n3);
   
    
    cout << " Original List " << endl;
    
    list.print();
    bool T = list.IsPalindrom();
    
    cout << endl;
    
    if(T == true)
    {
        cout << " Palindrome ";
    }
    else
    {
        cout << " Not Palindrome ";
    }

    return 0;
}
