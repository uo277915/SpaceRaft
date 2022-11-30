#include "CollisionController.h"

void CollisionController::addCollider(GameObject* collider)
{
	colliders.push_back(collider);
}

void CollisionController::removeCollider(GameObject* collider)
{
	colliders.remove(collider);
}

void CollisionController::addObject(GameObject* object)
{
	objects.push_back(object);
}

void CollisionController::removeObject(GameObject* object)
{
	objects.remove(object);
}

void CollisionController::init()
{	
	objects.clear();
	colliders.clear();
}

void CollisionController::update()
{
	for (auto const& object : objects) {
		updateMove(object);
	}
}

void CollisionController::updateMove(GameObject* gameObject)
{
	float possibleXMovement = 0;
	float possibleYMovement = 0;

	// Move Right
	if (gameObject->vx != 0) {
		float newX = gameObject->x + gameObject->vx;

		for (auto const& collider : colliders) {
			if (collider->containsPoint(newX, gameObject->y)) {
				// If collision we stop
				newX = gameObject->x;
			}
		}

		gameObject->x = newX;
	}

	if (gameObject->vy != 0) {
		float newY = gameObject->y - gameObject->vy;

		for (auto const& collider : colliders) {
			if (collider->containsPoint(gameObject->x, newY)) {
				// If collision we stop
				newY = gameObject->y;
			}
		}

		gameObject->y = newY;
	}

	
}
