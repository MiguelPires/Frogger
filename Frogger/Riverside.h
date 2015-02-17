#ifndef RIVERSIDE_H
#define RIVERSIDE_H
#include "StaticObject.h"
#include <stdio.h>
#include "soil/src/SOIL.h"

class Riverside : public StaticObject
{
	GLuint _tex;
	void applyTexture();

public:
	Riverside(double x, double y, double z);
	void draw();
};
#endif