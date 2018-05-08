#ifndef __SAO_ENGINE_TIME_LIBRARY_H__
#define __SAO_ENGINE_TIME_LIBRARY_H__

#include <time.h>

/**
*	Time library handles all the time properties
*	of the engine. It utilizes the glut time property
*	it can be used as a timer.
**/

namespace TimeLibrary { 
	class Time {
	public:
		Time();

		void Observe();
		float DeltaTime();
		float ElapsedTime();
		void Reset();

	private:
		float previousTime;
		float presentTime;
		float startTime;
		float dt; 
		float elapsedTime;
	protected:
	};
}

#endif