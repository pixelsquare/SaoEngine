#ifndef __SAO_ENGINE_COLLISION_LIBRARY_H__
#define __SAO_ENGINE_COLLISION_LIBRARY_H__

# ifndef __SAO_ENGINE_TRANSFORM_LIBRARY_H__
#  include "Transform.h"
# endif

/**
*	Collision library handles all collision done 
*	inside the game. It uses AABB collision detection
*	system. It also resizes according to the scale of
*	the gameobject used.
**/

namespace CollisionLibrary {
	using namespace TransformLibrary;

	class Collision : public Transform {
	public:
		Collision();
		void SetColliderSize(Vector3 colSize);
		void SetColliderSize(float x, float y, float z);
		Vector3 GetColliderSize();

		bool HasCollidedWith(Collision &obj);
	private:
		Vector3 colliderOffset;
	protected:
	};
}

#endif