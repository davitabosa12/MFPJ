#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle(double x, double y, double r);
        Circle(std::vector<Vec2&> points);
        virtual ~Circle();
        bool intercepts(const Circle& other);
        bool intercepts(const AABB& other);
        bool intercepts(const OBB& other);

        //G&S
        double getX();
        double getY();
        double getRadius();

        void setX(double newX);
        void setY(double newY);
        void setRadius(double newRadius);
    protected:
    private:
        double radius;
        double centerX;
        double centerY;
};

#endif // CIRCLE_H
