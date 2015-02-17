#include "FrogFigure.h"
#define FROG_SIZE 0.15


FrogFigure::FrogFigure(double x, double y, double z) :DynamicObject(x, y, z)
{
}


void FrogFigure::draw()
{
	Vector3 *pos = getPosition();

	//eye
	glPushMatrix();
	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslated(pos->getX() - 0.05, pos->getY() + 0.22, pos->getZ() + 0.05);
	glutSolidSphere(0.05, 10.0, 10.0);
	glPopMatrix();

	//eye
	glPushMatrix();
	glTranslated(pos->getX() + 0.05, pos->getY() + 0.22, pos->getZ() + 0.05);
	glutSolidSphere(0.05, 10.0, 10.0);
	glPopMatrix();

	glPopMatrix();

	//body
	glPushMatrix();
	glColor3f(76.0 / 255.0, 153.0 / 255.0, 0.0);

	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glScalef(0.7, 1, 0.7);
	glutSolidSphere(FROG_SIZE, 20.0, 10.0);
	glPopMatrix();

	//legs
	//righ side
	glPushMatrix();

	glColor3f(76.0 / 255.0, 153.0 / 255.0, 0.0);

	glPushMatrix();
	glTranslated(pos->getX() + 0.15, pos->getY() - 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + 0.15, pos->getY() + 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + 0.2, pos->getY() + 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + 0.2, pos->getY() + 0.15, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + 0.2, pos->getY() - 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() + 0.2, pos->getY() - 0.15, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	//left side
	glPushMatrix();
	glTranslated(pos->getX() - 0.15, pos->getY() - 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - 0.15, pos->getY() + 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - 0.2, pos->getY() + 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - 0.2, pos->getY() + 0.15, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - 0.2, pos->getY() - 0.1, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX() - 0.2, pos->getY() - 0.15, pos->getZ());
	glutSolidCube(0.05);
	glPopMatrix();
	glPopMatrix();

}
