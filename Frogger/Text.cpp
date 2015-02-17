#include "Text.h"
#include <Windows.h>
#include "SOIL.h"

Text::Text(double x, double y, double z, const char *name, float red, float green, float blue) :StaticObject(x, y, z){
	_red = red;
	_green = green;
	_blue = blue;
	_xSize = 5.0;
	_ySize = 2.0;
	applyTexture(name);
}

void Text::draw()
{
	glPushMatrix();
	//Vector3 *pos = getPosition();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tex);
	glNormal3d(0.0, 0.0, 30.0);
	glColor3f(_red, _green, _blue);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 0);
		glVertex3d(0, 0, 0);		

		glTexCoord2d(0,1);
		glVertex3d(0,_ySize,0); 

		glTexCoord2d(1,1);
		glVertex3d(_xSize,_ySize,0); 

		glTexCoord2d(1, 0);
		glVertex3d(_xSize, 0, 0); 

		glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Text::applyTexture(const char *name)
{
	GLuint texture = SOIL_load_OGL_texture
		(
		name,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	if (0 == texture)
		cout << "SOIL loading error: " << SOIL_last_result() << endl;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	

	_tex = texture;
}

void Text::resize(double x, double y){
	_xSize = x;
	_ySize = y;
}