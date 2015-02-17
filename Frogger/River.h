#ifndef RIVER_H
#define RIVER_H
#include "StaticObject.h"
#include <stdio.h>
#include "soil/src/SOIL.h"

class River : public StaticObject
{
	GLuint _tex;
	void applyTexture();

public:
	River(double x, double y, double z);
	void draw();
};

#endif