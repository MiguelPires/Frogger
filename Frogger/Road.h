#ifndef ROAD_H
#define ROAD_H
#include "StaticObject.h"
#include <stdio.h>
#include "soil/src/SOIL.h"

class Road : public StaticObject
{
	GLuint _tex;
	void applyTexture();

public:
	Road(double x, double y, double z);
	void draw();
};
#endif