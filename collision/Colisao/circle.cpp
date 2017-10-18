#include "circle.h"

Circle::Circle(double x, double y, double r)
{
    this.centerX = x;
    this.centerY = y;
    this.radius  = r;
}

Circle::~Circle()
{
    //dtor
}

 Circle::Circle(std::vector<Vec2& > points)
 {

 }

 bool Circle::intercepts(const Circle& other)
 {

 }

 bool Circle::intercepts(const AABB& other)
 {

 }

 bool Circle::intercepts(const OBB& other)
 {

 }
 double Circle::getX()
 {
     return this.centerX;
 }

 double Circle::getY()
 {
     return this.centerY;
 }

 double Circle::getRadius()
 {
     return this.radius;
 }

 void Circle::setX(double newX)
 {
    this.centerX = newX;
 }

 void Circle::setY(double newY)
 {
    this.centerY = newY;
 }

 void Circle::setRadius(double newRadius)
 {
    this.radius = newRadius;
 }
