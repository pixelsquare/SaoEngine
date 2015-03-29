#include "Physics.h"

/* Physics library declaration */
namespace PhysicsLibrary {

	Physics::Physics() {
		this->mass = 1.0f;
		this->velocity = Vector3::Zero;
		this->acceleration = Vector3::Zero;
		this->useGravity = false;
		this->gravityApplied = false;
		this->isActive = true;
	}

	Physics::~Physics() { }

	void Physics::SetActivePhysics(bool active) {
		this->isActive = active;
	}

	void Physics::SetMass(float objectMass) {
		if(objectMass > 0)
			this->mass = objectMass;
	}

	void Physics::AddVelocity(Vector3 objVel) {
		this->velocity += objVel;
	}

	void Physics::AddVelocity(float x, float y, float z) {
		this->velocity += Vector3(x, y, z);
	}

	void Physics::SetVelocity(Vector3 vel) {
		this->velocity = vel;
	}

	void Physics::SetVelocity(float x, float y, float z) {
		this->velocity = Vector3(x, y, z);
	}

	Vector3 Physics::GetVelocity() {
		return this->velocity;
	}

	void Physics::AddAcceleration(Vector3 objAccel) {
		this->acceleration += objAccel;
	}

	void Physics::AddAcceelration(float x, float y, float z) {
		this->acceleration += Vector3(x, y, z);
	}

	void Physics::SetAcceleration(Vector3 accel) {
		this->acceleration = accel;
	}

	void Physics::SetAcceleration(float x, float y, float z) {
		this->acceleration = Vector3(x, y, z);
	}

	Vector3 Physics::GetAcceleration() {
		return this->acceleration;
	}

	void Physics::UseGravity(bool flag) {
		if(!this->isActive) return;

		this->useGravity = flag;

		// When gravity is turned off 
		// Set the acceleration opposite to the current acceleration
		// this will cause to a constant velocity to the object

		if(!this->useGravity && this->gravityApplied) {
			if(this->acceleration != Vector3::Zero)
				this->AddAcceleration(Vector3::Up * GRAVITY * this->mass);

			this->gravityApplied = false;
		}

		// Gravity is Applied when this function is called
		// as well as the useGravity flag has been triggered
		// Set the acceleration -9.8 when the flag is true

		if(this->useGravity && !this->gravityApplied) {
			this->acceleration = Vector3::Down * GRAVITY * this->mass;
			this->gravityApplied = true;
		}
	}

	void Physics::ApplyPhysics() {
		if(!this->isActive) return;
		//float deltaTime = this->DeltaTime() * 2.0f;

		// Make the object move when the acceleration
		// is not zero

		if(this->acceleration != Vector3::Zero)
			this->velocity += (this->acceleration * 0.2f) * 0.02f;

		// Add the velocity to the position of the object

		this->position += this->velocity * 0.2f;
	}
}