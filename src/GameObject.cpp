#include "GameObject.h"

namespace GameObjectLibrary {
	PrimitiveType::PrimitiveType() { }

	/**
	*	static variables of PrimitiveType class
	*	the developer has an option to use this class
	*	or write the proper string.
	**/

	const string PrimitiveType::Cube = "Cube";
	const string PrimitiveType::Triangle = "Triangle";
	const string PrimitiveType::Cone = "Cone";
	const string PrimitiveType::Torus = "Torus";
	const string PrimitiveType::Sphere = "Sphere";
	const string PrimitiveType::Plane = "Plane";

	bool PrimitiveType::operator==(const string &other) { return (*this == other); }

	/**
	*	GameObject class
	**/

	GLuint _textureId[100];

	GameObject::GameObject() { 
		this->active = true;
		this->hasTexture = false;
		this->scale = Vector3(1.0f, 1.0f, 1.0f);
		this->color = Color3(1.0f, 1.0f, 1.0f);
	}

	GameObject::GameObject(const char* filepath, int texID) {
		this->active = true;
		this->hasTexture = true;
		this->scale = Vector3(1.0f, 1.0f, 1.0f);
		this->color = Color3(1.0f, 1.0f, 1.0f);
		this->textureID = texID;

		Image* image = loadBMP(filepath);
		_textureId[0] = this->LoadTexture(image);
		delete image;
	}

	/**
	*	Method that sets the gameobject's visibility to the scene
	**/

	void GameObject::SetEnable(bool enable) { this->active = enable; }

	/**
	*	Draws the gameobject
	**/

	void GameObject::Draw(string type) {
		if(this->active) {
			if(type == PrimitiveType::Cube) this->DrawCube();
			else if(type == PrimitiveType::Triangle) this->DrawTriangle();
			else if(type == PrimitiveType::Cone) this->DrawCone();
			else if(type == PrimitiveType::Torus) this->DrawTorus();
			else if(type == PrimitiveType::Sphere) this->DrawSphere();
			else if(type == PrimitiveType::Plane) this->DrawPlane();
		}
	}

	void GameObject::DrawCube() {
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y , this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

		glutSolidCube(2.0f);

		glPopMatrix();
	}

	void GameObject::DrawTriangle() {
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y , this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);
		
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(-1.0f, -1.0f, 0.0f);
				glVertex3f(1.0f, -1.0f, 0.0f);
				glVertex3f(0.0f, 1.0f, 0.0f);
			glEnd();

		glPopMatrix();
	}

	void GameObject::DrawCone() { 
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

		glutSolidCone(1, 3, 50, 50);

		glPopMatrix();
	}

	void GameObject::DrawTorus() { 
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

			glutSolidTorus(0.5f, 1.0f, 20, 20);

		glPopMatrix();
	}

	void GameObject::DrawSphere() { 
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

			glutSolidSphere(1, 50, 50);

		glPopMatrix();
	}

	void GameObject::DrawPlane() {
		glPushMatrix();
		glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
		glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
		glRotatef(this->GetAngle(), this->GetAxis().X, this->GetAxis().Y, this->GetAxis().Z);
		glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);
		glNormal3f(0.0f, 0.0f, 1.0f);

		if(this->hasTexture) {
			glBindTexture(GL_TEXTURE_2D, _textureId[0]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glBegin(GL_QUADS);
			glTexCoord2f(1, 1);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(0, 1);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glTexCoord2f(0, 0);
			glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1, 0);
			glVertex3f( 1.0f,-1.0f, 0.0f);
			glEnd();
		}
		else {
			glBegin(GL_TRIANGLE_STRIP); 
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);

			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glEnd();
		}

		glPopMatrix();
	}

	GLuint GameObject::LoadTexture(Image* image) {
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
}