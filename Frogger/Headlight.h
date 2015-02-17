#ifndef HEADLIGHT
#define HEADLIGHT
#include "Spotlight.h"

class Headlight : public Spotlight
{
private:
	char _direction;
public:
	Headlight(double x, double y, double z, char direction, GLenum light);
	void refresh();
	void setDirection(char direction);
};

#endif