#include "Timberlog.h"
#define TIMBERLOG_RADIUS CUBE_SIZE/2.5


Timberlog::Timberlog(double x, double y, double z) :DynamicObject(x, y, z){}

void Timberlog::draw()
{
	Vector3 *pos = getPosition();

	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.4, 0.15, 0.1);

	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Roda o cilindro para desenhar no x axis
	gluCylinder(gluNewQuadric(), (double)TIMBERLOG_RADIUS, (double)TIMBERLOG_RADIUS, (double)CUBE_SIZE*2.3, 32, 32);
	glPopMatrix();
}

vector<double> Timberlog::getBoundaries()
{
	Vector3 *position = getPosition();
	vector<double> boundaries(4);

	boundaries[0] = position->getX();
	boundaries[1] = position->getX() + (double)(CUBE_SIZE*2.3);
	boundaries[2] = position->getY() + (double)TIMBERLOG_RADIUS;
	boundaries[3] = position->getY() - (double)TIMBERLOG_RADIUS;

	return boundaries;
}