#include <iostream>
using namespace std;

class Node
{
    private:
    int Data;
    
    public:
    Node * Next;
    Node * Child;
    
    Node(){
        Data =0;
        Next = nullptr;
        Child = nullptr;
    }
    
    Node(int data){
        Data = data;
        Next = nullptr;
        Child = nullptr;
    }
    
    Node(int data,Node * child)
    {
        Child = child;
        Data = data;
    }
    
    
    int GetData()
    {
        return Data;
    }
    
};

class LinkedList
{
    private:
    Node * Head;
    Node * Tail;
    
    public:
    LinkedList(){
        Head = nullptr;
        Tail = nullptr;
    }
    
    void InsertAtHead(Node * node)
    {
        if(Head == nullptr && Tail == nullptr )
        {
            Head = node;
            Tail = node;
            return;
        }
        
        node ->Next = Head;
        Head = node;
        
    }
    
    void InsertAtTail(Node * node)
    {
        if(Tail== nullptr&& Head == nullptr)
        {
            Head = node;
            Tail = node;
            return;
        }
        
        Tail->Next = node;
        Tail = node;
        
    }
    
    void print(LinkedList * list)
    {
        Node * Temp = list->Head;
        while(Temp!= nullptr)
        {
            cout << "  " << Temp->GetData() ;
            Temp = Temp->Next;
        }
    }
    
    void printChild(LinkedList * List,LinkedList * childlist)
    {
        Node * Temp = List->Head;
        while(Temp!= nullptr)
        {
            cout << " " << Temp->GetData();
            
              

            if(Temp->Child != nullptr)
            {
                cout << endl;
                
            
                cout << "    ↓     " <<endl;
                Node * T = Temp->Child;
                cout << "    ";
                while(T!= nullptr)
                {
                  cout << " " << T->GetData() << "  ";
                 T = T->Next;
                }
                
                cout << endl;
            }
             if(Temp->Next != nullptr)
            {
                cout << "->";
                
            }
            
         
            Temp = Temp->Next;
        }
    }
    
    
    LinkedList* Flatten(LinkedList* List)
    {
      Node* Temp = List->Head;
       LinkedList* Flattenlist = new LinkedList();

       Node* current = Temp;
       while (current != nullptr)
      {
        Node* mainCopy = new Node(current->GetData());
        Flattenlist->InsertAtTail(mainCopy);

        if (current->Child != nullptr)
        {
            Node* cTemp = current->Child;
            while (cTemp != nullptr)
            {
                Node* cCopy = new Node(cTemp->GetData());
                Flattenlist->InsertAtTail(cCopy);

                if (cTemp->Child != nullptr)
                {
                    Node* sTemp = cTemp->Child;
                    while (sTemp != nullptr)
                    {
                        Node* sCopy = new Node(sTemp->GetData());
                        Flattenlist->InsertAtTail(sCopy);
                        sTemp = sTemp->Next;
                    }
                }

                cTemp = cTemp->Next;
            }
          }

        current = current->Next;
      }

    return Flattenlist;
    }
    
};


int main()
{
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    
    LinkedList * list = new LinkedList();
    list->InsertAtTail(n1);
    list->InsertAtTail(n2);
    list->InsertAtTail(n3);
    
    cout << "Normal List " << endl;
    list->print(list);
    
    LinkedList * Childlist = new LinkedList();
    Node * n4 = new Node(4);
    n2->Child = n4;
    
    Childlist->InsertAtTail(n4);
    Node * n5 = new Node(5);
    Childlist->InsertAtTail(n5);
    n4->Next = n5;
    cout << endl << " Whole List " << endl;
    Childlist->printChild(list,Childlist);
    
    
    LinkedList * Flattenlist = new LinkedList();
    Flattenlist = Flattenlist->Flatten(list);
    
    cout << endl;
    
    
    cout << " Flatten Linked List " << endl;
    Flattenlist->print(Flattenlist);
    

    return 0;
}
