#ifndef BUS_H
#define BUS_H
#define BUS_BLOCKSIZE (0.7 * CUBE_SIZE)
#define BUS_WHEELS_SIZE (0.15 * CUBE_SIZE)
#include "DynamicObject.h"

class Bus : public DynamicObject
{

public:
	Bus(double x, double y, double z);
	void draw();
	vector<double> getBoundaries();

};
#endif