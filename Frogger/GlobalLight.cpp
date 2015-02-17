#include "GlobalLight.h"

GlobalLight::GlobalLight(double x, double y, double z) :Light(x, y, z)
{
}

void GlobalLight::refresh()
{
	Vector3 *pos = getPosition();

	GLfloat position[] = {pos->getX(), pos->getY(), pos->getZ()};
	GLfloat specular[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat spot_direction[] = {pos->getX(), pos->getY(), -1.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_LIGHT0, GL_POSITION, position);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 5.0);

	glEnable(GL_DEPTH_TEST);
}