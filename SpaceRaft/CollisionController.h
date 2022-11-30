#pragma once
#include "GameObject.h"
class CollisionController
{
public:
	void init();

	// Colliders
	void addCollider(GameObject* collider);
	void removeCollider(GameObject* collider);

	// Objects
	void addObject(GameObject* collider);
	void removeObject(GameObject* collider);

	// Update
	void update();
	void updateMove(GameObject* gameObject);

	// Lists
	list<GameObject*> colliders;
	list<GameObject*> objects;
};

