#include "Transform.h"

namespace TransformLibrary {
	Transform::Transform() { 
		this->position = Vector3(0.0f, 0.0f, 0.0f);
		this->scale = Vector3(1.0f, 1.0f, 1.0f);
		this->color = Color3(1.0f, 1.0f, 1.0f);
		this->rot = 0.0f;
		this->axis = Vector3(0.0f, 0.0f, 0.0f);
	}

	/**
	*	Sets the color of the gameobject
	**/

	void Transform::SetColor(Color3 Color) {
		this->color = Color;
	}

	void Transform::SetColor(float r, float g, float b) {
		this->color = Color3(r, g, b);
	}

	Color3 Transform::GetColor() { 
		return this->color;
	}

	/**
	*	Sets the scale of the gameobject
	**/

	void Transform::SetScale(Vector3 scl) {
		this->scale = scl;
	}

	void Transform::SetScale(float sclX, float sclY, float sclZ) {
		this->scale = Vector3(sclX, sclY, sclZ);
	}

	Vector3 Transform::GetScale() {
		return this->scale; 
	}

	/**
	*	Sets the position of the gameobject
	**/

	void Transform::SetPosition(Vector3 pos) {
		this->position = pos;
	}

	void Transform::SetPosition(float x, float y, float z) {
		this->position = Vector3(x, y, z);
	}

	Vector3 Transform::GetPosition() { 
		return this->position; 
	}

	/**
	*	Sets the rotation of the gameobject
	**/

	void Transform::SetRotation(float angle, Vector3 rotationAxis) {
		this->rot = angle;
		this->axis = rotationAxis;
	}

	float Transform::GetAngle() { 
		return this->rot; 
	}

	Vector3 Transform::GetAxis() {
		return this->axis; 
	}
}