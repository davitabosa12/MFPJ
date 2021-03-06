#include "mat4.h"

Mat4::Mat4(){
  for(int i = 0; i < 16; i++)
    this->matrix4[i] = 0;
  this->matrix4[0] = 1;
  this->matrix4[5] = 1;
  this->matrix4[10] = 1;
  this->matrix4[15] = 1;
}
Mat4::Mat4(const Mat4& other){
  for(int i = 0; i < 16; i++){
    this->matrix4[i] = other.get(i);
  }
}

//Multiplicacao
Mat4 Mat4::mult(Mat4 b){
  double aux = 0;
  Mat4 result = Mat4();
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      aux = 0;
      for(int k = 0; k < 4; k++){
	aux += this->matrix4[i + k *4] * b.get(k + j * 4);
      }
      result.set(i + j * 4, aux);
      
    }
  }
  
      
    return result;
}
Mat4::~Mat4(){
}
Vec4 Mat4::mult(Vec4 v){
  Vec4 result = Vec4();
  result.setX(this->matrix4[0] * v.getX() +
	      this->matrix4[4] * v.getX() +
	      this->matrix4[8] * v.getX() +
	      this->matrix4[12] * v.getX());
  
  result.setY(this->matrix4[1] * v.getY() +
	      this->matrix4[5] * v.getY() +
	      this->matrix4[9] * v.getY() +
	      this->matrix4[13] * v.getY());
  
  result.setZ(this->matrix4[2] * v.getZ() +
	      this->matrix4[6] * v.getZ() +
	      this->matrix4[10] * v.getZ() +
	      this->matrix4[14] * v.getZ());
  
  result.setW(this->matrix4[3] * v.getW() +
	      this->matrix4[7] * v.getW() +
	      this->matrix4[11] * v.getW() +
	      this->matrix4[15] * v.getW());
  return result;
  
}
//identidade
void Mat4::identity(){
  for(int i = 0; i < 16; i++)
    this->matrix4[i] = 0;
  this->matrix4[0] = 1;
  this->matrix4[5] = 1;
  this->matrix4[10] = 1;
  this->matrix4[15] = 1;
}
//translacao
void Mat4::translate(double dx ,double dy ,double dz){
  this->identity();
  this->matrix4[3] = dx;
  this->matrix4[7] = dy;
  this->matrix4[11] = dz;
}
//escala
void Mat4::scale(double s){
  this->identity();
  this->matrix4[0] *=s;
  this->matrix4[5] *=s;
  this->matrix4[10] *=s;
}
void Mat4::scale(Vec3 pos, double s){
  Mat4 T,S,minusT;
  this->identity();
  S = Mat4();
  T = Mat4();
  minusT = Mat4();
  T.translate(pos.getX(), pos.getY(), pos.getZ());
  S.scale(s);
  minusT.translate(-pos.getX(), -pos.getY(), -pos.getZ());
  this->mult(T);
  this->mult(S);
  this->mult(minusT);
}
void Mat4::scale(double sx, double sy, double sz){
  this->identity();
  this->matrix4[0] *=sx;
  this->matrix4[5] *=sy;
  this->matrix4[10] *=sz;
}
//rotacao
void Mat4::rotateX(double theta){
  double ct = cos(theta);
  double st = sin(theta);
  this->identity();
  this->matrix4[5] = ct;
  this->matrix4[10] = ct;
  this->matrix4[6] = -st;
  this->matrix4[9] = st;
}
void Mat4::rotateY(double theta){
  double ct = cos(theta);
  double st = sin(theta);
  this->identity();
  this->matrix4[0] = ct;
  this->matrix4[10] = ct;
  this->matrix4[2] = st;
  this->matrix4[8] = -st;
}
void Mat4::rotateZ(double theta){
  double ct = cos(theta);
  double st = sin(theta);
  this->identity();
  this->matrix4[0] = ct;
  this->matrix4[5] = ct;
  this->matrix4[1] = -st;
  this->matrix4[4] = st;
}
void Mat4::rotate(Vec3 v, double theta){
  double ux =v.getX(), uy = v.getY(), uz = v.getZ();
  double cosT = cos(theta);
  double sinT = sin(theta);
  double one_minus_cos = 1 - cosT;
  this->identity();
  //contas
  //linha 1
  this->matrix4[0] = ux * ux * one_minus_cos + cosT;
  this->matrix4[1] = ux * uy * one_minus_cos - uz * sinT;
  this->matrix4[2] = ux * uz * one_minus_cos + uy * sinT;
  //linha 2
  this->matrix4[4] = ux * uy * one_minus_cos + uz * sinT;
  this->matrix4[5] = uy * uy * one_minus_cos + cosT;
  this->matrix4[6] = uy * uz * one_minus_cos - ux * sinT;
  //linha 3
  this->matrix4[8] = ux * uz * one_minus_cos - uy * sinT;
  this->matrix4[9] = uy * uz * one_minus_cos + ux * sinT;
  this->matrix4[10] = uz * uz * one_minus_cos + cosT;
}
//trs
Mat4 Mat4::trs(Vec3 pos, Mat4 rotation, Vec3 scale){
  Mat4 result;
  Mat4 T = Mat4(), R = rotation, S= Mat4();
  T.translate(pos.getX(), pos.getY(), pos.getZ());
  S.scale(scale.getX(), scale.getY(), scale.getZ());
  Mat4 TR = T.mult(R);
  result = TR.mult(S);
  return result;
}
//srt
Mat4 Mat4::srt(Vec3 scale, Mat4 rotation, Vec3 pos){
  Mat4 result;
  Mat4 T = Mat4(), R = rotation, S= Mat4();
  T.translate(-pos.getX(), -pos.getY(), -pos.getZ());
  S.scale(1/scale.getX(), 1/scale.getY(), 1/scale.getZ());
  Mat4 TR = T.mult(R);
  result = TR.mult(S);
  return result;
}
//getter&setter
double Mat4::get(int index) const{
  return this->matrix4[index];
}
void  Mat4::set(int index, double value){
  this->matrix4[index] = value;
}

void Mat4::toString(){
  std::cout<<"\n";
  for(int i = 0; i < 16; i++){
    std::cout << matrix4[i] << " ";
    if((i + 1) % 4 ==0)
      std::cout<<"\n";
  }
}
