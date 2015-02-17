#include "Entity.h"
#include <iostream>

using namespace std;

Vector3 *Entity::getPosition()
{
	return _position;
}

Vector3 *Entity::setPosition(double x, double y, double z)
{
	_position->set(x, y, z);
	return _position;
}

Entity::Entity(double x, double y, double z)
{
	_position = new Vector3(x, y, z);
}

