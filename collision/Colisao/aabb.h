#ifndef AABB_H
#define AABB_H

/*
 * AABB class with extreme points
 *
*/
class AABB
{
    public:
        AABB(double minX, double minY, double maxX, double maxY);
        AABB(std::vector<Vec2&> points);
        virtual ~AABB();
        //copy ctor
        AABB(const AABB& other);

        bool intercepts(const AABB other);
        bool intercepts(const OBB other);
        bool intercepts(const Circle other);

        //G&S
        double GetminX() { return minX; }
        void SetminX(double val) { minX = val; }
        double GetminY() { return minY; }
        void SetminY(double val) { minY = val; }
        double GetmaxX() { return maxX; }
        void SetmaxX(double val) { maxX = val; }
        double GetmaxY() { return maxY; }
        void SetmaxY(double val) { maxY = val; }
    protected:
    private:
        double minX;
        double minY;
        double maxX;
        double maxY;
};

#endif // AABB_H
