#ifndef __SAO_ENGINE_VECTOR3_LIBRARY_H__
#define __SAO_ENGINE_VECTOR3_LIBRARY_H__

# ifndef __SAO_ENGINE_MATH_LIBRARY_H__
#  include "Mathf.h"
# endif

/**
*	Vector3 Library handles all the variables needed
*	by the developer. Since the engines uses 3-dimensional
*	view, it is essential that we use XYZ to handles variables
**/

namespace Vector3Library {
	using namespace MathLibrary;

	class Vector3 {
	public:
		Vector3();
		Vector3(float x, float y, float z);

		float X; float Y; float Z;

		Vector3 &operator=(const Vector3 &rhs);
		Vector3 &operator-() const;

		Vector3 &operator+=(const Vector3 &rhs);
		Vector3 operator+(const Vector3 &op);

		Vector3 &operator-=(const Vector3 &rhs);
		Vector3 operator-(const Vector3 &op);

		Vector3 &operator*=(const float scalar);
		Vector3 operator*(const float scalar);

		Vector3 &operator*=(const Vector3 &rhs);
		Vector3 operator*(const Vector3 &op);

		Vector3 &operator/=(const float scalar);
		Vector3 operator/(const float scalar);

		Vector3 &operator/=(const Vector3 &rhs);
		Vector3 operator/(const Vector3 &op);

		bool operator==(const Vector3 &other);
		bool operator!=(const Vector3 &other);

		bool operator>(const Vector3 &other);
		bool operator>=(const Vector3 &other);

		bool operator<(const Vector3 &other);
		bool operator<=(const Vector3 &other);

		float Length();
		Vector3 &Normalize();
		float Dot(const Vector3& vec1, const Vector3& vec2);
		Vector3 Cross(const Vector3& vec1, const Vector3& vec2);
		void toString();

		static Vector3 Zero;		static Vector3 Forward;
		static Vector3 One;			static Vector3 Back;
		static Vector3 Up;			static Vector3 Left;
		static Vector3 Down;		static Vector3 Right;
	private:
	protected:
	};
}

#endif