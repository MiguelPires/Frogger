#include "OrthoCam.h"

OrthoCam::OrthoCam(int width, int height) : Camera(width, height)
{
	myReshape(width, height);
}

void OrthoCam::myReshape(int width, int height)
{
	_width = width;
	_height = height;

	float xmin = -5., xmax = 5., ymin = -5., ymax = 5.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)width / height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		glOrtho(xmin - delta, xmax + delta, ymin, ymax, -50.0, 5.0);
	} else 
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		glOrtho(xmin, xmax, ymin - delta, ymax + delta, -50.0, 5.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
