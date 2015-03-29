#ifndef __SAO_ENGINE_GAMEOBJECT_LIBRARY_H__
#define __SAO_ENGINE_GAMEOBJECT_LIBRARY_H__

# ifndef __SAO_ENGINE_COLLISION_LIBRARY_H__
#  include "Collision.h"
# endif

#include <glut.h>
#include <string>
using namespace std;

namespace GameObjectLibrary {
	using namespace CollisionLibrary;

	class PrimitiveType {
	public:
		static const string Cube;
		static const string Triangle;
		static const string Cone;
		static const string Torus;
		static const string Sphere;
		static const string Plane;

		bool operator==(const string &other);
	private:
		PrimitiveType();
	protected:
	};

	class GameObject : public Collision {
	public:
		GameObject();

		void SetEnable(bool enable);
		void Draw(string type);
	private:
		bool active;
		Vector3 scale;
		Color3 color;

		void DrawCube();
		void DrawTriangle();
		void DrawCone();
		void DrawTorus();
		void DrawSphere();
		void DrawPlane();
	protected:
	};
}

#endif