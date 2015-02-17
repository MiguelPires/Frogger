#include "Vector3.h"

double Vector3::getX() { return _x;}
double Vector3::getY() { return _y;}

double Vector3::getZ() { return _z;}

void Vector3::set(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3::Vector3(double x, double y, double z)
{
	set(x, y, z);
}