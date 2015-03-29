#include "GameObject.h"

namespace GameObjectLibrary {
	PrimitiveType::PrimitiveType() { }

	const string PrimitiveType::Cube = "Cube";
	const string PrimitiveType::Triangle = "Triangle";
	const string PrimitiveType::Cone = "Cone";
	const string PrimitiveType::Torus = "Torus";
	const string PrimitiveType::Sphere = "Sphere";
	const string PrimitiveType::Plane = "Plane";

	bool PrimitiveType::operator==(const string &other) { return (*this == other); }

	GameObject::GameObject() { 
		this->active = true;
		this->scale = Vector3(1.0f, 1.0f, 1.0f);
		this->color = Color3(1.0f, 1.0f, 1.0f);
	}

	void GameObject::SetEnable(bool enable) { this->active = enable; }

	void GameObject::Draw(string type) {
		if(type == PrimitiveType::Cube) this->DrawCube();
		else if(type == PrimitiveType::Triangle) this->DrawTriangle();
		else if(type == PrimitiveType::Cone) this->DrawCone();
		else if(type == PrimitiveType::Torus) this->DrawTorus();
		else if(type == PrimitiveType::Sphere) this->DrawSphere();
		else if(type == PrimitiveType::Plane) this->DrawPlane();
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

			glBegin(GL_TRIANGLE_STRIP); 
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);

			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glEnd();

		glPopMatrix();
	}
}