#ifndef __SAO_ENGINE_GAMEOBJECT_LIBRARY_H__
#define __SAO_ENGINE_GAMEOBJECT_LIBRARY_H__

# ifndef __SAO_ENGINE_COLLISION_LIBRARY_H__
#  include "Collision.h"
# endif

# ifndef __SAO_ENGINE_IMAGE_LOADER_LIBRARY_H__
#  include "ImageLoader.h"
# endif

#include <glut.h>
#include <string>
using namespace std;

/**
*	GameObject library draws objects needed
*	by the developer. It includes some of the
*	basic shapes that can be found in glut.
**/

namespace GameObjectLibrary {
	using namespace CollisionLibrary;

	/**
	*	PrimitiveType class is like enum but it uses
	*	static constant strings since we don't like
	*	the developer to use numbers to specify
	*	our primitives instead the developer
	*	will use strings.
	**/

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

	/**
	*	GameObject class that handles
	*	the drawing part of the object
	**/

	class GameObject : public Collision {
	public:
		GameObject();
		GameObject(const char* filepath, int texID);

		void SetEnable(bool enable);
		void Draw(string type);
	private:
		bool active;
		bool hasTexture;
		int textureID;
		Vector3 scale;
		Color3 color;

		void DrawCube();
		void DrawTriangle();
		void DrawCone();
		void DrawTorus();
		void DrawSphere();
		void DrawPlane();

		GLuint LoadTexture(Image* image);
	protected:
	};
}

#endif