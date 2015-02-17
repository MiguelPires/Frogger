#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include "Riverside.h"
#include "River.h"
#include "Roadside.h"
#include "Road.h"
#include "Car.h"
#include "Bus.h"
#include "Timberlog.h"
#include "Turtle.h"
#include "Text.h"
#include "Frog.h"
#include "OrthoCam.h"
#include "PerspectiveCam.h"
#include "MobileCam.h"
#include "GlobalLight.h"
#include "Spotlight.h"
#include "CenterLamp.h"
#include "UpLamp.h"
#include "DownLamp.h"
#include "FrogFigure.h"
#include <stdio.h>
#include <string>
using namespace std;

void reshape(int height, int width);
void display();
void specialKeys(int key, int x, int y);
void idle();
void initGameObjects();
void moveObjects(int value);
void moveCars(int value);
void moveBuses(int value);
void moveTimberlogs(int value);
void moveTurtles(int value);
void printText(const char* string, double x);
void resetGame();
void drawMobileObjects();
void drawStaticObjects();
void initLighting();
void setLighting();
void setGlobalLighting();
void setLampLighting();
void toggleGlobalLight();
void toggleDayNight();
void toggleLamps();
void toggleHelmetLamp();
void displayHUD();
void gameWon();
void hud();
void togglePause();
void decrementLives();