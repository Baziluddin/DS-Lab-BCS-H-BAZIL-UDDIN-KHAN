#include <iostream>
using namespace std;

class Node
{
    public:
    int SeverityLevel;
    Node * LeftChild;
    Node * RightChild;
    int Height;
   
    Node(int d)
    {
        SeverityLevel = d;
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
       
        else if(Root->SeverityLevel > node->SeverityLevel)
        {
            Root->LeftChild = InsertNode(Root->LeftChild,node);
        }
       
        else if(Root->SeverityLevel < node->SeverityLevel)
        {
            Root->RightChild = InsertNode(Root->RightChild,node);
        }
        else
        {
            return Root;
        }
        
        
        Root->Height = 1 + max(GetHeight(Root->LeftChild),GetHeight(Root->RightChild));
       
        int bf = GetBf(Root);
        cout << "Balance Factor of node " << Root->SeverityLevel << " = " << bf << endl;
       
     
       
        if (bf > 1 && node->SeverityLevel < Root->LeftChild->SeverityLevel)
        {
            cout << " Right Roation (LL) with Balance Factor On Patient Tree  = " << bf  << endl;
            return RightRotaion(Root);
        }
       
        else if (bf < -1 && node->SeverityLevel > Root->RightChild->SeverityLevel)
        {
            cout << " Left Roation (RR) with Balance Factor On Patient Tree = " << bf  << endl;
            return LeftRotaion(Root);
        }
       
        else if (bf < -1 && node->SeverityLevel < Root->RightChild->SeverityLevel)
        {
            cout << " Right Left Roation (RL) with Balance Factor On Patient Tree = " << bf   << endl;
            Root->RightChild = RightRotaion(Root->RightChild);
            return LeftRotaion(Root);
        }
       
        else if (bf > 1 && node->SeverityLevel > Root->LeftChild->SeverityLevel)
        {
            cout << " Left Right Roation (LR) with Balance Factor On Patient Tree = " << bf   << endl;
           Root->LeftChild = LeftRotaion(Root->LeftChild);
            return RightRotaion(Root);
        }
       
        return Root;
       
    }
   
    Node * Min(Node * node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
       
        if(node->LeftChild != nullptr)
        {
            return Min(node->LeftChild);
        }
       
        else{
            return node;
        }
    }
    
    Node * MaxSeverse(Node * node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
       
        if(node->RightChild != nullptr)
        {
            return MaxSeverse(node->RightChild);
        }
       
        else
        {
            return node;
        }
        
    }
   
    Node * Delete(Node * Root , Node * node)
    {
        if(Root == nullptr)
        {
            return nullptr;
        }
       
        else if(Root->SeverityLevel > node->SeverityLevel)
        {
            Root->LeftChild = Delete(Root->LeftChild,node);
        }
       
        else if(Root->SeverityLevel < node->SeverityLevel)
        {
            Root->RightChild = Delete(Root->RightChild,node);
        }
       
        else
        {
           if (Root->LeftChild == nullptr && Root->RightChild == nullptr)
            {
                delete Root;
                return nullptr;
            }
           
           
            else if(Root->LeftChild == nullptr )
            {
                Node * Temp = Root->RightChild;
                delete Root;
                return Temp;
               
            }
           
            else if(Root->RightChild == nullptr )
            {
                Node * Temp = Root->LeftChild;
                delete Root;
                return Temp;
               
            }
           
            else
            {
                Node * mi = Min(Root->RightChild);
                Root->SeverityLevel = mi->SeverityLevel;
               
                Root->RightChild = Delete(Root->RightChild,mi);
            }
        }
        
        Root->Height = 1 + max(GetHeight(Root->LeftChild),GetHeight(Root->RightChild));
       
        int bf = GetBf(Root);
        cout << "Balance Factor after deletion at node " << Root->SeverityLevel << " = " << bf << endl;
       
        if(bf > 1 && GetBf(Root->LeftChild) >=0)
        {
          cout << "Right Rotation (RR) performed during deletion."<< endl;

            return  RightRotaion(Root);
        }
       
        else if(bf < -1 && GetBf(Root->RightChild) <=0)
        {
         cout << "Left Rotation (LL) performed during deletion." << endl;


            return LeftRotaion(Root);
        }
       
        else if(bf > 1 && GetBf(Root->LeftChild) < 0)
        {
              Root->LeftChild = LeftRotaion(Root->LeftChild);
               cout << "Left Rotation on LeftChild (LR Step 1) during deletion." << endl;
               cout << "Right Rotation (LR Step 2) during deletion."<< endl;
             return RightRotaion(Root);
        }
       
        else if(bf < -1 && GetBf(Root->RightChild) > 0)
        {
              Root->RightChild = RightRotaion(Root->RightChild);
               cout << "Right Rotation on RightChild (RL Step 1) during deletion."<< endl;
               cout << "Left Rotation (RL Step 2) during deletion."<< endl;

              return LeftRotaion(Root);
        }
       
        return Root;
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
        cout << " " << Root->SeverityLevel;
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
    avl.Root = n1;
    avl.Print(avl.Root);
    cout << " Avl Height Is " << avl.Height(avl.Root) << endl;
    avl.Root = avl.InsertNode(avl.Root,n2);
    avl.Print(avl.Root);
    cout << " Avl Height Is " << avl.Height(avl.Root) << endl;
    
 avl.Root =    avl.InsertNode(avl.Root,n3);
    avl.Print(avl.Root);
    cout << " Avl Height Is " << avl.Height(avl.Root) << endl;
    
    avl.Root = avl.InsertNode(avl.Root,n4);
    avl.Print(avl.Root);
    cout << " Avl Height Is " << avl.Height(avl.Root) << endl;
    
    avl.Root = avl.Delete(avl.Root, new Node(5));
avl.Root = avl.Delete(avl.Root, new Node(8));
    
    Node* maxNode = avl.MaxSeverse(avl.Root);
    cout << "Max Severe Patient Is " << maxNode->SeverityLevel << endl;
 
 
 
    return 0;
}
