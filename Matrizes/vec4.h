#pragma once
class Vec4{
 public:
  Vec4();
  Vec4(double,double,double,double);
  double getX() const;
  double getY() const;
  double getZ() const;
  double getW() const;
  void   setX(double);
  void   setY(double);
  void   setZ(double);
  void   setW(double);
 private:
  double x,y,z,w;
};
