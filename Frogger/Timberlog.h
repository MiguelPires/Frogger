#ifndef TIMBERLOG_H
#define TIMBERLOG_H
#include "DynamicObject.h"

class Timberlog : public DynamicObject
{
public:
	Timberlog(double x, double y, double z);
	void draw();
	vector<double> getBoundaries();
};
#endif