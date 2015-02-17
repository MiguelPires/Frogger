#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "GameObject.h"
#define STEP_SIZE CUBE_SIZE/20
#define FROG_STEP CUBE_SIZE/2
class DynamicObject : public GameObject 
{
	bool _drawn = false;
	Vector3 *originalPosition;

public:
	DynamicObject(double x, double y, double z);
	void autoMove();
	bool isDrawn();
	void changeDrawnState(bool state);
	void reset();

};
#endif