#include "PlayerShip.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "shapedraw.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts,3);
	health = 100;
	shield = 40;
	shieldTimer = 30;
	

	transform.m_scale = vec2{ 5,5 };
	rebuildShip(ROBIN_HEAD, ROBIN_BODY);
}

void PlayerShip::rebuildShip(Ships head, Hulls body)
{
	switch (head)
	{
	case PlayerShip::ROBIN_HEAD:
		playerShip.vsize = 4;
		playerShip.vertices[0] = { 0,0 };
		playerShip.vertices[1] = { -2.5f,2.5f };
		playerShip.vertices[2] = { 0,8.f };
		playerShip.vertices[3] = { 2.5f,2.5f };

		playerShipColor = RED;
		break;
	case PlayerShip::TAURUS_HEAD:
		playerShip.vsize = 6;
		playerShip.vertices[0] = { 0,0 };
		playerShip.vertices[1] = { -3.5f,3.5f };
		playerShip.vertices[2] = { -1.5f,7.5f };
		playerShip.vertices[3] = { 0,6 };
		playerShip.vertices[4] = { 1.5f,7.5f };
		playerShip.vertices[5] = { 3.5f,3.5f };

		playerShipColor = YELLOW;
		break;
	case PlayerShip::PUMA_HEAD:
		playerShip.vsize = 6;
		playerShip.vertices[0] = { 0,0 };
		playerShip.vertices[1] = { -2,2 };
		playerShip.vertices[2] = { -2,5 };
		playerShip.vertices[3] = { 0,6.5f };
		playerShip.vertices[4] = { 2,5 };
		playerShip.vertices[5] = { 2,2 };

		playerShipColor = BLUE;
		break;
	case PlayerShip::JAWBREAKER:
		playerShip.vsize = 8;
		playerShip.vertices[0] = { 0,0 };
		playerShip.vertices[1] = { -4,4 };
		playerShip.vertices[2] = { -1,3 };
		playerShip.vertices[3] = { -1,5 };
		playerShip.vertices[4] = { 0,8 };
		playerShip.vertices[5] = { 1,5 };
		playerShip.vertices[6] = { 1,3 };
		playerShip.vertices[7] = { 4,4 };

		playerShipColor = SILVER;
		break;
	default:
		break;
	}
	switch (body)
	{
	case PlayerShip::ROBIN_BODY:
		playerHull.vsize = 6;
		playerHull.vertices[0] = { 0,0 };
		playerHull.vertices[1] = { 2.8f,2.8f };
		playerHull.vertices[2] = { 5,-6.8f };
		playerHull.vertices[3] = { 0,-5.5f };
		playerHull.vertices[4] = { -5,-6.8f };
		playerHull.vertices[5] = { -2.8f,2.8f };

		playerHullColor = RED;
		break;
	case PlayerShip::TAURUS_BODY:
		playerHull.vsize = 6;
		playerHull.vertices[0] = { 0,0 };
		playerHull.vertices[1] = { 2.8f,2.8f };
		playerHull.vertices[2] = { 5,-6.8f };
		playerHull.vertices[3] = { 0,-5.5f };
		playerHull.vertices[4] = { -5,-6.8f };
		playerHull.vertices[5] = { -2.8f,2.8f };

		playerHullColor = YELLOW;
		break;
	case PlayerShip::PUMA_BODY:
		playerHull.vsize = 6;
		playerHull.vertices[0] = { 0,0 };
		playerHull.vertices[1] = { 2.8f,2.8f };
		playerHull.vertices[2] = { 5,-6.8f };
		playerHull.vertices[3] = { 0,-5.5f };
		playerHull.vertices[4] = { -5,-6.8f };
		playerHull.vertices[5] = { -2.8f,2.8f };

		playerHullColor = BLUE;
		break;
	case PlayerShip::BODYSLAMMER:
		playerHull.vsize = 6;
		playerHull.vertices[0] = { 0,0 };
		playerHull.vertices[1] = { 2.8f,2.8f };
		playerHull.vertices[2] = { 5,-6.8f };
		playerHull.vertices[3] = { 0,-5.5f };
		playerHull.vertices[4] = { -5,-6.8f };
		playerHull.vertices[5] = { -2.8f,2.8f };

		playerHullColor = SILVER;
		break;
	default:
		break;
	}
}

void PlayerShip::update(float deltaTime, GameState &gs)
{
	if (shieldTimer < 30)
	{
		shieldTimer += deltaTime;
	}

	if (shieldTimer >= 30 && shield < 40)
	{
		shield += deltaTime;
		if (shield > 40)
		{
			shield = 40;
		}
	}

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
	drawHull((camera * transform.getGlobalTransform()) * playerHull, playerHullColor);
	drawHull(camera * transform.getGlobalTransform() * playerShip, playerShipColor);
}