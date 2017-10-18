#include "vec3.h"
#include "vec4.h"
#pragma once
class Mat4{
  //Construtor
 public:
  Mat4();
  Mat4(const Mat4& other);
  ~Mat4();
  //Multiplicacao
  Mat4 mult(Mat4 b);
  Vec4 mult(Vec4 v);
  //identidade
  void identity();
  //translacao
  void translate(double,double,double);
  //escala
  void scale(double);
  void scale(double,double,double);
  void scale(Vec3,double);
  //rotacao
  void rotateX(double);
  void rotateY(double);
  void rotateZ(double);
  void rotate(Vec3,double);
  //trs
  Mat4 trs(Vec3, Mat4, Vec3);
  //srt
  Mat4 srt(Vec3, Mat4, Vec3);
  //getter&setter
  double get(int) const;
  void  set(int,double);
  void toString();
  
 private:
  double matrix4[16];  
};
