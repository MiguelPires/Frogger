#include "Bus.h"

Bus::Bus(double x, double y, double z) :DynamicObject(x, y, z){}

void Bus::draw()
{
	Vector3 *pos = getPosition();
	
	glPushMatrix();

	glTranslated(pos->getX()+0.5, pos->getY(), pos->getZ());
	glScaled(1.0, 0.8*CUBE_SIZE, 1);

	glPushMatrix();	// wheels

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glColor3f((float)160 / 255, (float)160 / 255, (float)160 / 255);

	glPushMatrix();
	glTranslated(-BUS_BLOCKSIZE, BUS_BLOCKSIZE - BUS_WHEELS_SIZE-0.1, -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-BUS_BLOCKSIZE, -(BUS_BLOCKSIZE - BUS_WHEELS_SIZE-0.1), -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(BUS_BLOCKSIZE, BUS_BLOCKSIZE - BUS_WHEELS_SIZE - 0.1, -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(BUS_BLOCKSIZE, -(BUS_BLOCKSIZE - BUS_WHEELS_SIZE - 0.1), -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, BUS_BLOCKSIZE - BUS_WHEELS_SIZE - 0.1, -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -(BUS_BLOCKSIZE - BUS_WHEELS_SIZE - 0.1), -BUS_BLOCKSIZE / 4.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glutSolidTorus(BUS_WHEELS_SIZE / 2, BUS_WHEELS_SIZE, 20, 50);
	glPopMatrix();
	glPopMatrix(); //wheels

	glPushMatrix();		// chassis
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glTranslated(0.3, 0,0);
	glColor3f(1.0, 1.0, 1.0);

	glScaled(1.8, 1.0, 1.0);
	glutSolidCube(BUS_BLOCKSIZE); //reboque
	glPopMatrix();

	glPushMatrix();
	glScaled(0.7, 1, 0.3);
	glColor3f(0, 0, 1);

	glTranslated(-1.0,0.0,0.0);
	glutSolidCube(BUS_BLOCKSIZE);	//camiao down side

	
	glScaled(0.6, 1, 1);
	glTranslated(0.25, 0.0, 0.7);
	glutSolidCube(BUS_BLOCKSIZE);	//camiao up side
	glPopMatrix();	

	glScaled(1, 0.5, 0.1);
	glColor3f(0.5, 0.5, 0.5);

	glTranslated(-0.5, 0.0, -1.5);
	glutSolidCube(BUS_BLOCKSIZE); //ligacao camiao-reboque
	

	glPopMatrix();
}

vector<double> Bus::getBoundaries()
{
	Vector3 *position = getPosition();
	vector<double> boundaries(4);

	boundaries[0] = position->getX() - (double)(BUS_BLOCKSIZE  * 0.7 + 0.5) / 2;
	boundaries[1] = position->getX() + (double)(BUS_BLOCKSIZE  * 1.8 +1.4) / 2;
	boundaries[2] = position->getY() + (double)(BUS_BLOCKSIZE) / 2;
	boundaries[3] = position->getY() - (double)(BUS_BLOCKSIZE) / 2;
	
	return boundaries;
}