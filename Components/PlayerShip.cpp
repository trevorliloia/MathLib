#include "PlayerShip.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "shapedraw.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts,3);

	

	transform.m_scale = vec2{ 5,5 };
	rebuildShip(ROBIN_HEAD, ROBIN_BODY);
}

void PlayerShip::rebuildShip(Ships head, Hulls body)
{
	switch (head)
	{
	case PlayerShip::ROBIN_HEAD:
		//playerShip.position = transform.getGlobalPosition();
		playerShip.vsize = 4;
		playerShip.vertices[0] = { 0,0 };
		playerShip.vertices[1] = { -5,5 };
		playerShip.vertices[2] = { 0,15 };
		playerShip.vertices[3] = { 5,5 };

		playerShipColor = RED;
		break;
	case PlayerShip::TAURUS_HEAD:
		break;
	case PlayerShip::PUMA_HEAD:
		break;
	case PlayerShip::JAWBREAKER:
		break;
	default:
		break;
	}
	switch (body)
	{
	case PlayerShip::ROBIN_BODY:
		break;
	case PlayerShip::TAURUS_BODY:
		break;
	case PlayerShip::PUMA_BODY:
		break;
	case PlayerShip::BODYSLAMMER:
		break;
	default:
		break;
	}
}

void PlayerShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	rebuildShip(head, body);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

}

void PlayerShip::draw(const mat3 &camera, Hulls body, Ships head)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	//drawHull((camera * transform.getGlobalTransform()) * playerHull, playerHullColor);
	drawHull(camera * transform.getGlobalTransform() * playerShip, playerShipColor);
}