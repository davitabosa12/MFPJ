#include "aabb.h"

AABB::AABB(double minX, double minY, double maxX, double maxY)
{
    this.minY = minY;
    this.minX = minX;
    this.maxX = maxX;
    this.maxY = maxY;
}

AABB::AABB(std::vector<Vec2& > points)
{

}

bool AABB::intercepts(const AABB other)
{

}

bool AABB::intercepts(const OBB other)
{

}

bool AABB::intercepts(const Circle other)
{

}

AABB::~AABB()
{
    //dtor
}

AABB::AABB(const AABB& other)
{
    //copy ctor
}
