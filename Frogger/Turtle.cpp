#include "Turtle.h"
#define SHELL_RADIUS CUBE_SIZE/2.2

Turtle::Turtle(double x, double y, double z) :DynamicObject(x, y, z)
{}

void Turtle::draw()
{
	Vector3 *pos = getPosition();

	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glPushMatrix();
	glColor3f(102.0 / 255.0, 51.0 / 255.0, 0.0);
	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere((double)SHELL_RADIUS -SHELL_RADIUS / 50.0, 10.0, 10.0);
	glPopMatrix();

	glColor3f(0, 153.0/255.0, 0.0);

	//shell
	glPushMatrix();
	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glScalef(1, 1, 0.5);
	glutWireSphere((double)SHELL_RADIUS, 10.0, 10.0);
	glPopMatrix();



	//hands
	glPushMatrix();
	glTranslated(pos->getX() - (double)SHELL_RADIUS*(9.0 / 10), pos->getY() + (double)SHELL_RADIUS*(9.0 / 10), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere(0.08, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - (double)SHELL_RADIUS*(9.0 / 10), pos->getY() - (double)SHELL_RADIUS*(9.0 / 10), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere(0.08, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + (double)SHELL_RADIUS*(9.0 / 10), pos->getY() + (double)SHELL_RADIUS*(9.0 / 10), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere(0.08, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + (double)SHELL_RADIUS*0.9, pos->getY() - (double)SHELL_RADIUS*(9.0 / 10), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere(0.08, 10.0, 10.0);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslated(pos->getX() - (double)SHELL_RADIUS*1.2, pos->getY(), pos->getZ());
	glScalef(1, 1, 0.5);
	glutSolidSphere(0.12, 10.0, 10.0);
	glPopMatrix();

	glPopMatrix();
}


vector<double> Turtle::getBoundaries()
{
	Vector3 *position = getPosition();
	vector<double> boundaries(4);

	boundaries[0] = position->getX() - (double)(SHELL_RADIUS);
	boundaries[1] = position->getX() + (double)(SHELL_RADIUS);
	boundaries[2] = position->getY() + (double)(SHELL_RADIUS);
	boundaries[3] = position->getY() - (double)(SHELL_RADIUS);

	return boundaries;
}