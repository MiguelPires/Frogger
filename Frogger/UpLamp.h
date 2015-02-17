#ifndef UPLAMP_H
#define UPLAMP_H
#include "LampPost.h"

class UpLamp : public LampPost
{
public:
	UpLamp(double x, double y, double z);
	void draw();
};

#endif