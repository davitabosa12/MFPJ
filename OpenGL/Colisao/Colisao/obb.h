#ifndef OBB_H
#define OBB_H
#include "shapes.h"
#include "circle.h"
#include "aabb.h"
class OBB
{
    public:
        OBB(Vec2 axisX, Vec2 axisY, Vec2 center, Vec2 hDist);
        Vec2 getAxisX() const;
        Vec2 getAxisY() const;
        Vec2 getCenter() const;
        Vec2 gethDist() const;
        bool intercepts(const Circle& c);
        bool intercepts(const AABB& a);
        Vec2 closestOBBPoint(const Vec2& point);
        ~OBB();
    protected:
    private:

        Vec2 axisX;
        Vec2 axisY;
        Vec2 center;
        Vec2 hDist; //metade da dist entre as medidas

};

#endif // OBB_H
