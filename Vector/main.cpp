#include <iostream>

using namespace std;
#include"vec3.h"
#include"vec2.h"
#include<cmath>
double to_degrees(double radians){
    return radians * 180 / M_PI;
}
int main()
{
    Vec3 v1,v2;
    v1 = Vec3(1,0,0);
    v2 = Vec3(0.9999,0.0001,0);
    double ang = Vec3::angleBetween(v1,v2);

    cout << to_degrees(ang)<<endl;
    return 0;
}
