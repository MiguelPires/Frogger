#ifndef DOWNLAMP_H
#define DOWNLAMP_H
#include "LampPost.h"

class DownLamp : public LampPost
{
public:
	DownLamp(double x, double y, double z);
	void draw();
};

#endif