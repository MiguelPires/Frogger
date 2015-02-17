#ifndef LIGHT
#define LIGHT
#include "Entity.h"

class Light : public Entity
{

public:
	Light(double x, double y, double z);
	virtual void refresh()=0;
};

#endif