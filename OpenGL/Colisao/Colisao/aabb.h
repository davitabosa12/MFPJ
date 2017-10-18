#include "shapes.h"

#ifndef AABB_H
#define AABB_H
#include "circle.h"
/*
 * AABB class with extreme points
 *
*/
class AABB
{
    public:
        AABB(Vec2 min, Vec2 max);
        AABB(std::vector<Vec2> points);
        virtual ~AABB();
        //copy ctor
        AABB(const AABB& other);
        Vec2 closestAABBPoint(const Vec2& p);
        bool intercepts(AABB& other);
        bool intercepts(OBB& other);
        bool intercepts(Circle& other);
        void print(AABB other);

        //G&S
        Vec2 getMin() const;
        Vec2 getMax() const;
        void setMin(Vec2 v);
        void setMax(Vec2 v);
    protected:
    private:
        double minX;
        double minY;
        double maxX;
        double maxY;
        Vec2 min;
        Vec2 max;
};

#endif // AABB_H
