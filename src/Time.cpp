#include "Time.h"
#include <glut.h>

namespace TimeLibrary {
	Time::Time() {
		this->presentTime = this->previousTime = this->dt = this->elapsedTime = 0.0f;
		this->startTime = glutGet(GLUT_ELAPSED_TIME);
	}

	/**
	*	Computes the current time and delta time
	*	of the game scene. It is used inside the update
	*	function.
	**/

	void Time::Observe() {
		this->presentTime = glutGet(GLUT_ELAPSED_TIME);
		this->dt = this->presentTime - this->previousTime;
		this->previousTime = this->presentTime;
	}

	/**
	*	Delta Time of the game
	**/

	float Time::DeltaTime() { return (this->dt /= 1000.0f); }

	/**
	*	Elapsed time of the game
	**/

	float Time::ElapsedTime() {
		float timeNow = glutGet(GLUT_ELAPSED_TIME);
		this->elapsedTime = timeNow - this->startTime;
		this->elapsedTime /= 1000.0f;
		return this->elapsedTime;
	}

	/**
	*	Resets the time/timer back to 0
	**/

	void Time::Reset() { this->startTime = glutGet(GLUT_ELAPSED_TIME); }
}