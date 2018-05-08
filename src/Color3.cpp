#include "Color3.h"
#include <stdio.h>

namespace Color3Library {
	Color3::Color3() {
		this->R = 1.0f;
		this->G = 1.0f;
		this->B = 1.0f;
	}

	Color3::Color3(float red, float green, float blue) {
		this->R = red;
		this->G = green;
		this->B = blue;
	}

	/**
	*	Operators used in color to enable mathematical computations
	*	within the color library.
	**/

	Color3 &Color3::operator=(const Color3 &rhs) {
		this->R = rhs.R;
		this->G = rhs.G;
		this->B = rhs.B;

		return *this;
	}
	
	Color3 &Color3::operator+=(const Color3 &rhs)
	{
		this->R += rhs.R;
		this->G += rhs.G;
		this->B += rhs.B;

		return *this;
	}

	Color3 Color3::operator+(const Color3 &op)
	{
		Color3 rhs;
		rhs.R = this->R + op.R;
		rhs.G = this->G + op.G;
		rhs.B = this->B + op.B;

		return rhs;
	}

	Color3 &Color3::operator-=(const Color3 &rhs)
	{
		this->R -= rhs.R;
		this->G -= rhs.G;
		this->B -= rhs.B;

		return *this;
	}

	Color3 Color3::operator-(const Color3 &op)
	{
		Color3 rhs;
		rhs.R = this->R - op.B;
		rhs.G = this->G - op.G;
		rhs.B = this->B - op.R;

		return rhs;
	}

	Color3 &Color3::operator*=(const float scalar)
	{
		this->R *= scalar;
		this->G *= scalar;
		this->B *= scalar;

		return *this;
	}

	Color3 Color3::operator*(const float scalar)
	{
		Color3 rhs;
		rhs.R = this->R * scalar;
		rhs.G = this->G * scalar;
		rhs.B = this->B * scalar;

		return rhs;
	}

	Color3 &Color3::operator*=(const Color3 &rhs)
	{
		this->R *= rhs.R;
		this->G *= rhs.G;
		this->B *= rhs.B;

		return *this;
	}

	Color3 Color3::operator*(const Color3 &op)
	{
		Color3 rhs;
		rhs.R = this->R * op.R;
		rhs.G = this->G * op.G;
		rhs.B = this->B * op.B;

		return rhs;
	}

	Color3 &Color3::operator/=(const float scalar)
	{
		this->R /= scalar;
		this->G /= scalar;
		this->B /= scalar;

		return *this;
	}

	Color3 Color3::operator/(const float scalar)
	{
		Color3 rhs;
		rhs.R = this->R / scalar;
		rhs.G = this->G / scalar;
		rhs.B = this->B / scalar;

		return rhs;
	}

	Color3 &Color3::operator/=(const Color3 &rhs)
	{
		this->R /= rhs.R;
		this->G /= rhs.G;
		this->B /= rhs.B;

		return *this;
	}

	Color3 Color3::operator/(const Color3 &op)
	{
		Color3 rhs;
		rhs.R = this->R / op.R;
		rhs.G = this->G / op.G;
		rhs.B = this->B / op.B;

		return rhs;
	}

	/**
	*	Operators used in comparing colors
	**/

	bool Color3::operator==(const Color3 &other) {
		return (this->R == other.R && this->G == other.G && this->B == other.B);
	}

	bool Color3::operator!=(const Color3 &other) {
		return (this->R != other.R || this->G != other.G || this->B != other.B);
	}

	bool Color3::operator>(const Color3 &other) {
		return (this->R > other.R || this->G > other.G || this->B > other.B);
	}

	bool Color3::operator>=(const Color3 &other) {
		return (this->R > other.R || this->G > other.G || this->B > other.B);
	}

	bool Color3::operator<(const Color3 &other) {
		return (this->R < other.R || this->G < other.G || this->B < other.B);
	}

	bool Color3::operator<=(const Color3 &other) {
		return (this->R <= other.R || this->G <= other.G || this->B <= other.B);
	}

	/**
	*	Prints out the value of the color
	**/

	void Color3::toString() {
		printf("Color3 = (%.1f %.1f %.1f)\n", this->R, this->G, this->B);
	}

	/**
	*	Static variables used to have a quicker implementation of the library
	**/

	Color3 Color3::Red		= Color3(1.0f, 0.0f, 0.0f);
	Color3 Color3::Green	= Color3(0.0f, 1.0f, 0.0f);
	Color3 Color3::Blue		= Color3(0.0f, 0.0f, 1.0f);
	Color3 Color3::White	= Color3(1.0f, 1.0f, 1.0f);
	Color3 Color3::Yellow	= Color3(1.0f, 1.0f, 0.0f);
	Color3 Color3::Cyan		= Color3(0.0f, 1.0f, 1.0f);
	Color3 Color3::Magenta	= Color3(1.0f, 0.0f, 1.0f);
	Color3 Color3::Gray		= Color3(0.5f, 0.5f, 0.5f);
}