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
    
    void print()
    {
        Node * Temp = Head;
        while(Temp != nullptr)
        {
            cout << "  " << Temp->Data << "  ";
            Temp = Temp->Next;
        }
    }
    
    SinglyList * KReversal(int k)
    {
        SinglyList * klist = new SinglyList();
        Node * Temp = Head;
        int count = 0;
        while(Temp != nullptr)
        {
            count++;
            Temp = Temp->Next;
        }
        int groups = (count/k);
        Node * Tem = Head;
        for(int u =0; u<groups;u++)
        {
            int count =0;
            
            Node * next = nullptr;
            Node * Prev = nullptr;
            Node * curr = Tem;
            bool flag = false;
            
            while(curr != nullptr&&flag == false)
            {
                if(count < k)
                {
                    next = curr->Next;
                    curr->Next = Prev;
                    Prev = curr;
                    curr = next;
                    count++;
                }
                else
                {
                    flag = true;
                }
            }
            
            Node * T = Prev;
            while(T != nullptr)
            {
                Node * n = new Node(T->Data);
                klist->InsertAtTail(n);
                T = T->Next;
            }
            Tem = curr;
        }
        
        if (Tem != nullptr )
        {
            Node* Prev = nullptr;
            Node* curr = Tem;
            Node* next = nullptr;
            while (curr != nullptr)
            {
              next = curr->Next;
             curr->Next = Prev;
              Prev = curr;
               curr = next;
            }


            Node* T = Prev;
            while (T != nullptr)
            {
              Node* n = new Node(T->Data);
              klist->InsertAtTail(n);
              T = T->Next;
            }
        }
        
        
        return klist;
    }
    
    ~SinglyList()
    {
       Node* curr = Head;
       while(curr)
       {
         Node* temp = curr;
         curr = curr->Next;
         delete temp;
       }
     }
    
    
    
    
};

int main()
{
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);
    
SinglyList * list = new SinglyList();
    list->InsertAtHead(n1);
    list->InsertAtTail(n2);
    list->InsertAtTail(n3);
    list->InsertAtTail(n4);
    list->InsertAtTail(n5);
    list->InsertAtTail(n6);
    list->InsertAtTail(n7);
    list->InsertAtTail(n8);
    list->print();
    
    cout << endl;
    int k;
    cout << " Enter K reversal " << endl;
    cin >> k;
    cout << endl;
    
    if(k!=0)
    {
        SinglyList * l =  list->KReversal(k);
   l->print();
        
    }
    else
    {
        cout << " Cant Happen " << endl;
    }
   
    

    return 0;
}
