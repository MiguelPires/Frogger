#include "Car.h"
#define altura 0.2
#define largura_x 0.5
#define largura_y 0.25
#define altura_vidro 0.2

Car::Car(double x, double y, double z) :DynamicObject(x, y, z){}
void Car::draw()
{
	glPushMatrix();
	Vector3 *pos = getPosition();
	glTranslated(pos->getX(), pos->getY(), pos->getZ()+0.1);

	//rodas tras
	glPushMatrix();
	glTranslated(-CAR_BLOCKSIZE, pos->getY() + 0.6, pos->getZ() - 2.05);
	
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(1, 1, 1);

	//roda 1 - esquerda/tras
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(0.0, 0.01125, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0, -0.01125, 0.0);
	glEnd();

	//bottom middle
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	
	glNormal3d(0.0, 0.0, -0.0075);
	glEnd();

	//bottom right

	glBegin(GL_POLYGON);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0075, 0.0, -0.0075);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	
	glNormal3d(0.0075, 0.0, 0.0);
	glEnd();

	//top right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);

	glNormal3d(0.0075, 0.0, 0.0075);
	glEnd();

	//top
	glBegin(GL_POLYGON);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);

	glNormal3d(0.0, 0.0, 0.0075);
	glEnd();

	//top left
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0075);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0);
	glEnd();

	//bottom left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);

	glNormal3d(-0.0075, 0.0, -0.0075);
	glEnd();

	//roda 2 - direita/tras
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, -0.05*1.5);
	
	glNormal3d(0.0, 0.01125, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, -0.05*1.5);
	
	glNormal3d(0.0, -0.01125, 0.0);
	glEnd();

	//bottom
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, -0.1*1.5);
	
	glNormal3d(0.0, 0.0, -0.0075);
	glEnd();

	//bottom right

	glBegin(GL_POLYGON);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0075, 0.0, -0.0075);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, +0.05*1.5);

	glNormal3d(0.0075, 0.0, 0.0);
	glEnd();

	//top right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);

	glNormal3d(0.0075, 0.0, 0.0075);
	glEnd();

	//top
	glBegin(GL_POLYGON);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, +0.1*1.5); 
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, +0.1*1.5);
	
	glNormal3d(0.0, 0.0, 0.0075);
	glEnd();

	//top left
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0075);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, -0.05*1.5);
	
	glNormal3d(-0.0075, 0.0, 0.0);
	glEnd();

	//bottom left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);

	glNormal3d(-0.0075, 0.0, -0.075);
	glEnd();

	glPopMatrix();

	glPopMatrix();
	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glColor3f(1.0, 0, 0);

	//carrocaria
	glBegin(GL_POLYGON); // face da frente
	glNormal3d(0.0, 0.4, 0.0);
	glVertex3d(largura_x, largura_y, altura);
	glNormal3d(0.0, 0.4, 0.0);
	glVertex3d(-largura_x, largura_y, altura);
	glNormal3d(0.0, 0.4, 0.0);
	glVertex3d(-largura_x, largura_y, -altura);
	glNormal3d(0.0, 0.4, 0.0);
	glVertex3d(largura_x, largura_y, -altura);

	glNormal3d(0.0, 0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON); //face de tras
	glNormal3d(0.0, -0.4, 0.0);
	glVertex3d(largura_x, -largura_y, altura);
	glNormal3d(0.0, -0.4, 0.0);
	glVertex3d(-largura_x, -largura_y, altura);
	glNormal3d(0.0, -0.4, 0.0);
	glVertex3d(-largura_x, -largura_y, -altura);
	glNormal3d(0.0, -0.4, 0.0);
	glVertex3d(largura_x, -largura_y, -altura);
	
	glNormal3d(0.0, -0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // parte cima
	glNormal3d(0.0, 0.0, 0.4);
	glVertex3d(largura_x, largura_y, altura);
	glNormal3d(0.0, 0.0, 0.4);
	glVertex3d(-largura_x, largura_y, altura);
	glNormal3d(0.0, 0.0, 0.4);
	glVertex3d(-largura_x, -largura_y, altura);
	glNormal3d(0.0, 0.0, 0.4);
	glVertex3d(largura_x, -largura_y, altura);
	
	glNormal3d(0.0, 0.0, 0.4);
	glEnd();

	glBegin(GL_POLYGON); // parte baixo
	glNormal3d(0.0, 0.0, -0.4);
	glVertex3d(largura_x, -largura_y, altura);
	glNormal3d(0.0, 0.0, -0.4);
	glVertex3d(-largura_x, -largura_y, -altura);
	glNormal3d(0.0, 0.0, -0.4);
	glVertex3d(-largura_x, -largura_y, altura);
	glNormal3d(0.0, 0.0, -0.4);
	glVertex3d(largura_x, -largura_y, -altura);
	
	glNormal3d(0.0, 0.0, -0.4);
	glEnd();

	glBegin(GL_POLYGON); // parte esquerda
	glNormal3d(-0.4, 0.0, 0.0);
	glVertex3d(-largura_x, largura_y, altura);
	glNormal3d(-0.4, 0.0, 0.0);
	glVertex3d(-largura_x, largura_y, -altura);
	glNormal3d(-0.4, 0.0, 0.0);
	glVertex3d(-largura_x, -largura_y, -altura);
	glNormal3d(-0.4, 0.0, 0.0);
	glVertex3d(-largura_x, -largura_y, altura);
	
	glNormal3d(-0.4, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // parte direita
	glNormal3d(0.4, 0.0, 0.0);
	glVertex3d(largura_x, largura_y, altura);
	glNormal3d(0.4, 0.0, 0.0);
	glVertex3d(largura_x, largura_y, -altura);
	glNormal3d(0.4, 0.0, 0.0);
	glVertex3d(largura_x, -largura_y, -altura);
	glNormal3d(0.4, 0.0, 0.0);
	glVertex3d(largura_x, -largura_y, altura);
	
	glNormal3d(0.4, 0.0, 0.0);
	glEnd();


	glColor3f(0, 0, 1.0);
	// vidro centro

	glBegin(GL_POLYGON); //face de tras
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(-0.2, -largura_y, altura);
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(0.2, -largura_y, altura);
	
	glNormal3d(0.0, -0.08, 0.0);
	glEnd();



	glBegin(GL_POLYGON); // parte baixo
	glNormal3d(0.0, 0.0, -0.08);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.0, -0.08);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.0, -0.08);
	glVertex3d(-0.2, -largura_y, altura);
	glNormal3d(0.0, 0.0, -0.08);
	glVertex3d(0.2, -largura_y, altura);
	
	glNormal3d(0.0, 0.0, -0.08);
	glEnd();

	glBegin(GL_POLYGON); // parte esquerda
	glNormal3d(-0.08, 0.0, 0.0);
	glVertex3d(-0.2, largura_y, altura + altura_vidro);
	glNormal3d(-0.08, 0.0, 0.0);
	glVertex3d(-0.2, largura_y, altura);
	glNormal3d(-0.08, 0.0, 0.0);
	glVertex3d(-0.2, -largura_y, altura);
	glNormal3d(-0.08, 0.0, 0.0);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	
	glNormal3d(-0.08, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // parte direita
	glNormal3d(0.08, 0.0, 0.0);
	glVertex3d(0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.08, 0.0, 0.0);
	glVertex3d(0.2, largura_y, altura);
	glNormal3d(0.08, 0.0, 0.0);
	glVertex3d(0.2, -largura_y, altura);
	glNormal3d(0.08, 0.0, 0.0);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	
	glNormal3d(0.08, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // face da frente
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(-0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(-0.2, largura_y, altura);
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(0.2, largura_y, altura);
	
	glNormal3d(0.0, 0.08, 0.0);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON); // parte cima
	glNormal3d(0.0, 0.0, 0.08);
	glVertex3d(0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.0, 0.08);
	glVertex3d(-0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.0, 0.08);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.0, 0.08);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	
	glNormal3d(0.0, 0.0, 0.08);
	glEnd();

	glColor3f(0, 0, 1);
	//vidro 2
	glBegin(GL_TRIANGLES); //frente
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(0.3, largura_y, altura);
	glNormal3d(0.0, 0.08, 0.0);
	glVertex3d(0.2, largura_y, altura);
	
	glNormal3d(0.0, 0.08, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES); //tras
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(0.3, -largura_y, altura);
	glNormal3d(0.0, -0.08, 0.0);
	glVertex3d(0.2, -largura_y, altura);
	
	glNormal3d(0.0, -0.08, 0.0);
	glEnd();

	glBegin(GL_POLYGON); //superficie cima
	glNormal3d(0.1, -0.02, 0.05);
	glVertex3d(0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.1, -0.02, 0.05);
	glVertex3d(0.3, -largura_y, altura);
	glNormal3d(0.1, -0.02, 0.05);
	glVertex3d(0.3, largura_y, altura);
	glNormal3d(0.1, -0.02, 0.05);
	glVertex3d(0.2, largura_y, altura + altura_vidro);
	
	glNormal3d(0.1, -0.02, 0.05);
	glEnd();

	//vidro 3
	glBegin(GL_TRIANGLES); //frente
	glNormal3d(0.0, 0.02, 0.0);
	glVertex3d(-0.2, largura_y, altura + altura_vidro);
	glNormal3d(0.0, 0.02, 0.0);
	glVertex3d(-0.3, largura_y, altura);
	glNormal3d(0.0, 0.02, 0.0);
	glVertex3d(-0.2, largura_y, altura);
	
	glNormal3d(0.0, 0.02, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES); //tras
	glNormal3d(0.0, -0.02, 0.0);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	glNormal3d(0.0, -0.02, 0.0);
	glVertex3d(-0.3, -largura_y, altura);
	glNormal3d(0.0, -0.02, 0.0);
	glVertex3d(-0.2, -largura_y, altura);
	
	glNormal3d(0.0, -0.02, 0.0);
	glEnd();


	glBegin(GL_POLYGON); //superficie cima
	glNormal3d(-0.1, -0.02, 0.05);
	glVertex3d(-0.2, -largura_y, altura + altura_vidro);
	glNormal3d(-0.1, -0.02, 0.05);
	glVertex3d(-0.3, -largura_y, altura);
	glNormal3d(-0.1, -0.02, 0.05);
	glVertex3d(-0.3, largura_y, altura);
	glNormal3d(-0.1, -0.02, 0.05);
	glVertex3d(-0.2, largura_y, altura + altura_vidro);
	
	glNormal3d(-0.1, -0.02, 0.05);
	glEnd();

	glPopMatrix();

	// rodas
	glPushMatrix();
	glTranslated(-CAR_BLOCKSIZE, pos->getY() + 0.04, pos->getZ() - 2.05);
	
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(1, 1, 1);

	//roda 1 - esquerda/frente
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(0.0, 0.01125, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0, -0.01125, 0.0);
	glEnd();

	//bottom middle
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);

	glNormal3d(0.0, 0.0, -0.0075);
	glEnd();

	//bottom right

	glBegin(GL_POLYGON);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0075, 0.0, -0.0075);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);

	glNormal3d(0.0075, 0.0, 0.0);
	glEnd();

	//top right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);

	glNormal3d(0.0075, 0.0, 0.0075);
	glEnd();

	//top
	glBegin(GL_POLYGON);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);

	glNormal3d(0.0, 0.0, 0.0075);
	glEnd();

	//top left
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0075);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0);
	glEnd();

	//bottom left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);

	glNormal3d(-0.0075, 0.0, -0.0075);
	glEnd();

	//roda 2 - direita/frente
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(0.0, 0.01125, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0, -0.01125, 0.0);
	glEnd();

	//bottom
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, -0.1*1.5);

	glNormal3d(0.0, 0.0, -0.0075);
	glEnd();

	//bottom right

	glBegin(GL_POLYGON);
	glNormal3d(0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, -0.1*1.5);
	glNormal3d(0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, -0.05*1.5);

	glNormal3d(0.0075, 0.0, -0.0075);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 + 0.1*1.5, 1.7, +0.05*1.5);

	glNormal3d(0.0075, 0.0, 0.0);
	glEnd();

	//top right
	glBegin(GL_POLYGON);
	glNormal3d(0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 + 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 + 0.05*1.5, 1.65, +0.1*1.5);

	glNormal3d(0.0075, 0.0, 0.0075);
	glEnd();

	//top
	glBegin(GL_POLYGON);
	glNormal3d(0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 + 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.8 - 0.05*1.5, 1.7, +0.1*1.5);

	glNormal3d(0.0, 0.0, 0.0075);
	glEnd();

	//top left
	glBegin(GL_POLYGON);
	glNormal3d(-0.0075, -0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, +0.1*1.5);
	glNormal3d(-0.0075, 0.01125, 0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, +0.1*1.5);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, +0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0075);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, 0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, 0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, +0.05*1.5);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.8 - 0.1*1.5, 1.7, -0.05*1.5);

	glNormal3d(-0.0075, 0.0, 0.0);
	glEnd();

	//bottom left
	glBegin(GL_POLYGON);
	glNormal3d(-0.015, -0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.65, -0.05*1.5);
	glNormal3d(-0.015, 0.01125, -0.0075);
	glVertex3d(+0.02 - 0.1*1.5, 1.7, -0.05*1.5);
	glNormal3d(-0.0075, 0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.7, -0.1*1.5);
	glNormal3d(-0.0075, -0.01125, -0.015);
	glVertex3d(+0.02 - 0.05*1.5, 1.65, -0.1*1.5);

	glNormal3d(-0.0075, 0.0, -0.075);
	glEnd();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

vector<double> Car::getBoundaries()
{
	Vector3 *position = getPosition();
	vector<double> boundaries(4);

	boundaries[0] = position->getX() - (double)(CAR_BLOCKSIZE  * CAR_SCALE) / 2;
	boundaries[1] = position->getX() + (double)(CAR_BLOCKSIZE  * CAR_SCALE) / 2;
	boundaries[2] = position->getY() + (double)(CAR_BLOCKSIZE) / 2;
	boundaries[3] = position->getY() - (double)(CAR_BLOCKSIZE) / 2;
	
	return boundaries;
}
