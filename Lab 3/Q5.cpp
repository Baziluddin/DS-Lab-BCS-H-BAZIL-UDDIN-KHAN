#include <iostream>
using namespace std;


class Node 
{
public:
    int Data;
    Node* Next;
    Node(int data) 
    {
        Data = data;
        Next = nullptr;
    }
};


class NodeDoubly
{
public:
    int Data;
    NodeDoubly* Forward;
    NodeDoubly* Backward;
    NodeDoubly(int data)
    {
        Data = data;
        Forward = nullptr;
        Backward = nullptr;
    }
};

class SinglyList 
{
public:
Node* Head;
    
    SinglyList()
    { 
        Head = nullptr;
    }

    void InsertNode(int n)
    {
        Node* node = new Node(n);
        if (Head == nullptr) 
        {
            Head = node;
        }
        else 
        {
            Node* Temp = Head;
            while (Temp->Next != nullptr)
            {
            Temp = Temp->Next;
            }
            Temp->Next = node;
        }
    }

    void display() 
    {
        Node* Temp = Head;
        while (Temp != nullptr) {
            cout << Temp->Data << " -> ";
            Temp = Temp->Next;
        }
        
    }
};


class DoublyList 
{
public:
NodeDoubly * Head;


    

    DoublyList() 
    {
        Head = nullptr; 
    }

    void display() 
    {
        NodeDoubly* Temp = Head;
        while (Temp != nullptr)
        {
            cout << Temp->Data << " ";
            Temp = Temp->Forward;
        }
    }
};


class CircularList 
{

public:
Node* Head;
    

    CircularList()
    { 
        Head = nullptr;
    }

    void display()
    {
       if (Head == nullptr) 
       {
        cout << "List is empty." << endl;
        return;
       }

       Node* temp = Head;
       do {
        cout << temp->Data << " -> ";
        temp = temp->Next;
       } while (temp != Head);  

      }
};


DoublyList Doubly(SinglyList list)
{
    DoublyList Double;
    Node* Temp = list.Head;
    NodeDoubly* prev = nullptr;

    while (Temp != nullptr) 
    {
        NodeDoubly* node = new NodeDoubly(Temp->Data);
        if (Double.Head == nullptr)
            Double.Head = node;

        node->Backward = prev;
        if (prev != nullptr)
            prev->Forward = node;

        prev = node;
        Temp = Temp->Next;
    }
    return Double;
}


CircularList Circular(SinglyList Slist)
{
    CircularList Clist;
    if (!Slist.Head)
    {
        return Clist;
    }

    Clist.Head = new Node(Slist.Head->Data);
    Node* TempS = Slist.Head->Next;
    Node* TempC = Clist.Head;

    while (TempS != nullptr)
    {
        TempC->Next = new Node(TempS->Data);
        TempC = TempC->Next;
        TempS = TempS->Next;
    }
    TempC->Next = Clist.Head;  
    return Clist;
}

int main()
{
    SinglyList list;
    list.InsertNode(10);
    list.InsertNode(20);
    list.InsertNode(30);
    list.InsertNode(40);

    cout << "Original Singly Linked List: ";
    list.display();


    DoublyList doubly = Doubly(list);
    cout << endl <<  " Converted To  Doubly Linked List: ";
    doubly.display();


    CircularList clist = Circular(list);
    cout << endl <<  "  Circular Linked List : ";
    clist.display();

    return 0;
}
