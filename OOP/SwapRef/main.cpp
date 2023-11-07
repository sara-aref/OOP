#include <iostream>
using namespace std;

int swapPoint(int *x, int *y);
int swapRef(int &x, int &y);

int main()
{
    int x=0, y=0;
    cout<<"Enter the first num: "<<endl;
    cin>>x;
    cout<<"Enter the second num: "<<endl;
    cin>>y;

    cout<<endl;
    cout<<"Swap for the first time: "<<endl;
    swapPoint(&x, &y);
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;

    cout<<endl;
    cout<<"Swap for the second time: "<<endl;
    swapRef(x, y);
    cout<<"X = "<<x<<endl;
    cout<<"Y = "<<y<<endl;
    return 0;
}

int swapPoint(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int swapRef(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
