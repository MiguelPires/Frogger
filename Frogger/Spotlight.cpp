#include "Spotlight.h"

Spotlight::Spotlight(double x, double y, double z, char direction, GLenum light) :Light(x, y, z)
{
	_direction = direction;
	_light = light;
}

void Spotlight::refresh()
{
	Vector3 *pos = getPosition();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat ambient[] = { 0, 0, 0, 0.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat specular[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat position[] = { pos->getX(), pos->getY(), pos->getZ(), 1.0 };
	GLfloat spotDirection[] = { 0.0, 0.0, -1 };
	GLenum cutOff;

	if (_direction == 'c')
		cutOff = 45;
	else
		cutOff = 30;

	glLightfv(_light, GL_AMBIENT, ambient);
	glLightfv(_light, GL_DIFFUSE, diffuse);
	glLightfv(_light, GL_SPECULAR, specular);
	glLightfv(_light, GL_POSITION, position);
	glLightfv(_light, GL_SPOT_DIRECTION, spotDirection);

	glLightf(_light, GL_CONSTANT_ATTENUATION, 0);
	glLightf(_light, GL_LINEAR_ATTENUATION, 0.2);
	glLightf(_light, GL_QUADRATIC_ATTENUATION, 0.1);


	glLightf(_light, GL_SPOT_CUTOFF, cutOff);

	glLightf(_light, GL_SPOT_EXPONENT, 2.0);
	glEnable(GL_DEPTH_TEST);

}

