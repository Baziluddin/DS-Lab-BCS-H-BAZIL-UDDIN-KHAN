#include <iostream>
using namespace std;

class CircularQueue
{
    private:

    int Top;
    int Rear;
    int Front;
    int Size;
    int * arr;

    public:
    CircularQueue(int size)
    {
        Size = size;
     
        Front = -1;
        Rear = -1;
        arr = new int[Size];
    }

    bool IsFull()
    {
       
         if((Rear + 1) % Size == Front)
        {
           return true;
        }
        else
        {
            return false;
        }

    }

    bool isEmpty()
    {
        if(Front == -1)
        {
           return true;
        }
        else
        {
            return false;
        }

    }

    void Enqueue(int x)
    {
        if(IsFull())
        {
            cout << " Cant Enque now " << endl;
            return;
        }

        if(isEmpty())
        {
            Front =0;
            Rear = 0;

        }
        else{
            Rear = (Rear+1)% Size;
        }

        arr[Rear] = x;

    }

    void Dequeue()
    {
        if(isEmpty())
        {
            cout << " Cant Deque now " << endl;
            return;
        }

        int val = arr[Front];
        if(Front == Rear)
        {
            Front = -1;
            Rear = -1;
        }
        else
        {
            Front = (Front + 1) % Size;

        }

        cout << " Succesfully Removed val : " << val << endl;
    }

    void Display()
    {
        int index = Front;
        while(1)
        {
            cout << "  " << arr[index] << " ";
            if(index == Rear)
            {
                break;
            }
            index = (index + 1) % Size;
        }
        cout << endl;
    }
    
    ~CircularQueue()
    {
       delete[] arr;

    }

};

int main()
{
    CircularQueue queue(3);

    queue.Enqueue(90);
   queue.Enqueue(80);
   queue.Enqueue(34);


    queue.Display();

    queue.Dequeue();

    queue.Display();

    return 0;

}
