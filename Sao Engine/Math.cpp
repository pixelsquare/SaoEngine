#include "Math.h"

namespace MathLibrary {
	Math::Math() { }

	Math::~Math() { }

	float Math::Abs(float f) { return abs(f); }

	float Math::Acos(float f) { return acos(f); }

	float Math::Asin(float f) { return asin(f); }

	float Math::Atan(float f) { return atan(f); }

	float Math::Atan2(float a, float b) { return atan2(a, b); }

	float Math::Exp(float f) { return exp(f); }

	float Math::Cos(float f) { return cos(f); }

	float Math::Sin(float f) { return sin(f); }

	float Math::Tan(float f) { return tan(f); }

	float Math::Log(float f) { return log(f); }

	float Math::Sqrt(float f) { return sqrt(f); }

	float Math::Pow(float f, float p) { return pow(f, p); }

	double Math::Ceil(double f) { return ceil(f); }

	double Math::Floor(double f) { return floor(f); }

	int Math::Random(int min, int max) { return (rand() % (max - min)) + min; }

	double Math::PI = 3.14159265358979;
	float Math::DegToRad = Math::PI / 180.0f;
	float Math::RadToDeg = 180.0f / Math::PI;
}