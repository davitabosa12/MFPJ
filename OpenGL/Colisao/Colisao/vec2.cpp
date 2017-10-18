#include "vec2.h"
#include<cmath>
#include<iostream>

Vec2::Vec2(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vec2::Vec2()
{
    x = 0;
    y = 0;
}

Vec2::Vec2(const Vec2& v){
    this->x = v.getX();
    this->y = v.getY();
}


Vec2::~Vec2()
{
    //dtor
}
double Vec2::getX() const
{
    return x;
}

double Vec2::getY() const
{
    return y;
}

void Vec2::setX(double val)
{
    this->x = val;
}

void Vec2::setY(double val)
{
    this->y = val;
}

double Vec2::dot(Vec2 v) const
{
    return this->x * v.getX() + this->y * v.getY();
}

double Vec2::magSq() const
{
    return x*x + y*y;
}

Vec2 Vec2::subtr(Vec2 v) const
{
    return Vec2(this->x - v.getX(), this->y - v.getY());
}
Vec2 Vec2::mult(double s) const
{
    return Vec2(x * s, y * s);
}
Vec2 Vec2::add(const Vec2& v) const
{
    return Vec2(this->x + v.getX(), this->y + v.getY());
}

Vec2 Vec2::projection(const Vec2& v) const
{
    double dot = this->dot(v);
	double magSq = v.magSq();
	return v.mult(dot/magSq);
}
Vec2 Vec2::normalize() const
{
    double mag = sqrt(this->magSq());
    return Vec2(getX() / mag, getY() / mag);
}
double Vec2::scross(const Vec2& b) const
{

    return x * b.getY() - y * b.getX();
}
double Vec2::angleBetween(const Vec2& v) const{
    Vec2 n1 = normalize();
    Vec2 n2 = v.normalize();
    double cos = n1.dot(n2);
    double sen = n1.scross(n2);
    if(cos == 0)
        return asin(sen) * (180.0f/M_PI);

    return atan2(sen,cos) * (180.0f/M_PI);
}
