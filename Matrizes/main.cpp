#include "mat4.h"
#include "vec4.h"
#include <iostream>
using namespace std;
int main(){
  Mat4 a = Mat4();
  Mat4 b = Mat4();
  b.rotateZ(M_PI / 6);
  a = a.trs(Vec3(8,12,3), b, Vec3(2,2,2));
  a.toString();
  return 0;
}
