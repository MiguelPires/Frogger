#ifndef CENTERLAMP_H
#define CENTERLAMP_H
#include "LampPost.h"

class CenterLamp : public LampPost
{
public:
	CenterLamp(double x, double y, double z);
	void draw();
};

#endif