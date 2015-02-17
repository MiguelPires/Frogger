#ifndef FROG_H
#define FROG_H
#include "DynamicObject.h"
#include "Car.h"
#include "Bus.h"
#include "River.h"
#include "Timberlog.h"
#include "Turtle.h"
#include "LampPost.h"
#include "Headlight.h"

class Frog : public DynamicObject
{
	bool _onTimberlog = false;
	bool _onTurtle = false;
	Headlight *_lamp;
	char _direction; //up - u; down - d; right - r; left - l
	int _angle = 0; 
	bool _rotate = false;
public:
	int Frog::move(char direction, LampPost *posts[], int numPosts);
	void autoMove();
	Frog(double x, double y, double z);
	void draw();
	void reset();
	void die();
	bool edgesCollided (vector<double> boundaries);
	bool centerCollided (vector<double> boundaries);
	bool checkCollision(Car **cars, Bus **buses, int numCars, int numBuses,
					River *river);
	void checkObjects(Turtle **turtles, int nTurtles, Timberlog **timbers, int nTimberlogs);
	bool onPlatform();
	bool onTurtle();
	bool onTimberlog();

};
#endif