#include "pseudoangulo.h"

double PAngleBetween(Vec2 v1,Vec2 v2){ //pseudoangle between two 2D vectors
  return std::abs(PAngle(v1) - PAngle(v2));
}
double PAngle(const Vec2 v){ //pseudoangle between this 2D vector and a VEC2_RIGHT
    double x = Vec2::normalize(v).getX();
  double y = Vec2::normalize(v).getY();
  if(x == 0 && y == 0)
    return NAN;

  if(y >=0){
    if(x >= 0){
	if(x >= y)//se estiver no primeiro octante	
	  return y/x;
	return 2 - x/y;  //se estiver no segundo octante
    }
    if(-x <= y){
      return 2 + -x/y; //se estiver no terceiro octante
    }

    return 4 - y/(-x);    //se estiver no quarto octante
    
  }else{
    if(x <= 0){
      if(-x >= -y)	
	return 4 + (-y)/(-x);  //se estiver no quinto octante
      return 6 - (-x)/(-y);//se estiver no sexto octante
    }
    if(x <= -y){
      return 6 + x / (-y);        //se estiver no setimo octante
    }
     
    return 8 - (-y)/x; //se estiver no oitavo octante
    
  }


  
  

  


}
