#ifndef __SAOENGINE_SOUND_LIBRARY_H__
#define __SAOENGINE_SOUND_LIBRARY_H__

/*
	A macro defined to export or import functions, variables, etc.
*/

#pragma region Comments
//
// This section is all about Sound playing
// Sound declaration for this section is found at Sound.cpp
//
#pragma endregion

#include <Windows.h>
#include <string>

namespace SoundLib {
	namespace Library {
		class Sound {
		public:
			Sound();
			~Sound();

			static void Play(LPCSTR name);
			static void PlayLoop(LPCSTR name);
			static void Stop();
			static void Mute(bool mute);

		private:
			bool mute;
		protected:
		};
	}
}

#endif