#include "gameManager.h"
#define CARS 3
#define BUSES 5
#define TIMBERLOGS 3
#define TURTLES 3
// 1/2 minuto
#define TIME_TO_INCREASE 1000 * 30
#define NUM_LAMPS 6
#define INIT_LIVES 5

using namespace std;

River *river;
Riverside *riverside[MARGINS];
Roadside *roadside[MARGINS];
Road *road;
Car *cars[CARS];
Bus *buses[BUSES];
Timberlog *timberlogs[TIMBERLOGS];
Turtle *turtles[TURTLES];
Frog *frog;
Camera *cameras[3];
GlobalLight* globalLight;
Spotlight *spotlights[NUM_LAMPS];
LampPost *lampPosts[NUM_LAMPS];
FrogFigure *frogFigures[INIT_LIVES];

// velocidades
int carSpeed = 20;
int busSpeed = 40;
int timberlogSpeed = 60;
int turtleSpeed = 30;

// se estão objectos em espera para serem desenhados
int prevTime = 0;
int carWaiting = 0;
int busWaiting = 0;
int timberlogWaiting = 0;
int turtleWaiting = 0;

int lives = 5;
int points = 0;

int activeCamera = 0;

bool gamePaused = false;

void keyboard(unsigned char key, int x, int y)
{

	if (key == 's' || key == 'S')
	{
		togglePause();
		cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
	}
		
	if (gamePaused)
		return;

	if (lives > 0)
	{
		switch (key)
		{
			// left
		case 'O':
		case 'o':
			frog->move('l', lampPosts, NUM_LAMPS);
			break;

			// right
		case 'P':
		case 'p':
			frog->move('r', lampPosts, NUM_LAMPS);
			break;

			// up
		case 'Q':
		case 'q':
			if (frog->move('u', lampPosts, NUM_LAMPS))
			{
				++points;
				frog->reset();
			}
			break;

			// down
		case 'A':
		case 'a':
			frog->move('d', lampPosts, NUM_LAMPS);
			break;

		case '1':
			activeCamera = 0;
			setLighting();
			break;

		case '2':
			activeCamera = 1;
			setLighting();
			break;

		case '3':
			activeCamera = 2;
			setLighting();
			break;

		case 'l':
		case 'L':
			toggleGlobalLight();
			break;

		case 'n':
		case 'N':
			toggleDayNight();
			break;

		case 'c':
		case 'C':
			toggleLamps();
			break;

		/*case 'h':
		case 'H':
			toggleHelmetLamp();
			break;*/
		}
	}

	switch (key)
	{

	case 'r':
	case 'R':
		if (lives == 0)
			resetGame();
		break;
	}

	frog->checkObjects(turtles, TURTLES, timberlogs, TIMBERLOGS);

	if (frog->checkCollision(cars, buses, CARS, BUSES, river))
		decrementLives();
	
	cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glutPostRedisplay();
}

void togglePause()
{
	if (gamePaused)
		gamePaused = false;
	else
		gamePaused = true;
}

void toggleGlobalLight()
{
	if (glIsEnabled(GL_LIGHTING))
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		glDisable(GL_LIGHT6);
		glDisable(GL_LIGHT7);
	}
	else{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT7);
	}

	setLighting();
}

void toggleDayNight()
{
	if (!glIsEnabled(GL_LIGHTING) || glIsEnabled(GL_LIGHT1))
		return;
	
	if (glIsEnabled(GL_LIGHT0)){
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT7);
	}
	else{
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT7);
	}

	setLighting();

}

void toggleLamps()
{
	if (!glIsEnabled(GL_LIGHTING) || glIsEnabled(GL_LIGHT0))
		return;

	if (glIsEnabled(GL_LIGHT1))
	{
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		glDisable(GL_LIGHT6);

	} else 	{
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		glEnable(GL_LIGHT6);
	}
	setLighting();
}

/*void toggleHelmetLamp()
{
	if (!glIsEnabled(GL_LIGHTING))
		return;

	if (glIsEnabled(GL_LIGHT7))
		glDisable(GL_LIGHT7);
	else
		glEnable(GL_LIGHT7);

}*/
void reshape(int width, int height)
{
	if (height == 0)
		height = 1;
	cameras[activeCamera]->myReshape(width, height);
}

