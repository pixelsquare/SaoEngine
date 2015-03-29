#include "Time.h"
#include <glut.h>

namespace TimeLibrary {
	Time::Time() {
		this->presentTime = this->previousTime = this->dt = this->elapsedTime = 0.0f;
		this->startTime = glutGet(GLUT_ELAPSED_TIME);
	}

	void Time::Observe() {
		this->presentTime = glutGet(GLUT_ELAPSED_TIME);
		this->dt = this->presentTime - this->previousTime;
		this->previousTime = this->presentTime;
	}

	float Time::DeltaTime() { return (this->dt /= 1000.0f); }

	float Time::ElapsedTime() {
		float timeNow = glutGet(GLUT_ELAPSED_TIME);
		this->elapsedTime = timeNow - this->startTime;
		this->elapsedTime /= 1000.0f;
		return this->elapsedTime;
	}

	void Time::Reset() { this->startTime = glutGet(GLUT_ELAPSED_TIME); }
}