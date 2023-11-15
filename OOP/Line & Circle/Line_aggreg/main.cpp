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

    void set_x(int _x)
    {
        x=_x;
    }
    void set_y(int _y)
    {
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

    void setxy(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    void paint()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
    }

};

class Line{

    Point *p1, *p2;

    public :
    Line()
    {
        p1 = NULL;
        p2 = NULL;
    }

    Line(Point *px,Point *py)
    {
         p1 = px;
         p2 = py;
    }

//aggregiation
    void draw_Line(Point *p1, Point *p2)
    {
        int gd  = DETECT , gm;
        initgraph(&gd,&gm,(char*)"");
        line(p1->get_x(),p1->get_y(),p2->get_x(),p2->get_y());
        getch();
        closegraph();
    }

    ~Line(){
    }
};


int main()
{
    Point p1(100,200);
    Point p2(600,500);

    Line L;
    L.draw_Line(&p1,&p2);

    return 0;
}