void drawNewCar(int value)
{
	if (gamePaused)
	{
		double randomSpeed;
		randomSpeed = ((double)rand() / (RAND_MAX)) * 5000 + carSpeed * 70;
		glutTimerFunc(randomSpeed, drawNewCar, 0);
		return;
	}

	for (int i = 0; i < CARS; i++)
		if (cars[i]->isDrawn() == false){
			cars[i]->changeDrawnState(true);
			cars[i]->draw();	
			break;
		}
		carWaiting = 0;
}

void drawNewBus(int value)
{
	if (gamePaused)
	{
		double randomSpeed;
		randomSpeed = ((double)rand() / (RAND_MAX)) * 5000 + busSpeed * 70;
		glutTimerFunc(randomSpeed, drawNewBus, 0);
		return;
	}

	for (int i = 0; i < BUSES; i++)
		if (buses[i]->isDrawn() == false)
		{
			buses[i]->changeDrawnState(true);
			buses[i]->draw();
			break;
		}
	busWaiting = 0;
}

void drawNewTimberlog(int value)
{
	if (gamePaused)
	{
		double randomSpeed;
		randomSpeed = ((double)rand() / (RAND_MAX)) * 5000 + timberlogSpeed * 20;
		glutTimerFunc(randomSpeed, drawNewTimberlog, 0);
		return;
	}

	for (int i = 0; i < TIMBERLOGS; i++)
		if (timberlogs[i]->isDrawn() == false)
		{
			timberlogs[i]->changeDrawnState(true);
			timberlogs[i]->draw();		
			break;
		}
	timberlogWaiting = 0;
}

void drawNewTurtle(int value)
{
	if (gamePaused)
	{
		double randomSpeed;
		randomSpeed = ((double)rand() / (RAND_MAX)) * 5000 + turtleSpeed * 20;
		glutTimerFunc(randomSpeed, drawNewTurtle, 0);
		return;
	}

	for (int i = 0; i < TURTLES; i++)
		if (turtles[i]->isDrawn() == false)
		{
			turtles[i]->changeDrawnState(true);
			turtles[i]->draw();	
			break;
		}
	turtleWaiting = 0;
}

void display(void)
{
	bool lightsOn = false;
	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	drawStaticObjects();

	if (lives > 0)
		drawMobileObjects();

	else{
		if (glIsEnabled(GL_LIGHTING))
		{
			lightsOn = true;
			glDisable(GL_LIGHTING);
		}
		
		cameras[0]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		Text *string = new Text(0,0,30, "gameOver.png", 1,0,0);
		glPushMatrix();
		glTranslated(-2.5, -2.0, 30);
		string->draw();
		glPopMatrix();
		if (lightsOn)
			glEnable(GL_LIGHTING);
	}

	if (gamePaused){
		if (glIsEnabled(GL_LIGHTING))
		{
			lightsOn = true;
			glDisable(GL_LIGHTING);
		}
		glPushMatrix();
		glTranslated( -2.5, -2.0, 30);
		cameras[0]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		Text *string = new Text(0, 0, 0, "paused.png", 1,0,0);
		glPushMatrix();
		glTranslated(-2.5, -2.0, 30);
		string->draw();
		glPopMatrix();
		if (lightsOn)
			glEnable(GL_LIGHTING);
	}

	displayHUD();

	glutSwapBuffers();
}

