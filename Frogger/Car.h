#ifndef CAR_H
#define CAR_H
#include "DynamicObject.h"
#define CAR_BLOCKSIZE (0.4 * CUBE_SIZE)
#define CAR_SCALE 3
#define CAR_WHEELS_SIZE (0.1* CUBE_SIZE)

class Car : public DynamicObject
{
	public:
		Car (double x, double y, double z);
		void draw();
		vector<double> getBoundaries();
};

#endif