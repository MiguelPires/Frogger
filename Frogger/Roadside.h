#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "StaticObject.h"
#include <stdio.h>
#include "soil/src/SOIL.h"

class Roadside : public StaticObject
{
	GLuint _tex;
	void applyTexture();

public:
	Roadside(double x, double y, double z);
	void draw();
};
#endif