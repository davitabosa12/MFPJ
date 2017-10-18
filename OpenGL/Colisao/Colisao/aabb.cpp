#include "aabb.h"
#include <iostream>

AABB::AABB(Vec2 min, Vec2 max)
{
    this->min = min;
    this->max = max;
}

AABB::AABB(std::vector<Vec2 > points)
{
    //TODO: essa desgraça
}

bool AABB::intercepts(AABB& other)
{
    std::cout << "other: " << other.getMin().getX() << ", " << other.getMin().getY() << std::endl;

    if(this->max.getX() < other.getMin().getX() || this->min.getX() > other.getMax().getX()) return false;
    if(this->max.getY() < other.getMin().getY() || this->min.getY() > other.getMax().getY()) return false;

    //else
    return true;
}
void AABB::setMin(Vec2 v)
{
    this->min = Vec2(v);
}

void AABB::setMax(Vec2 v)
{
    this->max = Vec2(v);
}

bool AABB::intercepts(OBB& other)
{
    return other.intercepts(*this);
}

bool AABB::intercepts(Circle& other)
{
    return other.intercepts(*this);
}
void AABB::print(AABB other)
{
    std::cout << "Ponto minimo: " << other.getMin().getX() << "," << other.getMin().getY() << std::endl;
    std::cout << "Ponto maximo: " << other.getMax().getX() << "," << other.getMax().getY() << std::endl;
}

AABB::~AABB()
{
    //dtor
}

AABB::AABB(const AABB& other)
{
    this->min = other.getMin();
    this->max = other.getMax();
}


Vec2 AABB::getMin() const
{
    return min;
}

Vec2 AABB::getMax() const
{
    return max;
}
Vec2 AABB::closestAABBPoint(const Vec2& p)
{
    double closeX =p.getX(), closeY = p.getY();

    if(closeX < min.getX())
        closeX = min.getX();
    else if(closeX > max.getX())
        closeX = max.getX();

    if(closeY < min.getY())
        closeY = min.getY();
    else if(closeY > max.getY())
        closeY = max.getY();

    return Vec2(closeX,closeY);
}
