#ifndef PERSPECTIVE_CAM
#define PERSPECTIVE_CAM
#include "Camera.h"
class PerspectiveCam : public Camera
{
public:
	PerspectiveCam(int width, int height);
	void myReshape(int width, int height);

};

#endif