void drawMobileObjects()
{
	double randomSpeed;

	for (int i = 0; i < CARS; i++)
	{
		if (cars[i]->isDrawn())
			cars[i]->draw();		//desenha carros já no ecrã

		else
		{
			randomSpeed = ((double)rand() / (RAND_MAX)) * 7000 + carSpeed * 100;
			if (!carWaiting)
			{
				carWaiting = 1;
				glutTimerFunc(randomSpeed, drawNewCar, 0);
				// se nao tiver carro desenhado vai mandar um timer aleatorio para o desenhar
			}
		}
	}

	for (int i = 0; i < BUSES; i++)
	{
		if (buses[i]->isDrawn())
			buses[i]->draw();		//desenha autocarros já no ecrã

		else
		{
			randomSpeed = ((double)rand() / (RAND_MAX)) * 7000 + busSpeed * 90;
			if (!busWaiting)
			{
				busWaiting = 1;
				glutTimerFunc(randomSpeed, drawNewBus, 0);
				// se nao tiver autocarro desenhado vai mandar um timer aleatorio para o desenhar
			}
		}
	}

	for (int i = 0; i < TURTLES; i++)
	{
		if (turtles[i]->isDrawn())
			turtles[i]->draw();		//desenha tartarugas já no ecrã

		else
		{
			randomSpeed = ((double)rand() / (RAND_MAX)) * 7000 + turtleSpeed * 70;
			if (!turtleWaiting)
			{
				turtleWaiting = 1;
				glutTimerFunc(randomSpeed, drawNewTurtle, 0);
				// se nao tiver tartaruga desenhada vai mandar um timer aleatorio para o desenhar
			}
		}

	}

	for (int i = 0; i < TIMBERLOGS; i++)
	{
		if (timberlogs[i]->isDrawn())
			timberlogs[i]->draw();		//desenha troncos já no ecrã

		else
		{
			randomSpeed = ((double)rand() / (RAND_MAX)) * 7000 + timberlogSpeed * 80;

			if (!timberlogWaiting)
			{
				timberlogWaiting = 1;
				glutTimerFunc(randomSpeed, drawNewTimberlog, 0);
				// se nao tiver tronco desenhado vai mandar um timer aleatorio para o desenhar
			}
		}
	}

	frog->draw();
}

void drawStaticObjects()
{
	for (int i = 0; i < MARGINS; i++)
			riverside[i]->draw();

	river->draw();

	for (int i = 0; i < MARGINS; i++)
			roadside[i]->draw();

	road->draw();

	for (int i = 0; i < NUM_LAMPS; i++)
		lampPosts[i]->draw();
}

void initGameObjects()
{
	// River
	river = new River(0, (double)CUBE_SIZE*MARGINS/2 + 0.55, CUBE_SIZE);

	// Riverside cubes
	for (int i = 1; i <= MARGINS; ++i)
		riverside[i - 1] = new Riverside(0, (i - 1)*(HEIGHT_RIVER + 1)*CUBE_SIZE + (double)CUBE_SIZE/2 -1.0, CUBE_SIZE);
	
	// Roadside cubes
	for (int i = 1; i <= MARGINS; i++)
		roadside[i - 1] = new Roadside(0, -(i - 1)*(HEIGHT_ROAD + 1)*CUBE_SIZE - (double)CUBE_SIZE/2 -1.0, CUBE_SIZE );

	// Road cubes
	road = new Road(0, -CUBE_SIZE - CUBE_SIZE - (double)CUBE_SIZE / 2 +0.05, CUBE_SIZE);

	// Car
	for (int i = 0; i < CARS; i++)
		cars[i] = new Car((WIDTH_CUBES*CUBE_SIZE - CUBE_SIZE * 2) / 2, -2 * CUBE_SIZE, 2.0*CUBE_SIZE);
		
	// Bus
	for (int i = 0; i < BUSES; i++)
		buses[i] = new Bus((WIDTH_CUBES*CUBE_SIZE - CUBE_SIZE * 3) / 2, -3 * CUBE_SIZE, 2.0*CUBE_SIZE);
	
	// timberlog
	for (int i = 0; i < TIMBERLOGS; i++)
		timberlogs[i] = new Timberlog((WIDTH_CUBES*CUBE_SIZE - CUBE_SIZE * 2) / 2, CUBE_SIZE, 1.5*CUBE_SIZE);
	
	// turtles
	for (int i = 0; i < TURTLES; i++)
		turtles[i] = new Turtle((WIDTH_CUBES*CUBE_SIZE - CUBE_SIZE * 2) / 2, CUBE_SIZE*HEIGHT_RIVER, 1.5*CUBE_SIZE);
	
	//frog
	frog = new Frog(0.0, -CUBE_SIZE*(HEIGHT_ROAD+MARGINS),2.0*CUBE_SIZE);

	// lamps
	lampPosts[0] = new CenterLamp(-3.0, -.5, 3.5);
	lampPosts[1] = new CenterLamp(3.0, -.5, 3.5);
	lampPosts[2] = new UpLamp(-4.0, 3.0, 3.5);
	lampPosts[3] = new UpLamp(4.0, 3.0, 3.5);
	lampPosts[4] = new DownLamp(-4.0, -4.0, 3.5);
	lampPosts[5] = new DownLamp(4.0, -4.0, 3.5);

	//camera
	cameras[0] = new OrthoCam(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	cameras[1] = new PerspectiveCam(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	cameras[2] = new MobileCam(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), frog);

	//frog figures
	for (int i = 0; i < INIT_LIVES; i++)
		frogFigures[i] = new FrogFigure(-7.25+(double)2.0*i*CUBE_SIZE/3.0, (double)CUBE_SIZE*(HEIGHT_ROAD +HEIGHT_RIVER), 4.0*CUBE_SIZE);
	
	
}

void moveObjects(int value)
{
	glutTimerFunc(busSpeed, moveBuses, value);
	glutTimerFunc(carSpeed, moveCars, value);
	glutTimerFunc(timberlogSpeed, moveTimberlogs, value);
	glutTimerFunc(turtleSpeed, moveTurtles, value);
}

void moveTurtles(int value)
{
	if (gamePaused)
	{
		glutTimerFunc(turtleSpeed, moveTurtles, value);
		return;
	}

	for (int i = 0; i < TURTLES; i++)
		turtles[i]->autoMove();
	frog->checkObjects(turtles, TURTLES, timberlogs, TIMBERLOGS);

	if (frog->onTurtle()){
		frog->autoMove();
		cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	}

	glutTimerFunc(turtleSpeed, moveTurtles, value);
	glutPostRedisplay();

}

void moveTimberlogs(int value)
{
	if (gamePaused)
	{
		glutTimerFunc(timberlogSpeed, moveTimberlogs, value);
		return;
	}

	for (int i = 0; i < TIMBERLOGS; i++)
		timberlogs[i]->autoMove();
	frog->checkObjects(turtles, TURTLES, timberlogs, TIMBERLOGS);

	if (frog->onTimberlog()){
		frog->autoMove();
		cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)); // move a mobileCam quando o sapo está em cima do tronco
	}

	glutTimerFunc(timberlogSpeed, moveTimberlogs, value);
	glutPostRedisplay();
}
void moveCars(int value)
{
	if (gamePaused)
	{
		glutTimerFunc(carSpeed, moveCars, value);
		return;
	}

	for (int i = 0; i < CARS; i++)
	{
		cars[i]->autoMove();
		cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)); // move a mobileCam quando o sapo está em cima do tronco
	}

	if (frog->checkCollision(cars, buses, CARS, BUSES, river))
		decrementLives();

	glutTimerFunc(carSpeed, moveCars, value);
	glutPostRedisplay();
}

