#include <iostream>
using namespace std;


class complexNum
{
    private:
        int realNum;
        int imaginaryNum;

    public:

        complexNum(int _realNum = 0, int _imaginaryNum = 0)
        {
            realNum = _realNum;
            imaginaryNum = _imaginaryNum;
        }

        complexNum(complexNum &c)
        {
            realNum = c.realNum;
            imaginaryNum = c.imaginaryNum;
        }

        void setReal(int realnumber)
        {
            realNum = realnumber;
        }
        int getReal() const
        {
            return realNum;
        }
        void setImaginary(int imaginarynumber)
        {
            imaginaryNum = imaginarynumber;
        }
        int getImaginary() const
        {
            return imaginaryNum;
        }

        complexNum operator +(const complexNum &c)
        {
            complexNum res(realNum+c.realNum, imaginaryNum+c.imaginaryNum);
            /*complexNum res;
            res.realNum = realNum + c.realNum;
            res.imaginaryNum = imaginaryNum + c.imaginaryNum;*/
            return res;
        }

        complexNum operator -(const complexNum &c)
        {
            complexNum res(realNum-c.realNum, imaginaryNum-c.imaginaryNum);
            /*complexNum res;
            res.realNum = realNum - c.realNum;
            res.imaginaryNum = imaginaryNum - c.imaginaryNum;
            */
            return res;
        }

        complexNum operator +(int x)
        {
            complexNum res;
            res.realNum = realNum + x;
            res.imaginaryNum = imaginaryNum;
            return res;
        }

        complexNum operator -(int x)
        {
            complexNum res;
            res.realNum = realNum - x;
            res.imaginaryNum = imaginaryNum;
            return res;
        }

        complexNum operator +=(const complexNum &c)
        {
            realNum = realNum + c.realNum;
            imaginaryNum = imaginaryNum + c.imaginaryNum;
            return *this;
        }

        int operator ==(const complexNum &c)
        {
            return (realNum == c.realNum && imaginaryNum == c.imaginaryNum);
        }

        complexNum operator ++()
        {
            realNum = realNum +1;
            return *this;
        }

        complexNum operator --()
        {
            realNum = realNum -1;
            return *this;
        }

        complexNum operator ++(int)
        {
            complexNum temp = *this;
            realNum = realNum +1;
            return temp;
        }

        complexNum operator --(int)
        {
            complexNum temp = *this;
            realNum = realNum -1;
            return temp;
        }

        operator float()
        {
            return realNum;
        }

        int operator [](int num)
        {
            if(0 == num)
            {
                return realNum;
            }
            if(1 == num)
            {
                return imaginaryNum;
            }
        }

        int operator [](string x)
        {
            if("real" == x)
            {
                return realNum;
            }
            if("img" == x)
            {
                return imaginaryNum;
            }
        }


        friend istream& operator>>(istream& cin, complexNum& c);
        friend ostream& operator<<(ostream&, complexNum& c);

        void print(void);

};//end class

istream& operator>>(istream& Cin, complexNum& c)
{
    Cin >> c.realNum;
    Cin >> c.imaginaryNum;
    return Cin;
}

ostream& operator<<(ostream& Cout, complexNum& c)
{
    Cout << c.realNum << "+" << c.imaginaryNum <<"j";
    return Cout;
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

complexNum operator +(int x, const complexNum &c);
complexNum operator -(int x, const complexNum &c);

int main()
{
    complexNum c1(20,10);
    complexNum c2(10);
    complexNum c3;

    cout<<"---------------+-------------"<<endl;
    c3 = c1 + c2;
    c3.print();

    cout<<"---------------(-)-----------"<<endl;
    c3 = c1 - c2;
    c3.print();

    cout<<"---------------+int----------"<<endl;
    c3 = c1 + 5;
    c3.print();

    cout<<"---------------(-)int--------"<<endl;
    c3 = c1 - 5;
    c3.print();

    cout<<"---------------int+----------"<<endl;
    c3 = 5 + c1;
    c3.print();

    cout<<"---------------int(-)--------"<<endl;
    c3 = 5 - c1;
    c3.print();

    cout<<"---------------==------------"<<endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;

    cout<<"---------------+=------------"<<endl;
    c1 += c2;
    c1.print();

    cout<<"---------------++------------"<<endl;
    ++c1;
    c1.print();

    cout<<"---------------(--)----------"<<endl;
    --c1;
    c1.print();

    cout<<"---------------++------------"<<endl;
    c1++;
    c1.print();

    cout<<"---------------(--)----------"<<endl;
    c1--;
    c1.print();

    cout<<"---------------[]----------"<<endl;
    cout << c1[0]<< endl;

    cout<<"---------------[]----------"<<endl;
    cout << c1["img"]<< endl;

    cout<<"--------------->>----------"<<endl;
    complexNum c4;
    cin >> c4;

    cout<<"---------------<<----------"<<endl;
    cout<< c4;
    return 0;
}

complexNum operator +(int x, const complexNum &c)
{
        complexNum res(c.getReal()+x, c.getImaginary());
        return res;
}

complexNum operator -(int x, const complexNum &c)
{
        complexNum res(c.getReal()-x, c.getImaginary());
        return res;
}

