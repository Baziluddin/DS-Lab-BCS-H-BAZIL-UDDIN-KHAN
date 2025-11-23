#include <iostream>
using namespace std;

class Node
{
    public:
    int Data;
    Node * LeftChild;
    Node * RightChild;
    int Height;
   
    Node(int d)
    {
        Data = d;
        Height = 1;
        LeftChild  = nullptr;
        RightChild = nullptr;
    }
   
};

class AvlTree
{
    public:
   
    Node * Root;
   
    AvlTree()
    {
        Root = nullptr;
    }
   
    int GetHeight(Node * node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        return node->Height;
    }
   
    int GetBf(Node * node)
    {
        if(node == nullptr)
        {
            return 0;
        }
       
        return (GetHeight(node->LeftChild) - GetHeight(node->RightChild));
    }
   
    Node * LeftRotaion(Node * node)
    {
        Node * x = node->RightChild;
        Node * T = x->LeftChild;
        x->LeftChild = node;
        node->RightChild = T;
        node->Height = 1 + max(GetHeight(node->LeftChild), GetHeight(node->RightChild));
        x->Height = 1 + max(GetHeight(x->LeftChild), GetHeight(x->RightChild));
       return x;
    }
   
    Node * RightRotaion(Node * node)
    {
     Node * x = node->LeftChild;
     Node * T = x->RightChild;
     x->RightChild = node;
     node->LeftChild = T;
     node->Height = 1 + max(GetHeight(node->LeftChild), GetHeight(node->RightChild));
     x->Height = 1 + max(GetHeight(x->LeftChild), GetHeight(x->RightChild));
     return x;
    }
   
   
   
    Node * InsertNode(Node * Root,Node * node)
    {
        if(Root == nullptr)
        {
            return node;
        }
       
        else if(Root->Data > node->Data)
        {
            Root->LeftChild = InsertNode(Root->LeftChild,node);
        }
       
        else if(Root->Data < node->Data)
        {
            Root->RightChild = InsertNode(Root->RightChild,node);
        }
        else
        {
            return Root;
        }
        
        
        Root->Height = 1 + max(GetHeight(Root->LeftChild),GetHeight(Root->RightChild));
       
        int bf = GetBf(Root);
        cout << "Balance Factor of node " << Root->Data << " = " << bf << endl;
       
     
       
        if (bf > 1 && node->Data < Root->LeftChild->Data)
        {
            cout << " Right Roation (LL) with Balance Factor On = " << bf  << endl;
            return RightRotaion(Root);
        }
       
        else if (bf < -1 && node->Data > Root->RightChild->Data)
        {
            cout << " Left Roation (RR) with Balance Factor On = " << bf  << endl;
            return LeftRotaion(Root);
        }
       
        else if (bf < -1 && node->Data < Root->RightChild->Data)
        {
            cout << " Right Left Roation (RL) with Balance Factor " << bf   << endl;
            Root->RightChild = RightRotaion(Root->RightChild);
            return LeftRotaion(Root);
        }
       
        else if (bf > 1 && node->Data > Root->LeftChild->Data)
        {
            cout << " Left Right Roation (LR) with Balance Factor = " << bf   << endl;
           Root->LeftChild = LeftRotaion(Root->LeftChild);
            return RightRotaion(Root);
        }
       
        return Root;
       
    }
    
    void PrintPrices(int x,int y,Node*Root)
    {
        
        if(Root == nullptr)
        {
            return ;
        }
        
         if(Root->Data > x)
        {
            PrintPrices(x,y,Root->LeftChild);
        }
        
         if(Root->Data >=  x && Root->Data <= y)
        {
            cout << Root->Data << " ";
        }
        
        if(Root->Data < y)
        {
            PrintPrices(x,y,Root->RightChild);
        }
        
    }
    
   
    
    int Height(Node * Root)
    {
        if(Root == nullptr)
        {
            return 0;
        }
       
        else
        {
            int heightr = Height(Root->RightChild);
            int heightl = Height(Root->LeftChild);
            if(heightr > heightl)
            {
                return heightr +1;
            }
            else
            {
                return heightl +1;
            }
        }
    }
    
    void Print(Node * Root)
    {
        if(Root == nullptr)
        {
            return;
        }
        
        Print(Root->LeftChild);
        cout << " " << Root->Data;
        Print(Root->RightChild);
        
    }
   
   
   
};

int main()
{
    AvlTree avl;
    Node * n1 = new Node(9);
    Node * n2 = new Node(8);
    Node * n3 = new Node(5);
    Node * n4 = new Node(4);
    Node * n5 = new Node(12);
    Node * n6 = new Node(15);
    Node * n7 = new Node(7);
   avl.Root = avl.InsertNode(avl.Root, n1);
    avl.Root = avl.InsertNode(avl.Root, n2);
    avl.Root = avl.InsertNode(avl.Root, n3);
    avl.Root = avl.InsertNode(avl.Root, n4);
    avl.Root = avl.InsertNode(avl.Root, n5);
    avl.Root = avl.InsertNode(avl.Root, n6);
    avl.Root = avl.InsertNode(avl.Root, n7);

    cout << " All Product Prices " << endl;
    avl.Print(avl.Root);
    cout << endl;

    int x, y;
    cout << " Enter X :  " << endl;
    cin >> x;
    cout << "Enter Y : " << endl;
    cin >> y;

    cout << " Prices between " << x << " and " << y << ": ";
    avl.PrintPrices(x, y, avl.Root);
    cout << endl;

    return 0;
}
