#include "vec4.h"
#include <cmath>
Vec4::Vec4(){
  this->x = 0;
  this->y = 0;
  this->z = 0;
  this->w = 0;
}
Vec4::Vec4(double x,double y ,double z, double w){
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

double Vec4::getX() const{
  return this->x;
}
double Vec4::getY() const{
  return this->y;
}
double Vec4::getZ() const{
  return this->z;
}
double Vec4::getW() const{
  return this->w;
}
void   Vec4::setX(double x){
  this->x = x;
}
void   Vec4::setY(double y){
  this->y = y;
}
void   Vec4::setZ(double z){
  this->z = z;
}
void   Vec4::setW(double w){
  this->w = w;
}
  double x,y,z,w;
