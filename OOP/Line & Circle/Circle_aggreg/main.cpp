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


class Circle{

    Point *p1;
    int r;

    public :
    Circle()
    {
        p1 = NULL;
        r = 0;
    }

    Circle(Point *px, int r)
    {
         p1 = px;
         r = 0;
    }

    void drawCircle(Point *p1, int r)
    {
        int gd  = DETECT , gm;
        initgraph(&gd,&gm,(char*)"");
        circle(p1->get_x(),p1->get_y(),r);
        getch();
        closegraph();
    }

    ~Circle(){
    }
};


int main()
{
    int r = 20;
    Point p(50,50);

    Circle C;
    C.drawCircle(&p,r);

    return 0;
}
