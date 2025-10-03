#include<iostream>
using namespace std;

class Queue
{
    private:
    int Size;
    int Front;
    int Rear;
    int * arr;

    public:
    Queue(int size)
    {
        Size = size;
        Front = -1;
        Rear = -1;
        arr = new int[Size];
    }

     bool IsFull()
    {
        if(Rear == Size-1)
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
           
        }
        else
        {
            if(Front == -1)
            {
                Front = 0;
            }
            Rear++;
            arr[Rear] = x;
        }
    }

    void Dequeue()
    {
        if(isEmpty())
        {
            cout << " Cant Deque now " << endl;
           
        }
        else
        {
            int x = arr[Front];
            cout << " X : " << x << " poped out " << endl;
            Front++;
            if(Front > Rear)
            {
                Front = -1;
                Rear = -1;
            }
        }
    }

    void Display()
    {
        if(isEmpty())
        {
            cout << " Queue Is Empty " << endl;
            return;
        }
        
        for(int y = Front; y <= Rear;y++)
        {
            cout << "  " << arr[y] << endl;
        }
    }



};

int main()
{
    Queue queue(4);
    queue.Enqueue(12);
    queue.Enqueue(10);
    queue.Enqueue(15);

    cout << " Displaying  Original Elements " << endl;
    queue.Display();

    queue.Dequeue();

    cout << " Displaying   Elements " << endl;
    queue.Display();




}
