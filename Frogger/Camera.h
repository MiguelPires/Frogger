#ifndef CAM
#define CAM
#include "Entity.h"

class Camera
{
protected:
	int _width, _height;

public:
	Camera(int width, int height);
	virtual void myReshape(int width, int height) = 0;
};

#endif