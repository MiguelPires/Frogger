#ifndef FROGFIGURE_H
#define FROGFIGURE_H
#include "DynamicObject.h"

class FrogFigure : public DynamicObject
{
public:
	FrogFigure(double x, double y, double z);
	void draw();


};
#endif