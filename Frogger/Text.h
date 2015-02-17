#ifndef TEXT_H
#define TEXT_H
#include "StaticObject.h"
#include <stdio.h>
#include "soil/src/SOIL.h"

class Text : public StaticObject
{
	GLuint _tex;
	float _red, _green, _blue;
	double _xSize, _ySize;
	void applyTexture(const char *name);

public:
	Text(double xz, double y, double z, const char *name, float red, float green, float blue);
	void draw();
	void resize(double x, double y);
};

#endif