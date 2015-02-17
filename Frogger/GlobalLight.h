#ifndef GLOBALLIGHT
#define GLOBALLIGHT
#include "Light.h"

class GlobalLight : public Light
{

public:
	GlobalLight(double x, double y, double z);
	void refresh();
};

#endif