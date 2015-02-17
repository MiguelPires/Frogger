#include "Riverside.h"
#include<Windows.h>
#include "SOIL.h"

#define triangulos 170

Riverside::Riverside(double x, double y, double z) :StaticObject(x, y, z){
	applyTexture();
}

void Riverside::draw()
{
	Vector3 *pos = getPosition();

	glPushMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glColor3f((float)18 / 255, (float)181 / 255, (float)56 / 255);

	glTranslated(pos->getX(), pos->getY(), pos->getZ());
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tex);
	glNormal3d(0.0, 0.0, 30.0);

	for (double i = 0; i < 1; i += (double)WIDTH_CUBES / triangulos)
	for (double j = -(double)WIDTH_CUBES / 2; j <= (double)WIDTH_CUBES / 2; j += (double)WIDTH_CUBES / triangulos)
	{
		glBegin(GL_TRIANGLES);

		glTexCoord2d(j, i);
		glVertex3d(j, 0.0 + i, (double)CUBE_SIZE / 2);		// se

		glTexCoord2d(j, -(double)WIDTH_CUBES / triangulos + i);
		glVertex3d(j, -(double)WIDTH_CUBES / triangulos + i, (double)CUBE_SIZE / 2); //ie

		glTexCoord2d(j + (double)WIDTH_CUBES / triangulos, i);
		glVertex3d(j + (double)WIDTH_CUBES / triangulos, 0.0 + i, (double)CUBE_SIZE / 2); //sd

		glEnd();

		glBegin(GL_TRIANGLES);

		glTexCoord2d(j + (double)WIDTH_CUBES / triangulos, -(double)WIDTH_CUBES / triangulos + i);
		glVertex3d(j + (double)WIDTH_CUBES / triangulos, -(double)WIDTH_CUBES / triangulos + i, (double)CUBE_SIZE / 2); // id

		glTexCoord2d(j, -(double)WIDTH_CUBES / triangulos + i);
		glVertex3d(j, -(double)WIDTH_CUBES / triangulos + i, (double)CUBE_SIZE / 2); //sd

		glTexCoord2d(j + (double)WIDTH_CUBES / triangulos, i);
		glVertex3d(j + (double)WIDTH_CUBES / triangulos, 0.0 + i, (double)CUBE_SIZE / 2); //ie

		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}

void Riverside::applyTexture()
{
	GLuint texture = SOIL_load_OGL_texture
		(
		"grass.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	if (0 == texture)
		cout << "SOIL loading error: " << SOIL_last_result() << endl;


	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	_tex = texture;
}
