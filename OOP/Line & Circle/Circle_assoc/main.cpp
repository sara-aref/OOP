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
    ~Point()
    {
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

    Circle(int px,int py, int r)
    {
         p.setXY(px,py);
         r = 0;
    }

    void drawCircle(Point p1, int r)
    {
        p.Paint();
        cout<<r;
        int gd  = DETECT , gm;
        initgraph(&gd,&gm,(char*)"");
        circle(p.get_x(),p.get_y(),r);
        getch();
        closegraph();
    }

    ~Circle(){
    }
};


int main()
{
    Point p(50,50);

    Circle C;
    C.drawCircle(p,30);

    return 0;
}
