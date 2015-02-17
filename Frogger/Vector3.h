#ifndef VECTOR_H
#define VECTOR_H 
#include <stdlib.h>
#include "GL\glut.h"
#include <iostream>
#include <vector>

class Vector3
{
protected:
	double _x, _y, _z;
public:
	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	Vector3 operator=(const Vector3& vec);
	Vector3 operator*(double num);
	Vector3 operator+(const Vector3 & vec);
	Vector3 operator-(const Vector3 & vec);
	Vector3(double x, double y, double z);
};

#endif