#include <iostream>

using namespace std;

template <class H>

class Stack
{
    int Size;
    int top;
    H *arr;


public:
    Stack(int _Size)
    {
        Size = _Size;
        top = -1;
        arr = new H[Size]{0};
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

    H push(H data)
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

    H pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            if(top > -1)
            {
                H num = arr[top];
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
    Stack <char>S(5);


    //S2.pop();//empty
    S.push('j');
    S.push('k');
    S.push('l');
    S.pop();//6.3
    S.pop();//5.2
    S.push('t');
    S.pop();//7.9
    // S.pop();//1
    //S.pop();//Empty
    S.push('e');
    S.pop();//7.7
    S.pop();//1.5

    //S.display();
    //S2.display();


    return 0;

}
