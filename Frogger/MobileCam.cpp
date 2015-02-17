#include "MobileCam.h"

MobileCam::MobileCam(int width, int height, Frog *frog) : Camera(width, height)
{
	_frog = frog;
	myReshape(width, height);
}

void MobileCam::myReshape(int width, int height)
{
	double frogX = _frog->getPosition()->getX();
	double frogY = _frog->getPosition()->getY();
	
	_width = width;
	_height = height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);

	gluPerspective(90.0, width / height, 1, 100);

	gluLookAt(frogX, frogY - (double)CUBE_SIZE/10, CUBE_SIZE*4, frogX, frogY + CUBE_SIZE, CUBE_SIZE, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
