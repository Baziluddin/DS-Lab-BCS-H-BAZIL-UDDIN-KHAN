#include<iostream>
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

class Stack
{
    private:
    Node * Top;

    public:
    Stack() { Top = nullptr;}

    void Push(int x)
    {
        Node  * newnode = new Node(x);

        if(Top == nullptr)
        {
            Top = newnode;
            return ;
        }

        newnode->Next = Top;
        Top = newnode;

    }

    void Pop()
    {
         if(Top == nullptr)
        {
           cout << " Cant Pop No elements. " << endl;
        }
        else
        {
            Node * Temp = Top;
            if(Temp->Next == nullptr)
            {
                Top = nullptr;
                delete Temp;
                return;
            }

            Top = Top->Next;
            delete Temp;
        }

    }

    int Peek()
    {
        if(Top == nullptr)
        {
            return -1;
        }

        else
        {
            return Top->Data;
        }
    }

    void Display()
    {
        Node * Temp = Top;

        while(Temp != nullptr)
        {
            cout << " " << Temp->Data << endl;
            Temp = Temp->Next;
        }
    }

};

int main()
{
    Stack * stack = new Stack();

    while(1)
    {
        string element;
        cout << " You Can Enter Push/Pop/Display/Exit/Peek  " << endl;
        cin >> element;

       

        if(element == "Push")
        {
            int num;
            cout << " Enter Num " << endl;
            cin >> num;

            stack->Push(num);
        }

        else if(element == "Pop")
        {
            stack->Pop();
        }

        else if(element == "Peek")
        {
            int num = stack->Peek();
            if(num == -1)
            {
                cout << " No Elements in Stack " << endl;
            }
            else
            {
                cout << "Peeked  Number Is : " << num << endl;
            }
        }

        else if(element == "Display")
        {
           stack->Display();
        }

        else if(element == "Exit")
        {
            stack->Display();
            cout << " succesfully Ended " << endl;
            break;
           
        }
        else
        {
            cout << " Invalid Retry Again " << endl;
        }
    }
    
   

};
