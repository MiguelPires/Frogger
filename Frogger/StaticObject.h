#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"


class StaticObject: public GameObject
{
public:
	StaticObject(double x, double y, double z);
};
#endif