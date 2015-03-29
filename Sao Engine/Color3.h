#ifndef __SAO_ENGINE_COLOR3_LIBRARY_H__
#define __SAO_ENGINE_COLOR3_LIBRARY_H__

/**
*	Color library handles all the color
*	variables needed by the gameobject.
*	It also uses math operator which
*	can be used to make cool effects.
*	It also has static variables which
*	can be used by the developer for quicker
*	implementation.
**/

namespace Color3Library {
	class Color3 {
	public:
		Color3();
		Color3(float r, float g, float b);

		float R; float G; float B;
		
		Color3 &operator=(const Color3 &rhs);

		Color3 &operator+=(const Color3 &rhs);
		Color3 operator+(const Color3 &op);

		Color3 &operator-=(const Color3 &rhs);
		Color3 operator-(const Color3 &op);

		Color3 &operator*=(const float scalar);
		Color3 operator*(const float scalar);

		Color3 &operator*=(const Color3 &rhs);
		Color3 operator*(const Color3 &op);

		Color3 &operator/=(const float scalar);
		Color3 operator/(const float scalar);

		Color3 &operator/=(const Color3 &rhs);
		Color3 operator/(const Color3 &op);

		bool operator==(const Color3 &other);
		bool operator!=(const Color3 &other);

		bool operator>(const Color3 &other);
		bool operator>=(const Color3 &other);

		bool operator<(const Color3 &other);
		bool operator<=(const Color3 &other);

		void toString();
		
		static Color3 Red;		static Color3 Yellow;	
		static Color3 Green;	static Color3 Cyan;
		static Color3 Blue;		static Color3 Magenta;
		static Color3 White;	static Color3 Gray;

	private:
	protected:
	};
}

#endif