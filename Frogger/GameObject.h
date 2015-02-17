#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Entity.h"

class GameObject: public Entity
{
public:
	GameObject(double x, double y, double z);
	void draw(void);
	void update(double delta_t);
};
#endif