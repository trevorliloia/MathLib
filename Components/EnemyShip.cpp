#include "EnemyShip.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "shapedraw.h"


EnemyShip::EnemyShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);



	transform.m_scale = vec2{ 5,5 };
	rebuildShip(CARAPACE_HORN, CARAPACE_SHELL);
}

void EnemyShip::rebuildShip(Ships head, Hulls body)
{
	switch (head)
	{
	case EnemyShip::CARAPACE_HORN:
		enemyShip.vsize = 4;
		enemyShip.vertices[0] = { 0,0 };
		enemyShip.vertices[1] = { -2.5f,2.5f };
		enemyShip.vertices[2] = { 0,8.f };
		enemyShip.vertices[3] = { 2.5f,2.5f };

		enemyShipColor = PURPLE;
		break;
	default:
		break;
	}
	switch (body)
	{
	case EnemyShip::CARAPACE_SHELL:
		enemyHull.vsize = 6;
		enemyHull.vertices[0] = { 0,0 };
		enemyHull.vertices[1] = { 2.8f,2.8f };
		enemyHull.vertices[2] = { 5,-6.8f };
		enemyHull.vertices[3] = { 0,-5.5f };
		enemyHull.vertices[4] = { -5,-6.8f };
		enemyHull.vertices[5] = { -2.8f,2.8f };

		enemyHullColor = PURPLE;
		break;
	default:
		break;
	}
}

void EnemyShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	rebuildShip(head, body);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

}

void EnemyShip::draw(const mat3 &camera, Hulls body, Ships head)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	drawHull((camera * transform.getGlobalTransform()) * enemyHull, enemyHullColor);
	drawHull(camera * transform.getGlobalTransform() * enemyShip, enemyShipColor);
}