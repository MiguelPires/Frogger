#ifndef ORTHO_CAM
#define ORTHO_CAM
#include "Camera.h"

class OrthoCam : public Camera
{
public:
	OrthoCam(int width, int height);
	void myReshape(int width, int height);
}; 

#endif