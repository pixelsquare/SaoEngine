#ifndef __SAOENGINE_TEXTURE_LOADER_LIBRARY_H__
#define __SAOENGINE_TEXTURE_LOADER_LIBRARY_H__


#include<glut.h>

#include "ImageLoader.h"

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId[10];
void LoadTextures(const char* _filepath, int _textureID) {
	Image* image = loadBMP(_filepath);
	_textureId[_textureID] = loadTexture(image);
	delete image;
}
#endif