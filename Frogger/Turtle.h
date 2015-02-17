#ifndef TURTLE_H
#define TURTLE_H
#include "DynamicObject.h"

class Turtle : public DynamicObject
{
public:
	Turtle(double x, double y, double z);
	void draw();
	vector<double> getBoundaries();
};
#endif