void moveBuses(int value)
{
	if (gamePaused)
	{
		glutTimerFunc(busSpeed, moveBuses, value);
		return;
	}

	for (int i = 0; i < BUSES; i++)
	{
		buses[i]->autoMove();
		cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)); // move a mobileCam quando o sapo está em cima do tronco
	}
	if (frog->checkCollision(cars, buses, CARS, BUSES, river))
		decrementLives();
	
	glutTimerFunc(busSpeed, moveBuses, value);
	glutPostRedisplay();
}

void decrementLives()
{
	--lives;
	if (lives == 0)
		glDisable(GL_LIGHT7);
}

void increaseSpeeds()
{
	carSpeed -= carSpeed/10;
	busSpeed -= busSpeed/10;
	timberlogSpeed -= timberlogSpeed/10;
	turtleSpeed -= turtleSpeed/10;
}
void idle()
{
	if (gamePaused)
		return;

	int currentTime = glutGet(GLUT_ELAPSED_TIME);

	if (currentTime - prevTime >= TIME_TO_INCREASE)
	{
		prevTime = currentTime;
		increaseSpeeds();
	}
}

void printText(const char* string, double x)
{
	bool lightsOn = false;
	
	if (glIsEnabled(GL_LIGHTING))
	{
		lightsOn = true;
		glDisable(GL_LIGHTING);
	}

	cameras[0]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

	glPushMatrix();

	glTranslatef(x, -0.5, 4.0);
	glScalef(1 / 100.0, 1 / 100.0, 1 / 100.0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	
	for (int i = 0; string[i] != '\0'; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);

	glPopMatrix();

	if (lightsOn)
		glEnable(GL_LIGHTING);

	cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glPopMatrix();

}


void displayHUD()
{
	string str;
	bool lightsOn = false;
	
	if (glIsEnabled(GL_LIGHTING))
	{
		lightsOn = true;
		glDisable(GL_LIGHTING);
	}

	cameras[0]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

	glPushMatrix();					// vidas
	glTranslatef(0,0,20.0);
	for (int i = 0; i < lives; i++)
		frogFigures[i]->draw();

	glPopMatrix();
	

	glPushMatrix();									// pontos
	glTranslatef(3.0, 3.7, 20.0);

	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

	Text *pointsMessage = new Text(0, 0, 0, "points.png",0,0,1);
	pointsMessage->resize(2.5,0.8);
	pointsMessage->draw();

	string numbOne, numbTwo, numbThree;
	str = to_string(points);
	if (points < 10){
		numbOne = str;
		numbTwo = "0";
		numbThree = "0";
	}
	else if (points >= 10 && points < 100){
		numbOne = str[1];
		numbTwo = str[0];
		numbThree = "0";
	}
	else{
		numbOne = str[2];
		numbTwo = str[1];
		numbThree = str[0];
	}

	numbOne = numbOne + ".png";
	Text *OnePoints = new Text(0, 0, 0, numbOne.c_str(), 0, 0, 1);
	OnePoints->resize(0.4, 0.6);
	glTranslatef(3.5, 0.08, 0.0);
	OnePoints->draw();

	numbTwo = numbTwo + ".png";
	Text *TwoPoints = new Text(0, 0, 0, numbTwo.c_str(), 0, 0, 1);
	TwoPoints->resize(0.4, 0.6);
	glTranslatef(-0.4, 0.0, 0.0);
	TwoPoints->draw();

	numbThree = numbThree + ".png";
	Text *ThreePoints = new Text(0, 0, 0, numbThree.c_str(), 0, 0, 1);
	ThreePoints->resize(0.4, 0.6);
	glTranslatef(-0.4, 0.0, 0.0);
	ThreePoints->draw();

	glPopMatrix();
	
	if (lightsOn)
		glEnable(GL_LIGHTING);

	cameras[activeCamera]->myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void resetGame()
{
	lives = 5;
	points = 0;

	for (int i = 0; i < CARS; i++)
		cars[i]->reset();

	for (int i = 0; i < BUSES; i++)
		buses[i]->reset();

	for (int i = 0; i < TURTLES; i++)
		turtles[i]->reset();

	for (int i = 0; i < TIMBERLOGS; i++)
		timberlogs[i]->reset();
	
	if (!glIsEnabled(GL_LIGHT0))
		glEnable(GL_LIGHT7); // liga lampada do sapo

	carSpeed = 20;
	busSpeed = 40;
	timberlogSpeed = 60;
	turtleSpeed = 30;

	frog->reset();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(980, 586);
	glutInitWindowPosition(-1,-1);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glutCreateWindow("Frogger");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	moveObjects(0);
	initLighting();
	initGameObjects();

	glutMainLoop();
	return 0;
}

void initLighting()
{
	globalLight = new GlobalLight(0.0, 0.0, 6.0);

	spotlights[0] = new Spotlight(-3.0, -.5, 4.0, 'c', GL_LIGHT1);
	spotlights[1] = new Spotlight(3.0, -.5, 4.0, 'c', GL_LIGHT2);
	spotlights[2] = new Spotlight(-4.0, -3.5, 3.6, 'd', GL_LIGHT3);
	spotlights[3] = new Spotlight(4.0, -3.5, 3.6, 'd', GL_LIGHT4);
	spotlights[4] = new Spotlight(-4.0, 3.0, 3.6, 'u', GL_LIGHT5);
	spotlights[5] = new Spotlight(4.0, 3.0, 3.6, 'u', GL_LIGHT6);

	setLighting();
}
void setLighting()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_NORMALIZE);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);

	GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	setGlobalLighting();
	setLampLighting();
	glutPostRedisplay();
}

void setGlobalLighting()
{
	if (glIsEnabled(GL_LIGHT0))
		globalLight->refresh();
}

void setLampLighting()
{
	if (glIsEnabled(GL_LIGHT1))
		for (int i = 0; i < NUM_LAMPS; i++)
			spotlights[i]->refresh();
}