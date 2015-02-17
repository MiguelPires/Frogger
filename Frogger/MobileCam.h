#ifndef MOBILE_CAM
#define MOBILE_CAM
#include "Camera.h"
#include "Frog.h"

class MobileCam :public Camera
{
	Frog *_frog;
public:
	MobileCam(int width, int height, Frog *frog);
	void myReshape(int width, int height);
};
#endif