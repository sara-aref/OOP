#include <iostream>
using namespace std;


class complexNum
{
    private:
        int realNum;
        int imaginaryNum;

    public:
        void setReal(int realnumber)
        {
            realNum = realnumber;
        }
        int getReal()
        {
            return realNum;
        }
        void setImaginary(int imaginarynumber)
        {
            imaginaryNum = imaginarynumber;
        }
        int getImaginary()
        {
            return imaginaryNum;
        }

        complexNum add(complexNum com1);
        complexNum sub(complexNum com1);
        void print(void);

};

complexNum complexNum::add(complexNum com1)
{
    complexNum result;
    result.setReal(realNum+com1.getReal());
    result.setImaginary(imaginaryNum+com1.getImaginary());
    return result;
}

complexNum complexNum::sub(complexNum com1)
{
    complexNum result;
    result.setReal(realNum-com1.getReal());
    result.setImaginary(imaginaryNum-com1.getImaginary());
    return result;
}

void complexNum::print(void)
{
    cout<<"The Number: ";
    if(imaginaryNum > 0)
    {
        cout<<realNum <<"+"<<imaginaryNum<<"j"<<endl;
    }
    else if(imaginaryNum < 0)
    {
        cout<<realNum <<imaginaryNum<<"j"<<endl;
    }
    else
    {
        cout<<realNum <<endl;
    }
}


complexNum add(complexNum com1, complexNum com2);
complexNum sub(complexNum com1, complexNum com2);

int main()
{
    int num1=0,num2=0;
    complexNum com1,com2,res;
    complexNum r;

    com1.setReal(12);
    com1.setImaginary(-20);

    com2.setReal(5);
    com2.setImaginary(10);

    res = add(com1,com2);
    res.print();
    res = sub(com1,com2);
    res.print();

    res = com1.add(com2);
    res.print();
    res = com1.sub(com2);
    res.print();

    return 0;
}


complexNum add(complexNum com1, complexNum com2)
{
    complexNum result;
    result.setReal(com1.getReal()+com2.getReal());
    result.setImaginary(com1.getImaginary()+com2.getImaginary());
    return result;
}

complexNum sub(complexNum com1, complexNum com2)
{
    complexNum result;
    result.setReal(com1.getReal()-com2.getReal());
    result.setImaginary(com1.getImaginary()-com2.getImaginary());
    return result;
}
