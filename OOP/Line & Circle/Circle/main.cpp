#include <iostream>
#include <stdlib.h>
#include <graphics.h>

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

    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    void setXY(int _x,int _y)
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

    void Paint()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
    }

};

class Circle
{
    Point p;
    int r;

    public :
    Circle():p(5,2)
    {
        r = 0;
    }

    Circle(int px,int py, int radius)
    {
         p.setXY(px,py);
         r = radius;
    }

    void drawCircle()
    {
        p.Paint();
        cout<<r;
        circle(p.get_x(),p.get_y(),r);
    }

    ~Circle(){
    }
};


int main()
{
    int gd  = DETECT , gm;
    initgraph(&gd,&gm,(char*)"");

    Circle C(50,50,100);
    C.drawCircle();

    getch();
    closegraph();


    return 0;
}
