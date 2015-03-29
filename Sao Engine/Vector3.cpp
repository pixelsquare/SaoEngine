#include "Vector3.h"

namespace Vector3Library {
	Vector3::Vector3() {
		this->X = 0.0f;
		this->Y = 0.0f;
		this->Z = 0.0f;
	}

	Vector3::Vector3(float x, float y, float z) {
		this->X = x;
		this->Y = y;
		this->Z = z;
	}

	/**
	*	Vector3 operators used to implement 
	*	mathematical computations using the library.
	**/

	Vector3 &Vector3::operator=(const Vector3 &rhs)
	{
		this->X = rhs.X;
		this->Y = rhs.Y;
		this->Z = rhs.Z;

		return *this;
	}

	Vector3 &Vector3::operator-() const {
		Vector3 *tmp = new Vector3;
		*tmp = *this;
		tmp->X = -tmp->X;
		tmp->Y = -tmp->Y;
		tmp->Z = -tmp->Z;
		return *tmp;
	}

	Vector3 &Vector3::operator+=(const Vector3 &rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
		this->Z += rhs.Z;

		return *this;
	}

	Vector3 Vector3::operator+(const Vector3 &op)
	{
		Vector3 rhs;
		rhs.X = this->X + op.X;
		rhs.Y = this->Y + op.Y;
		rhs.Z = this->Z + op.Z;

		return rhs;
	}

	Vector3 &Vector3::operator-=(const Vector3 &rhs)
	{
		this->X -= rhs.X;
		this->Y -= rhs.Y;
		this->Z -= rhs.Z;

		return *this;
	}

	Vector3 Vector3::operator-(const Vector3 &op)
	{
		Vector3 rhs;
		rhs.X = this->X - op.X;
		rhs.Y = this->Y - op.Y;
		rhs.Z = this->Z - op.Z;

		return rhs;
	}

	Vector3 &Vector3::operator*=(const float scalar)
	{
		this->X *= scalar;
		this->Y *= scalar;
		this->Z *= scalar;

		return *this;
	}

	Vector3 Vector3::operator*(const float scalar)
	{
		Vector3 rhs;
		rhs.X = this->X * scalar;
		rhs.Y = this->Y * scalar;
		rhs.Z = this->Z * scalar;

		return rhs;
	}

	Vector3 &Vector3::operator*=(const Vector3 &rhs)
	{
		this->X *= rhs.X;
		this->Y *= rhs.Y;
		this->Z *= rhs.Z;

		return *this;
	}

	Vector3 Vector3::operator*(const Vector3 &op)
	{
		Vector3 rhs;
		rhs.X = this->X * op.X;
		rhs.Y = this->Y * op.Y;
		rhs.Z = this->Z * op.Z;

		return rhs;
	}

	Vector3 &Vector3::operator/=(const float scalar)
	{
		this->X /= scalar;
		this->Y /= scalar;
		this->Z /= scalar;

		return *this;
	}

	Vector3 Vector3::operator/(const float scalar)
	{
		Vector3 rhs;
		rhs.X = this->X / scalar;
		rhs.Y = this->Y / scalar;
		rhs.Z = this->Z / scalar;

		return rhs;
	}

	Vector3 &Vector3::operator/=(const Vector3 &rhs)
	{
		this->X /= rhs.X;
		this->Y /= rhs.Y;
		this->Z /= rhs.Z;

		return *this;
	}

	Vector3 Vector3::operator/(const Vector3 &op)
	{
		Vector3 rhs;
		rhs.X = this->X / op.X;
		rhs.Y = this->Y / op.Y;
		rhs.Z = this->Z / op.Z;

		return rhs;
	}

	/**
	*	Operators used to compare 2 vectors
	**/

	bool Vector3::operator==(const Vector3 &other) { return (this->X == other.X && this->Y == other.Y && this->Z == other.Z); }

	bool Vector3::operator!=(const Vector3 &other) { return (this->X != other.X || this->Y != other.Y || this->Z != other.Z); }

	bool Vector3::operator>(const Vector3 &other) {	return (this->X > other.X || this->Y > other.Y || this->Z > other.Z); }

	bool Vector3::operator>=(const Vector3 &other) { return (this->X > other.X || this->Y > other.Y || this->Z > other.Z); }

	bool Vector3::operator<(const Vector3 &other) {	return (this->X < other.X || this->Y < other.Y || this->Z < other.Z); }

	bool Vector3::operator<=(const Vector3 &other) { return (this->X <= other.X || this->Y <= other.Y || this->Z <= other.Z); }

	/**
	*	Returns the length of the vector
	**/

	float Vector3::Length() {
		return sqrtf(this->X * this->X + this->Y * this->Y + this->Z * this->Z);
	}

	/**
	*	Normalizes the vector
	**/

	Vector3 &Vector3::Normalize() {
		return (*this /= this->Length());
	}

	/**
	*	Returns the Dot product of 2 vectors
	**/

	float Vector3::Dot(const Vector3& vec1, const Vector3& vec2) {
		return vec1.X * vec2.X + vec1.Y * vec2.Y + vec1.Z * vec2.Z;
	}

	/**
	*	Returns the Cross product of 2 vectors
	**/

	Vector3 Vector3::Cross(const Vector3& vec1, const Vector3& vec2) {
		return Vector3(
			vec1.Y * vec2.Z - vec1.Z * vec2.Y,
			vec1.Z * vec2.X - vec1.X * vec2.Z,
			vec1.X * vec2.Y * vec1.Y * vec2.X);
	}

	/**
	*	Prints out the vector
	**/

	void Vector3::toString() {
		printf("%f %f %f\n", this->X, this->Y, this->Z);
	}

	/**
	*	Static function declaration for the developers
	*	quick implementation to the game scene
	**/

	Vector3 Vector3::Zero		= Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Vector3::One		= Vector3(1.0f, 1.0f, 1.0f);
	Vector3 Vector3::Up			= Vector3(0.0f, 1.0f, 0.0f);
	Vector3 Vector3::Down		= Vector3(0.0f, -1.0f, 0.0f);
	Vector3 Vector3::Forward	= Vector3(0.0f, 0.0f, 1.0f);
	Vector3 Vector3::Back		= Vector3(0.0f, 0.0f, -1.0f);
	Vector3 Vector3::Right		= Vector3(1.0f, 0.0f, 0.0f);
	Vector3 Vector3::Left		= Vector3(-1.0f, 0.0f, 0.0f);
}