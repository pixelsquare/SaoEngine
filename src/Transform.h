#ifndef __SAO_ENGINE_TRANSFORM_LIBRARY_H__
#define __SAO_ENGINE_TRANSFORM_LIBRARY_H__

# ifndef __SAO_ENGINE_VECTOR3_LIBRARY_H__
#  include "Vector3.h"
# endif

# ifndef __SAO_ENGINE_COLOR3_LIBRARY_H__
#  include "Color3.h"
# endif

/**
*	Transform library handles all the transformations
*	needed by the gameobject and utilizes by 
*	the developer.
**/

namespace TransformLibrary {
	using namespace Vector3Library;
	using namespace Color3Library;

	class Transform : public Vector3 {
	public:
		Transform();

		void SetColor(Color3 color);
		void SetColor(float r, float g, float b);
		Color3 GetColor();

		void SetScale(Vector3 scl);
		void SetScale(float x, float y, float z);
		Vector3 GetScale();

		void SetPosition(Vector3 pos);
		void SetPosition(float x, float y, float z);
		Vector3 GetPosition();

		void SetRotation(float angle, Vector3 rotAxis);
		float GetAngle();
		Vector3 GetAxis();




	private:
		
	protected:Color3 color;
		Vector3 position;
		Vector3 scale;
		float rot; Vector3 axis;
	};
}

#endif