#include "LampPost.h"


LampPost::LampPost(double x, double y, double z) : StaticObject(x, y, z)
{
}


void LampPost::draw()
{
}

vector<double> LampPost::getBoundaries()
{

	Vector3 *position = getPosition();
	vector<double> boundaries(4);

	boundaries[0] = position->getX() - (double)(POST_RADIUS);
	boundaries[1] = position->getX() + (double)(POST_RADIUS);
	boundaries[2] = position->getY() + (double)(POST_RADIUS);
	boundaries[3] = position->getY() - (double)(POST_RADIUS);

	return boundaries;
}