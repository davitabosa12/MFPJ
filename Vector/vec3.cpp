#include "vec3.h"

#include"vec3.h"

const Vec3 Vec3::VEC3_ZERO = Vec3(0,0,0); //Vetor zero
const Vec3 Vec3::VEC3_ONES = Vec3(1,1,1); //Vetor de "um"s
const Vec3 Vec3::VEC3_FORWARD = Vec3(0,0,1);
const Vec3 Vec3::VEC3_BACKWARD = Vec3(0,0,-1);
const Vec3 Vec3::VEC3_UP = Vec3(0,1,0);
const Vec3 Vec3::VEC3_DOWN = Vec3(0,-1,0);
const Vec3 Vec3::VEC3_LEFT = Vec3(-1,0,0);
const Vec3 Vec3::VEC3_RIGHT = Vec3(1,0,0);

/**
  *Construtor padrao Vec3
  *Cria um novo vetor FORWARD
  */
Vec3::Vec3()
{
    this->x = 0;
	this->y = 0;
	this->z = 1;
	this->mag = 1;
}

Vec3::Vec3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->mag = sqrt(x*x + y*y + z*z);

}
//Copy constructor
Vec3::Vec3(const Vec3& v) {
	this->x = v.getX();
	this->y = v.getY();
	this->z = v.getZ();
	this->mag = v.getMagnitude();
}

Vec3::~Vec3()
{
    //wat
}
Vec3 Vec3::add(Vec3 v) {
	return Vec3(this->x + v.getX(),
				this->y + v.getY(),
				this->z + v.getZ());
}

Vec3 Vec3::subtr(Vec3 v) {
	return Vec3(x - v.getX(), y - v.getY(), z - v.getZ());
}
Vec3 Vec3::mult(double s) {
	return Vec3(s * x, s * y, s * z);
}

Vec3 Vec3::div(double s) {
	return Vec3(x / s, y / s, z / s);
}

double Vec3::dot(Vec3 v) {
	return this->x * v.getX() +
		   this->y * v.getY() +
		   this->z * v.getZ();
}

Vec3 Vec3::cross(Vec3 v) {
	double vx = v.getX(), vy = v.getY(), vz = v.getZ();
	return Vec3(y * vz - z * vy,
				z * vx - x * vz,
				x * vy - y * vx);
}

double Vec3::magnitude() {
	return sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::normalized() {
	double norma = this->magnitude();
	return Vec3(x/norma, y/norma, z/norma);
}

 //Retorna o angulo entre v1 e v2
double Vec3::angleBetween(Vec3 v1, Vec3 v2){
    double n_mult = v1.getMagnitude() * v2.getMagnitude();
    double theta;
    double cos = v1.dot(v2) / n_mult;
    Vec3 aux = v1.cross(v2);
    double sen = (aux / n_mult).getMagnitude();
    std::cout << sen << std::endl;
    if(cos != 0)
        theta = atan(sen/cos);
    else
        theta = 0;
    if(sen >= 0 && cos > 0){

    }else if(sen > 0 && cos <= 0 ){ //segundo quadrante
        theta += M_PI_2;
    } else if( sen <= 0 && cos < 0 ){//terceiro quadrante
        theta += M_PI;
    } else if ( sen < 0 && cos >= 0) {//quarto quadrante
        theta += 3 * M_PI_2;
    }
    return theta;
}

double Vec3::getX() const {
	return x;
}

void Vec3::setX(double x) {
	this->x = x;
}

double Vec3::getY() const {
	return y;
}

void Vec3::setY(double y) {
	this->y = y;
}

double Vec3::getZ() const {
	return z;
}

void Vec3::setZ(double z) {
	this->z = z;
}

double Vec3::getMagnitude() const{
    return mag;
}

Vec3 Vec3::projection(Vec3 v) {
	double dot = this->dot(v);
	double magSq = v.getMagnitude();
	magSq *= magSq;
	return v.mult(dot/magSq);
}

Vec3 Vec3::operator +(Vec3 a) {
	return Vec3(a.getX() + x,
				a.getY() + y,
				a.getZ() + z );
}

Vec3 Vec3::operator -(Vec3 a) {
	return Vec3(x - a.getX(),
				y - a.getY(),
				z - a.getZ() );
}

Vec3 Vec3::operator -() {
	return Vec3(-x,-y,-z);
}

Vec3 Vec3::operator *(double s) {
	return Vec3(x * s, y * s, z * s);
}


Vec3 Vec3::operator /(double s) {
	if(s == 0)
		throw 111;
	return Vec3(x / s, y / s, z / s);
}


bool Vec3::operator ==(Vec3 a) {
	return x == a.getX() &&
		   y == a.getY() &&
		   z == a.getZ();
}

void Vec3::operator=(Vec3 a){
	x = a.getX();
	y = a.getY();
	z = a.getZ();

}

//Facilidades de IO
std::string Vec3::to_string(){
    std::stringstream stream;
    stream << "X: " << x << " Y: " << y << " Z: " << z;
    return stream.str();
}
