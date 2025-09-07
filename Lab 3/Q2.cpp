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
    
    SinglyList * SortedLinkedList(SinglyList * list)
    {
        
      bool Flag;
      do
      {
          Node * Temp = list->Head;
          Flag = false;
        while(Temp != nullptr)
        {
            if(Temp->Next != nullptr)
            {
              if(Temp->Data > Temp->Next->Data)
              {
                int temp = Temp->Data;
                Temp->Data = Temp->Next->Data;
                Temp->Next->Data = temp;
                Flag = true;
              }
            }
            Temp = Temp->Next;
        }
      } while(Flag);
        return list;
    }
    
    SinglyList * CombineSorted(SinglyList * l1, SinglyList * l2)
    {
        Node * Temp1 = l1->Head;
        Node * Temp2 = l2->Head;
        
        
        while(Temp1 != nullptr)
        {
            Temp1 = Temp1->Next;
        }
        
        while(Temp2 != nullptr)
        {
           Node * N = new Node(Temp2->Data);
           l1->InsertAtTail(N);
           Temp2 = Temp2->Next;
        }
        
        bool flag;
        do
        {
            Node * start = Head;
            flag = false;
            while(start != nullptr && start->Next != nullptr)
            {
               if(start->Data > start->Next->Data)
               {
                   int temp = start->Data;
                   start->Data = start->Next->Data;
                   start->Next->Data = temp;
                   flag = true;
               }
               start = start->Next;
            }
        
        } while(flag);
        
        return l1;
    }
};

int main()
{
    Node * n1 = new Node(5);
    Node * n2 = new Node(3);
    Node * n3 = new Node(1);
SinglyList * list = new SinglyList();
    list->InsertAtHead(n1);
    list->InsertAtTail(n2);
    list->InsertAtTail(n3);
    
    cout << " Original List " << endl;
    list->print();
    
    cout << endl;
    cout << " Sorted " << endl;
    list = list->SortedLinkedList(list);
    list->print();
    
    
    Node * n4 = new Node(4);
    Node * n5 = new Node(2);
    Node * n6 = new Node(6);
    
    SinglyList * list2 = new SinglyList();
    list2->InsertAtTail(n4);
    list2->InsertAtTail(n5);
    list2->InsertAtTail(n6);
    
    cout << endl << " Original List " << endl;
    list2->print();
    
    cout << endl;
    cout << " Sorted " << endl;
    list2 = list2->SortedLinkedList(list2);
    list2->print();
    
    list = list->CombineSorted(list,list2);
    
    cout << endl;
    
    cout << " Combined Sorted List " << endl;
    
    list->print();
    return 0;
}
