#include "shapes.h"

#ifndef CIRCLE_H
#define CIRCLE_H
#include "aabb.h"
#include "obb.h"

class Circle
{
    public:
        Circle(Vec2 v, double r);
        Circle(std::vector<Vec2> points);
        virtual ~Circle();
        bool intercepts(Circle& other);
        bool intercepts(AABB& other);
        bool intercepts(OBB& other);
        Vec2 getCenter() const;
        double getRadius() const;
        Vec2 closestCirclePoint(const Vec2& p);
        void setCenter(Vec2 val);
        void setRadius(double val);



    protected:
    private:
        void compute(int& min, int& max,std::vector<Vec2> points);
        double radius;
        Vec2 center;
};

#endif // CIRCLE_H
