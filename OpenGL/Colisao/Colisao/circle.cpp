#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(Vec2 v, double r)
{
    center = v;
    radius  = r;
}

Circle::~Circle()
{
    //dtor
}

 Circle::Circle(std::vector<Vec2> points)
 {
    int min, max;
    compute(min,max,points);
    this->center = points.at(min).add(points.at(max));
    this->center = center.mult(0.5);
    Vec2 temp = points.at(max).subtr(center);
    this->radius = temp.dot(temp);
    radius = sqrt(radius);
 }
void Circle::compute(int &min, int &max, std::vector<Vec2> points){
    int xMin = 0, xMax = 0;
    int yMin = 0, yMax = 0;
    for(int i = 0; i < points.size(); i++){
        if(points.at(i).getX() < xMin) xMin = i;
        if(points.at(i).getX() > xMax) xMax = i;
        if(points.at(i).getY() < yMin) yMin = i;
        if(points.at(i).getY() > yMax) yMax = i;
    }
    Vec2 tempx = points.at(xMax).subtr(points.at(xMin));
    Vec2 tempy = points.at(yMax).subtr(points.at(yMin));
    double dist2x = tempx.dot(tempx);
    double dist2y = tempy.dot(tempy);
    min = xMin, max = xMax;
    if (dist2y > dist2x) {
        max = yMax;
        min = yMin;
    }

}
 bool Circle::intercepts(Circle& other)
 {
    Vec2 dist = center.subtr(other.getCenter());
    double dist2 = dist.dot(dist);

    double rSum = radius + other.getRadius();
    return dist2 <= rSum*rSum;
 }

 bool Circle::intercepts(AABB& aabb)
 {
    double closeX = this->center.getX(), closeY = this->center.getY();

    if(center.getX() < aabb.getMin().getX())
        closeX = aabb.getMin().getX();
    else if(center.getX() > aabb.getMax().getX())
        closeX = aabb.getMax().getX();

    if(center.getY() < aabb.getMin().getY())
        closeY = aabb.getMin().getY();
    else if(center.getY() > aabb.getMax().getY())
        closeY = aabb.getMax().getY();

    Vec2 dist = center.subtr(Vec2(closeX, closeY));
    std::cout << "Dist2: " << dist.magSq() <<std::endl;
    return dist.magSq() <= radius * radius; //detecta borda
    //return dist.magSq() < radius * radius //nao detecta borda

 }

 bool Circle::intercepts(OBB& other)
 {
    return other.intercepts(*this);
 }
 Vec2 Circle::getCenter()const
 {
     return center;
 }

 double Circle::getRadius()const
 {
    return radius;
 }

 void Circle::setCenter(Vec2 val)
 {
    this->center =  val;
 }

 void Circle::setRadius(double val)
 {
    this->radius = val;
 }
Vec2 Circle::closestCirclePoint(const Vec2& p){
    double theta = atan2(center.getY() - p.getY(),center.getX() - p.getX());
    double newX = p.getX(), newY = p.getY();

	double dx = center.getX() - p.getX();
    double dy = center.getY() - p.getY();
    double dist = sqrt(dx*dx + dy*dy);

    if(newX * newX > dist)
        newX = center.getX() - dx * radius / dist;
    if(newY*newY > dist)
        newY = center.getY() - dy * radius / dist;

    return Vec2(newX,newY);
}
