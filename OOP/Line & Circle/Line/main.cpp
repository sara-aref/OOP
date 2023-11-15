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
    void paint()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
    }

};

class Line{

    Point pl,pr;

    public :
    Line():pl(50,100),pr(200,300)
    {

    }

    Line(int plx,int ply, int prx,int pry)
    {
         pl.setxy(plx,ply);
         pr.setxy(prx,pry);
    }

    void draw_Line()
    {
        int gd  = DETECT , gm;
        initgraph(&gd,&gm,(char*)"");
        line(pr.get_x(),pr.get_y(),pl.get_x(),pl.get_y());
        getch();
        closegraph();
    }

    ~Line(){
    }
};


int main()
{
    Line L(50,20,60,40);

    L.draw_Line();

    return 0;
}
