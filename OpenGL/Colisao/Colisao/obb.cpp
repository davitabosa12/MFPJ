#include "obb.h"
#include<iostream>
#include<cmath>

OBB::OBB(Vec2 axisX, Vec2 axisY, Vec2 center, Vec2 hDist)
{
    this->axisX = axisX;
    this->axisY = axisY;
    this->center = center;
    this->hDist = hDist;
}

Vec2 OBB::getAxisX() const
{
    return axisX;

}

Vec2 OBB::getAxisY() const
{
    return axisY;
}

Vec2 OBB::getCenter() const
{
    return center;
}

Vec2 OBB::gethDist() const
{
    return hDist;
}
bool OBB::intercepts(const Circle& c)
{
    Vec2 closestPoint = this->closestOBBPoint(c.getCenter());

    Vec2 dist = closestPoint.subtr(c.getCenter());
    return dist.magSq() < c.getRadius() * c.getRadius(); //detecta borda
    //return dist.magSq() < radius * radius //nao detecta borda
}
Vec2 OBB::closestOBBPoint(const Vec2& point){
    Vec2 d = point.subtr(center);
    Vec2 q = Vec2(center.getX(),center.getY());
    double distX = d.dot(axisX);
    double distY = d.dot(axisY);
    //std::cout << "distX:" << distX << std::endl;
    //std::cout << "distY:" << distY << std::endl;
    if(distX > hDist.getX()) distX = hDist.getX();
    if(distX < -hDist.getX()) distX = -hDist.getX();

    if(distY > hDist.getY()) distY = hDist.getY();
    if(distY < -hDist.getY()) distY = -hDist.getY();
    //std::cout << "after distX:" << distX << std::endl;
    //std::cout << "after distY:" << distY << std::endl;
    //std::cout << "hdistX:" << hDist.getX() << std::endl;
    //std::cout << "hdistY:" << hDist.getY() << std::endl;
    q = q.add(axisX.mult(distX));
    //std::cout << "q = "<< q.getX() << "," << q.getY() << std::endl;
    q = q.add(axisY.mult(distY));
    return q;


}
bool OBB::intercepts(const AABB& a)
{
    double aabbCenterX = (a.getMax().getX() - a.getMin().getX())/2;
    double aabbCenterY = (a.getMax().getY() - a.getMin().getY())/2;
    Vec2 aabbCenter = Vec2(aabbCenterX,aabbCenterY);
    //

    //pegar ponto mais proximo aabb
    double closeX = this->center.getX(), closeY = this->center.getY();
    if(center.getX() < a.getMin().getX())
        closeX = a.getMin().getX();
    else if(center.getX() > a.getMax().getX())
        closeX = a.getMax().getX();

    if(center.getY() < a.getMin().getY())
        closeY = a.getMin().getY();
    else if(center.getY() > a.getMax().getY())
        closeY = a.getMax().getY();

    Vec2 closestAABB = Vec2(closeX,closeY);
    Vec2 closestOBB = closestOBBPoint(closestAABB);
    //closestOBB = Vec2(closestOBB.getX() + center.getX(), closestOBB.getY() + center.getY());

    if(closestOBB.getX() < a.getMin().getX()) return false;
    if(closestOBB.getX() > a.getMax().getX()) return false;
    if(closestOBB.getY() < a.getMin().getY()) return false;
    if(closestOBB.getY() > a.getMax().getY()) return false;
    return true;




}

OBB::~OBB()
{
    //dtor
}
