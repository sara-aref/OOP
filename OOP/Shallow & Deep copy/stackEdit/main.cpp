#include <iostream>

using namespace std;

class Stack
{
    int Size;
    int top;
    int *arr;


public:
    Stack(int _Size)
    {
        Size = _Size;
        top = -1;
        arr = new int[Size]{0};
    }

    Stack(Stack &stc)
    {
        Size = stc.Size;
        top = stc.top;
        arr = new int[Size];
        for(int i=0; i<=top; i++)
        {
            arr[i] = stc.arr[i];
        }
    }


    int getTop()
    {
        return top;
    }

    int isfull()
    {
        if(top == Size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int isempty()
    {
        if(-1 == top)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int push(int data)
    {
        if(isfull())
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            if(top < Size)
            {
                top++;
                arr[top] = data;
            }
        }
    }

    int pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            if(top > -1)
            {
                int num = arr[top];
                top--;
                cout<<num<<endl;
            }
        }
    }

    void display()
    {
       cout<<"----------Display------------- "<<endl;

        if(!isempty())
        {
            for(int i=top; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }
        else{
            cout<<"No Element for Display "<<endl;
        }
    }


    ~Stack()
    {
        delete[] arr;
    }
};



int main()
{
    Stack S(5);

    Stack S2 = S;

    S2.pop();//empty
    S2.push(1);
    S2.push(5);
    S2.push(6);
    S2.pop();//6
    S2.pop();//5
    S2.push(7);
    //S.pop();//7
   // S.pop();//1
    //S.pop();//Empty
    S2.push(7);
    S2.pop();//7
    S2.pop();//7

    //S.display();
    //S2.display();


    return 0;

}
