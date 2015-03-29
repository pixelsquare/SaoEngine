#ifndef __SAO_ENGINE_MATH_LIBRARY_H__
#define __SAO_ENGINE_MATH_LIBRARY_H__

#include <math.h>
#include <array>

namespace MathLibrary {
	class Math{
	public:
		Math();

		static float Abs(float f);
		static float Acos(float f);
		static float Asin(float f);
		static float Atan(float f);
		static float Atan2(float a, float b);
		static float Exp(float f);
		static float Cos(float f);
		static float Sin(float f);
		static float Tan(float f);
		static float Log(float f);
		static float Sqrt(float f);
		static float Pow(float f, float p);
		static double Ceil(double f);
		static double Floor(double f);
		static int Random(int min, int max);

		static double PI;
		static float DegToRad;
		static float RadToDeg;

	private:
		~Math();
	protected:
	};
}

#endif