#include "point.h"

Point::Point(double x, double y)
{
    //ctor
    this.x = x;
    this.y = y;
}

Point::~Point()
{
    //dtor
}

double getX(); { return x; }
void setX(double val); { x = val; }
double getY(); { return y; }
void setY(double val); { y = val; }
