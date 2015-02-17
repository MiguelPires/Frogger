#ifndef LAMPPOST_H
#define LAMPPOST_H
#define POST_RADIUS CUBE_SIZE/10
#include "StaticObject.h"

class LampPost : public StaticObject
{
public:
	LampPost(double x, double y, double z);
	virtual void draw()=0;
	virtual vector<double> getBoundaries();
};

#endif