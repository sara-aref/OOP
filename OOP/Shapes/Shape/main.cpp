#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;


class Point
{
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void set_x(int _x)
    {
        x = _x;
    }

    void set_y(int _y)
    {
        y = _y;
    }

    void setxy(int _x, int _y)
    {
        x = _x;
        y = _y;
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
};

class Shape
{
protected:
    int color;
    Point p1;
    Point p2;

public:
    Shape() : p1(50, 100), p2(200, 300)
    {

    }

    Shape(int plx, int ply, int prx, int pry)
    {
        p1.setxy(plx, ply);
        p2.setxy(prx, pry);
    }

    virtual void drawShape() = 0;
};

class Line : public Shape
{
public:
    Line(int plx, int ply, int prx, int pry) : Shape(plx, ply, prx, pry)
    {
        cout << "Line" << endl;
    }

    void drawShape()
    {
        setcolor(3);
        line(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
    }
};

class Rec : public Shape
{
public:
    Rec(int plx, int ply, int prx, int pry) : Shape(plx, ply, prx, pry)
    {
        cout << "Rectangle" << endl;
    }

    void drawShape()
    {
        setcolor(2);
        rectangle(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
    }
};

class Circle : public Shape
{
    int r;

public:
    Circle(int plx, int ply, int radius) : Shape(plx, ply, plx + radius, ply + radius), r(radius)
    {
        cout << "Circle" << endl;
    }

    void drawShape()
    {
        setcolor(4);
        circle(p1.get_x(), p1.get_y(), r);
    }
};

int main() {
    int num = 0, nos = 0;
    int pl1 = 0, pl2 = 0, pr1 = 0, pr2 = 0, r = 0;

    cout << "Enter the number of shapes: ";
    cin >> num;

    Shape* shapes[num];

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int i = 0; i < num; i++)
    {
        cout << "Choose the shape: " << endl;
        cout << "1- Line" << endl;
        cout << "2- Rectangle" << endl;
        cout << "3- Circle" << endl;
        cin >> nos;

        switch (nos)
        {
            case 1:
            {
                cout << "Enter point 1 (x,y): " << endl;
                cin >> pl1 >> pl2;
                cout << "Enter point 2 (x,y): " << endl;
                cin >> pr1 >> pr2;
                Line* L = new Line(pl1, pl2, pr1, pr2);
                shapes[i] = L;
                break;
            }
            case 2:
            {
                cout << "Enter point 1 (x,y): " << endl;
                cin >> pl1 >> pl2;
                cout << "Enter point 2 (x,y): " << endl;
                cin >> pr1 >> pr2;
                Rec* r = new Rec(pl1, pl2, pr1, pr2);
                shapes[i] = r;
                break;
            }
            case 3:
            {
                cout << "Enter point (x,y): " << endl;
                cin >> pl1 >> pl2;
                cout << "Enter radius: " << endl;
                cin >> r;
                Circle* c = new Circle(pl1, pl2, r);
                shapes[i] = c;
                break;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        shapes[i]->drawShape();
    }

    getch();
    closegraph();

    for (int i = 0; i < num; i++)
    {
        delete shapes[i];
    }


    return 0;
}
