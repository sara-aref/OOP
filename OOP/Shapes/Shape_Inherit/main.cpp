#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

class Point
{
    int x;
    int y;
public :
    Point()
    {
        x=0;
        y=0;
    }
    Point(int _x,int _y)
    {
        x= _x;
        y= _y;
    }

    void set_x(int _x)
    {
        x=_x;
    }
    void set_y(int _y)
    {
        y=_y;
    }
    void setxy(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }

    ~Point()
    {

    }
};//end class point

class Shape
{

protected:
    int color;
    Point p1,p2;

public:

    Shape():p1(50,100),p2(200,300)
    {

    }

    Shape(int plx,int ply, int prx,int pry)
    {
         p1.setxy(plx,ply);
         p2.setxy(prx,pry);
    }

    void setcolor(int color)
    {
        setcolor(color);
    }
    void drawShape()
    {

    }

};//end class shape

class Line:public Shape
{
public:
    Line(int plx,int ply, int prx,int pry)
    {
        cout<<"Line"<<endl;
    }


    void drawShape()
    {
        line(p1.get_x(),p1.get_y(),p2.get_x(),p2.get_y());
    }
};//end class line

class Rec:public Shape
{
public:
    Rec(int plx,int ply, int prx,int pry)
    {
        cout<<"Rectangle"<<endl;
    }

    void drawShape()
    {
        rectangle(p1.get_x(),p1.get_y(),p2.get_x(),p2.get_y());
    }
};//end class rectangle

class Circle:public Shape
{
private:
    int radius;

public:
    Circle(int plx, int ply, int r)
    {
        radius = r;
        cout <<"Circle"<< endl;
    }

    void drawShape()
    {
        circle(p1.get_x(),p1.get_y(),radius);
    }
};//end class circle

int main()
{
    int num = 0, nos = 0, i = 0;
    int pl1 = 0, pl2 = 0, pr1 = 0, pr2 = 0, r = 0;

    cout<<"Enter the number of the Shapes: ";
    cin>>num;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for(i=0; i<num; i++)
    {
        cout<<"Choose the Shape: "<<endl;
        cout<<"1- Line"<<endl;
        cout<<"2- Rectangle"<<endl;
        cout<<"3- Circle"<<endl;
        cin>>nos;

        switch(nos)
        {
            case 1:
                {
                    cout<<"Enter point 1 (x,y): "<<endl;
                    cin>>pl1>>pl2;
                    cout<<"Enter point 2 (x,y): "<<endl;
                    cin>>pr1>>pr2;
                    Line L(pl1,pl2,pr1,pr2);
                    setcolor(3);
                    L.drawShape();
                    break;
                }
            case 2:
                {
                    cout<<"Enter point 1 (x,y): "<<endl;
                    cin>>pl1>>pl2;
                    cout<<"Enter point 2 (x,y): "<<endl;
                    cin>>pr1>>pr2;
                    Rec r(pl1,pl2,pr1,pr2);
                    setcolor(2);
                    r.drawShape();
                    break;
                }
            case 3:
                {
                    cout<<"Enter point 1 (x,y): "<<endl;
                    cin>>pl1>>pl2;
                    cout<<"Enter radius: "<<endl;
                    cin>>r;
                    Circle c(pl1,pl2,r);
                    setcolor(4);
                    c.drawShape();
                    break;
                }
        }
    }

    getch();
    closegraph();
    return 0;
}
