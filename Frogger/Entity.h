#ifndef ENTITY_H
#define ENTITY_H
#include "Vector3.h"

#define WIDTH_CUBES 15
#define HEIGHT_RIVER 2
#define MARGINS 2
#define HEIGHT_ROAD 2
#define CUBE_SIZE 1

using namespace std;
class Entity
{
protected:
	Vector3 *_position;

public:
	Entity(double x, double y, double z);
	Vector3* getPosition();
	Vector3* setPosition(double x, double y, double z);
	Vector3* setPosition(const Vector3& p);

};

#endif