#include <iostream>

using namespace std;

class Queue
{
    int Size;
    int *arr;
    int head;
    int rear;

public:
    Queue(int _size)
    {
        Size = _size;
        head = rear = -1;
        arr = new int[Size]{0};
    }

    int isempty()
    {
        if(head == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int isfull()
    {
        if(Size == rear)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    int Enqueue(int data)
    {
        if(isfull())
        {
            cout<<"Overload"<<endl;
        }
        else
        {
            if(rear < Size)
            {
                arr[rear] = data;
                rear++;
            }
        }
    }

    int dequeue()
    {
        if(isempty())
        {
            cout<<"underload"<<endl;
        }
        else
        {
            if(rear > -1)
            {
                int num = arr[head];
                for(int i=0; i<Size; i++)
                {
                    arr[i-1] = arr[i];
                }
                rear--;
                cout<<num<<endl;
            }
        }
    }

    void display()
    {
        for(int i=head; i<Size; i++)
        {
            cout<<arr[i]<<endl;
        }
    }

    ~Queue()
    {
        delete[] arr;
    }

};//end class

int main()
{
    Queue q(5);

    q.dequeue();//underload
    q.Enqueue(5);
    q.Enqueue(7);
    q.Enqueue(10);


    q.dequeue();//5
    q.dequeue();//7
    q.Enqueue(11);
    q.dequeue();//10
    q.dequeue();//11

    q.dequeue();//underload
    q.display();

    return 0;
}
