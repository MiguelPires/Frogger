#include "Frog.h"
#define FROG_SIZE 0.20
#include <string>
using namespace std;

//alt: por edgesCollided no tronco e tartaruga e tirar o jump

Frog::Frog(double x, double y, double z) :DynamicObject(x, y, z)
{
	_lamp = new Headlight(x, y, z+CUBE_SIZE/2.0, 'f', GL_LIGHT7);
	_lamp->refresh();
	_direction = 'u';
	_angle = 0;

}

void Frog::reset()
{
	DynamicObject::reset();
	_direction = 'u';
	_angle = 0;
	_lamp->setDirection('u');
	draw();
}

void Frog::draw()
{
	Vector3 *pos = getPosition();

	glPushMatrix();


	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	if (_direction == 'l')
	{
		glRotatef(-_angle + 90, 0.0, 0.0, 1.0);

	}

	else if (_direction == 'r')
		glRotatef(-_angle - 90, 0.0, 0.0, 1.0);
	else if (_direction == 'd')
		glRotatef(-_angle + 180, 0.0, 0.0, 1.0);

	glTranslatef(-getPosition()->getX(), -getPosition()->getY(), -getPosition()->getZ());

	//eye
	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
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

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(76.0 / 255.0, 153.0 / 255.0, 0.0);

	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glScalef(0.7, 1, 0.7);
	glutSolidSphere(FROG_SIZE, 20.0, 10.0);
	glPopMatrix();

	//legs
	//righ side
	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
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

	//helmet
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslated(pos->getX(), pos->getY(), pos->getZ() + 0.09);
	glScalef(1, 1, 0.2);
	glutSolidSphere(0.15, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos->getX(), pos->getY(), pos->getZ() + 0.05);
	glScalef(0.8, 1, 1.5);
	glutSolidSphere(0.15, 10.0, 10.0);
	glPopMatrix();

	//light scope
	glColor3f(0.4, 0.4, 0.4);
	glPushMatrix();
	glTranslated(pos->getX(), pos->getY() + 0.2, pos->getZ() + 0.10);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(gluNewQuadric(), 0.05, 0.05, 0.10, 32, 32);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

int Frog::move(char direction, LampPost *posts[], int numPosts)
{
	Vector3 *pos = getPosition();

	double oldX = pos->getX(), oldY = pos->getY();

	switch (direction)
	{
	case 'l':	//left
		if (_direction == 'l')
			_rotate = false;
		else
		{
			_direction = 'l';
			_rotate = true;
		}

		if (pos->getX() > -CUBE_SIZE*WIDTH_CUBES / 2)
			setPosition(pos->getX() - (double)FROG_STEP, pos->getY(), pos->getZ());
		break;

	case 'r':	//right
		if (_direction == 'r')
			_rotate = false;

		else
		{
			_direction = 'r';
			_rotate = true;
		}

		if (pos->getX() < CUBE_SIZE*WIDTH_CUBES / 2)
			setPosition(pos->getX() + (double)FROG_STEP, pos->getY(), pos->getZ());
		break;

	case 'u':	//up
		if (_direction == 'u')
			_rotate = false;
		else
		{
			_direction = 'u';
			_rotate = true;
		}
		if (pos->getY() < (MARGINS + HEIGHT_RIVER + HEIGHT_ROAD) *CUBE_SIZE / 2)
		{
			if (onPlatform())
				setPosition(pos->getX(), pos->getY() + (double)CUBE_SIZE, pos->getZ());

			else
				setPosition(pos->getX(), pos->getY() + (double)FROG_STEP, pos->getZ());
		}

		else
			return 1;

		break;

	case 'd':	//down
		if (_direction == 'd')
			_rotate = false;
		else
		{
			_direction = 'd';
			_rotate = true;
		}

		if (pos->getY() > -(2 * MARGINS + HEIGHT_RIVER + HEIGHT_ROAD) *CUBE_SIZE / 2)
		{
			if (onPlatform())
				setPosition(pos->getX(), pos->getY() - (double)CUBE_SIZE, pos->getZ());
			else
				setPosition(pos->getX(), pos->getY() - (double)FROG_STEP, pos->getZ());
		}

		break;
	}
	for (int i = 0; i < numPosts; i++)
		if (edgesCollided(posts[i]->getBoundaries()))
		{
			if (direction == 'l' || direction == 'r')
				setPosition(oldX, pos->getY(), pos->getZ());
			else
				setPosition(pos->getX(), oldY, pos->getZ());
		}
	
	pos = getPosition();
	_lamp->setPosition(pos->getX(), pos->getY(), pos->getZ()+ CUBE_SIZE / 2.0);
	_lamp->refresh();
	_lamp->setDirection(direction);
	return 0;
}

void Frog::autoMove()
{
	Vector3 *pos = getPosition();

	if (pos->getX() > -CUBE_SIZE*WIDTH_CUBES / 2)
		setPosition(pos->getX() - (double)STEP_SIZE, pos->getY(), pos->getZ());

	pos = getPosition();
	_lamp->setPosition(pos->getX(), pos->getY(), pos->getZ() + CUBE_SIZE / 2.0);
	_lamp->refresh();
}

void Frog::die()
{
	setPosition(0.0, -CUBE_SIZE*(HEIGHT_ROAD + MARGINS), 2.0*CUBE_SIZE);

	Vector3 *pos = getPosition();
	_lamp->setPosition(pos->getX(), pos->getY(), pos->getZ() + CUBE_SIZE / 2.0);
	_lamp->refresh();
}

bool Frog::edgesCollided(vector<double> boundaries)
{
	Vector3 *frogPos = getPosition();

	if (frogPos->getX() - FROG_SIZE <= boundaries[1] && frogPos->getX() + FROG_SIZE >= boundaries[0] &&
		frogPos->getY() - FROG_SIZE <= boundaries[2] && frogPos->getY() + FROG_SIZE >= boundaries[3])
		return true;

	return false;
}

bool Frog::centerCollided(vector<double> boundaries)
{
	Vector3 *frogPos = getPosition();

	if (frogPos->getX() <= boundaries[1] && frogPos->getX() >= boundaries[0] &&
		frogPos->getY() <= boundaries[2] && frogPos->getY() >= boundaries[3])
		return true;

	return false;
}

bool Frog::checkCollision(Car **cars, Bus **buses, int numCars, int numBuses, 
						River *river)
{
	vector<double> boundaries;

	// checks collision with every car
	for (int i = 0; i < numCars; i++)
	{
		boundaries = cars[i]->getBoundaries();
		if (edgesCollided(boundaries))
		{
			die();
			return true;
		}
	}

	// checks collision with every bus
	for (int i = 0; i < numBuses; i++)
	{
		boundaries = buses[i]->getBoundaries();
		if (edgesCollided(boundaries))
		{
			die();
			return true;
		}
	}
	
	// checks to see if the frog fell in the river
	boundaries[0] = -WIDTH_CUBES *CUBE_SIZE - CUBE_SIZE/2;
	boundaries[1] = WIDTH_CUBES *CUBE_SIZE / 2 - CUBE_SIZE/2;
	boundaries[2] = HEIGHT_RIVER*CUBE_SIZE;
	boundaries[3] = CUBE_SIZE;								

	if (centerCollided(boundaries) && !onPlatform())
	{
		die();
		return true;
	}

	return false;
}

void Frog::checkObjects(Turtle **turtles, int nTurtles, Timberlog **timbers, int nTimberlogs){

	vector<double> boundaries;

	_onTimberlog = false;
	_onTurtle = false;

	for (int i = 0; i < nTurtles; i++)
	{
		boundaries = turtles[i]->getBoundaries();
		if (centerCollided(boundaries))
		{
			_onTurtle = true;
			return;
		}
	}

	for (int i = 0; i < nTimberlogs; i++)
	{
		boundaries = timbers[i]->getBoundaries();
		if (centerCollided(boundaries))
		{
			_onTimberlog = true;
			return;
		}
	}


}

bool Frog::onPlatform(){
	return onTurtle() || onTimberlog();
}

bool Frog::onTurtle(){
	return _onTurtle;
}

bool Frog::onTimberlog(){
	return _onTimberlog;
}