#include "CenterLamp.h"

CenterLamp::CenterLamp(double x, double y, double z) : LampPost(x, y, z){}

void CenterLamp::draw()
{
	Vector3 *pos = getPosition();

	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(160.0 / 255.0, 160.0 / 255.0, 160.0 / 255.0);

	glPushMatrix();
	glTranslated(pos->getX(), pos->getY(), (double)pos->getZ()/2.0);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	gluCylinder(gluNewQuadric(), (double)POST_RADIUS, (double)POST_RADIUS, (double)pos->getZ()/2.0, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(199.0 / 255.0, 203.0 / 255.0, 240.0/255.0);
	glTranslated(pos->getX(), pos->getY(), (double)pos->getZ());
	glutSolidSphere((double)CUBE_SIZE/4.0, 10.0, 10.0);
	glPopMatrix();
	

	glPopMatrix();
}