#include "Headlight.h"

Headlight::Headlight(double x, double y, double z, char direction, GLenum light) :Spotlight(x, y, z, direction, light)
{
	_direction = 'u';
}

void Headlight::refresh()
{
	Vector3 *pos = getPosition();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat ambient[] = { 0, 0, 0, 0.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat specular[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat position[] = { pos->getX(), pos->getY(), pos->getZ(), 1.0 };
	GLenum 	cutOff = 25;

	if (_direction == 'u'){
		GLfloat spotDirection[] = { 0.0, 1, -1 };
		glLightfv(_light, GL_SPOT_DIRECTION, spotDirection);
	}
	else if (_direction == 'r')
	{
		GLfloat spotDirection[] = {1, 0, -1 };
		glLightfv(_light, GL_SPOT_DIRECTION, spotDirection);
	}
	else if (_direction == 'l')
	{
		GLfloat spotDirection[] = { -1, 0, -1 };
		glLightfv(_light, GL_SPOT_DIRECTION, spotDirection);
	}
	else
	{
		GLfloat spotDirection[] = { 0, -1, -1 };
		glLightfv(_light, GL_SPOT_DIRECTION, spotDirection);
	}

	glLightf(_light, GL_CONSTANT_ATTENUATION, 0);
	glLightf(_light, GL_LINEAR_ATTENUATION, 0);
	glLightf(_light, GL_QUADRATIC_ATTENUATION, 0.6);

	glLightfv(_light, GL_AMBIENT, ambient);
	glLightfv(_light, GL_DIFFUSE, diffuse);
	glLightfv(_light, GL_SPECULAR, specular);
	glLightfv(_light, GL_POSITION, position);


	glLightf(_light, GL_SPOT_CUTOFF, cutOff);

	glLightf(_light, GL_SPOT_EXPONENT, 2.0);
	glEnable(GL_DEPTH_TEST);

}


void Headlight::setDirection(char direction)
{
	_direction = direction;
	refresh();
}