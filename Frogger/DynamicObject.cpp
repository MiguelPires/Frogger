#include "DynamicObject.h"

DynamicObject::DynamicObject(double x, double y, double z) :GameObject(x, y, z)
{
	originalPosition = new Vector3(x, y, z);
}

void DynamicObject::autoMove()
{
	if (!isDrawn())
		return;

	Vector3 *pos = getPosition();
	
	if (pos->getX() > -CUBE_SIZE*WIDTH_CUBES/2)
		setPosition(pos->getX() - (double)STEP_SIZE, pos->getY(), pos->getZ());
	else
	{
		setPosition(CUBE_SIZE*WIDTH_CUBES / 2, pos->getY(), pos->getZ());
		changeDrawnState(false);
	}

}
void DynamicObject::reset()
{
	setPosition(originalPosition->getX(), originalPosition->getY(), originalPosition->getZ());
	changeDrawnState(false);
}

bool DynamicObject::isDrawn()
{
	return _drawn;
}

void DynamicObject::changeDrawnState(bool state)
{
	_drawn = state;
}
