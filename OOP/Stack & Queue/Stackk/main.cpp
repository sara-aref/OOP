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
    /*int data;
    int Size;
    cout << "Enter Size: \n";
    cin >> Size;*/

    Stack S(5);

    S.pop();//empty
    S.push(1);
    S.push(5);
    S.push(6);
    S.pop();//6
    S.pop();//5
    S.push(7);
    //S.pop();//7
   // S.pop();//1
    //S.pop();//Empty
    S.push(7);
    //S.pop();//7

    S.display();

    /*for(int i =0; i<Size; i++)
    {
        cout << "Enter the num: \n";
        cin >> data;
        S.push(data);
    }

    S.display();

    cout << "num to pop: "<<S.pop()<<endl;
    cout << "num to pop: "<<S.pop()<<endl;
    cout << "num to pop: "<<S.pop()<<endl;
    cout << "num to pop: "<<S.pop()<<endl;
    cout << "num to pop: "<<S.pop()<<endl;*/

    return 0;

}
