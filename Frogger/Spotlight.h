#ifndef SPOTLIGHT
#define SPOTLIGHT
#include "Light.h"

class Spotlight : public Light
{
public:
	char _direction;
	GLenum _light;
	Spotlight(double x, double y, double z, char direction, GLenum light);
	void refresh();
};

#endif