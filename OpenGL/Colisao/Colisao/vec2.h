#ifndef VEC2_H
#define VEC2_H


class Vec2
{
    public:
        Vec2(double x, double y);
        Vec2();
        Vec2(const Vec2& v);
        virtual ~Vec2();

        double getX() const;
        double getY() const;
        void   setX(double val);
        void   setY(double val);
        Vec2 add(const Vec2& v) const;
        Vec2 mult(double s) const;
        Vec2 projection(const Vec2& v) const;
        Vec2 normalize() const;
        double scross(const Vec2& b) const;
        double angleBetween(const Vec2& v) const;
        double dot(Vec2 v) const;
        double magSq() const;
        Vec2 subtr(Vec2 v) const;

    protected:

    private:
        double x;
        double y;
};

#endif // VEC2_H
