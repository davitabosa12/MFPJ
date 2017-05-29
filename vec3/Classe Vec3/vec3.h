/*
 * vec3.h
 *
 *  Created on: 25 de mai de 2017
 *      Author: davi
 */

#ifndef VEC3_H_
#define VEC3_H_

#endif /* VEC3_H_ */
#include<cmath>

/*Construtores
 – Padrão e recebendo x, y e z
 • Métodos, operadores e atributos
 */



class Vec3 {
	//Constantes
public:
	static const Vec3 VEC3_ZERO; //Vetor zero
	static const Vec3 VEC3_ONES; //Vetor de "um"s
	static const Vec3 VEC3_FORWARD;
	static const Vec3 VEC3_BACKWARD;
	static const Vec3 VEC3_UPWARD;
	static const Vec3 VEC3_DOWNWARD;
	static const Vec3 VEC3_LEFT;
	static const Vec3 VEC3_RIGHT;
	//Campos
private:
	double x; //Componente X
	double y; //Componente Y
	double z; //Componente Z
public:
	//Construtores
	Vec3(); //Construtor Padrao. Cria um vetor forward.
	Vec3(double x, double y, double z); //Cria um vetor dado x, y e z.
	Vec3(const Vec3& v); //Copy constructor

	//Metodos
	Vec3 add(Vec3 v); //soma de vetores
	Vec3 subtr(Vec3 v); //subtracao de vetores
	double dot(Vec3 v); //produto escalar
	Vec3 cross(Vec3 v); //produto vetorial
	Vec3 mult(double s); //multiplicacao de um vetor por um escalar
	Vec3 div(double s); //divisao de um vetor por um escalar
	double magnitude(); //Magnitude do vetor
	Vec3 normalized();  //Retorna o vetor normalizado
	Vec3 projection(Vec3 v); //Retorna a projecao deste vetor em V

	//Sobrecarga de operadores
	Vec3 operator+(Vec3 a);
	Vec3 operator-(Vec3 a);
	Vec3 operator-();
	Vec3 operator*(double s);
	Vec3 operator/(double s);
	bool operator==(Vec3 a);
	void operator=(Vec3 a);



	//Getters / Setters
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);
	double getZ() const;
	void setZ(double z);
};

/*
 Adição, subtração, multiplicação e divisão
 Magnitude, distância e normalização
 Produto e divisão por escalar
 Produtos escalar e vetorial
 Projeção de um vetor sobre outro
 Ângulos entre vetores
 Quais constantes de classe você poderia adicionar?
 */
/*
 • Desafio
 – Forneça facilidades para I/O
 – Implemente vetores 2D e 4D
 */


