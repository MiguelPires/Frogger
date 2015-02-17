#include "PerspectiveCam.h"

PerspectiveCam::PerspectiveCam(int width, int height) : Camera(width, height)
{
	myReshape(width, height);
}

void PerspectiveCam::myReshape(int width, int height)
{
	_width = width;
	_height = height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);

	gluPerspective(90.0, width / height, 0.1, 100);

	gluLookAt(0.0, -CUBE_SIZE*(HEIGHT_ROAD)*4.0, 8.5, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
