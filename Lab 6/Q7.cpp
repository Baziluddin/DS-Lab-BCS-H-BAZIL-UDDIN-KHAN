#include <iostream>
using namespace std;

class Process 
{
public:
    int Id;
    int Priority;
    Process()
    {
        Id = 0;
        Priority =0;
    }
    
    Process(int i, int p) 
    {
       Id = i; 
       Priority = p;
    }
    
};

class Queue 
{
    
private:
    Process* arr;
    int Front;
    int Rear;
    int Size;
    int Capacity;
    
public:

    Queue(int s) 
    {
        arr = new Process[s];
        Front = 0; 
        Rear = -1;
        Size = 0; 
        Capacity = s;
    }
    
    void Enqueue(Process p) 
    { 
        if(Size < Capacity)
        {
            arr[(Rear+1)%Capacity] = p; 
            Rear = (Rear+1)%Capacity; 
            Size++; 
        }
        else
        {
            cout << " Cant Enqueue The Process " << endl;
        }
        
    }
    
    Process Dequeue() 
    { 
         if(Size > 0)
        {
            Process P = arr[Front];
            Front = (Front + 1) % Capacity; 
            Size--;
            
            return P;
        }
        else
        {
            cout << " Cant Enqueue The Process " << endl;
            return Process(-1,-1);
        }
    }
    
    int getSize() 
    { 
        return Size;
    }
    
    bool isEmpty() 
    { 
        if(Size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

class Stack
{
    
private:

    Process* arr;
    int Top;
    int Capacity;
    
public:

    Stack(int S) 
    { 
        arr = new Process[S];
        Top = -1; 
        Capacity = S;
    }
    
    void Push(Process p) 
    { 
        if(Top < Capacity -1)
        {
            arr[++Top] = p; 
        }
        else
        {
            cout << " Cant Push Process " << endl;
        }
        
    }
    
    Process Pop() 
    { 
        if(Top >=0 )
        {
            return arr[Top--]; 
        }
        else
        {
            cout << " No Processes " << endl;
            return Process(-1,-1);
        }
        
    }
    
    bool IsEmpty() 
    {
        if(Top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main()
{
    int N;
    cout << "Enter number of processes =  ";
    cin >> N;

    Queue ArrivalQueue(N);
    
    for(int i = 0; i < N; i++) 
    {
        int id;
        int priority;
        
    cout << " Enter Your Process ID = ";
    cin >> id ;
    cout << " Enter Your Priority =   ";
    cin >> priority;
        
    ArrivalQueue.Enqueue(Process(id, priority));
    }

    Stack ExecStack(N);

   
    while(!ArrivalQueue.isEmpty()) 
    {
        Process P = ArrivalQueue.Dequeue();
        
        if(P.Priority >= 5) 
        {
            ExecStack.Push(P);
        }
        else
        { 
            cout << " Executing low-Priority Process ID: " << P.Id << endl;
        }
    }


    while(!ExecStack.IsEmpty())
    {
        Process O = ExecStack.Pop();
        cout << " Executing high-Priority Process ID: " << O.Id << endl;
    }

    return 0;
}
