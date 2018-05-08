#include "Collision.h"

namespace CollisionLibrary {
	Collision::Collision() { 
		this->colliderOffset = Vector3(1.0f, 1.0f, 1.0f);
	}

	/**
	*	Sets the collider size
	**/

	void Collision::SetColliderSize(Vector3 colSize) { this->colliderOffset = colSize; }

	void Collision::SetColliderSize(float x, float y, float z) { this->colliderOffset = Vector3(x, y, z); }

	/**
	*	Gets the collider Size
	**/

	Vector3 Collision::GetColliderSize() { return this->colliderOffset; } 

	/**
	*	returns true when 2 colliders collide
	**/

	bool Collision::HasCollidedWith(Collision &object) {
		bool xHasNotCollided =
			this->GetPosition().X - this->colliderOffset.X >
			object.GetPosition().X + object.colliderOffset.X ||
			this->GetPosition().X + this->colliderOffset.X <
			object.GetPosition().X - object.colliderOffset.X;

		bool yHasNotCollided = 
			this->GetPosition().Y - this->colliderOffset.Y >
			object.GetPosition().Y + object.colliderOffset.Y ||
			this->GetPosition().Y + this->colliderOffset.Y <
			object.GetPosition().Y - object.colliderOffset.Y;

		bool zHasNotCollided = 
			this->GetPosition().Z - this->colliderOffset.Z >
			object.GetPosition().Z + object.colliderOffset.Z ||
			this->GetPosition().Z + this->colliderOffset.Z <
			object.GetPosition().Z - object.colliderOffset.Z;

		if((xHasNotCollided || yHasNotCollided || zHasNotCollided))
			return false;
		else 
			return true;
	}
}