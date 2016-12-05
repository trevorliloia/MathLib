#include "ObjectCollision.h"
#include "Walls.h"


void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		player.transform.m_scale = (player.transform.m_scale * .9f);
	}
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void PlayerWallsCollision(PlayerShip & player, Walls & walls)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			walls.wallTransform, walls.wallCollider);

	if (result.penetrationDepth >= 0)
	{
	//	player.transform.m_scale = (player.transform.m_scale * .9f);
	}
}

void EnemyWallsCollision(EnemyShip & enemy, Walls & walls)
{
	CollisionData result =
		StaticResolution(enemy.transform, enemy.rigidbody, enemy.collider,
			walls.wallTransform, walls.wallCollider);

	if (result.penetrationDepth >= 0)
	{
		
	}
}

void PlayerBulletCollision(PlayerShip & player, Bullets & bullet)
{
	if (bullet.sig == 2)
	{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			bullet.transform, bullet.rigidbody, bullet.collider);

	
		if (result.penetrationDepth >= 0)
		{
			bullet.timer = 0;
			bullet.transform.m_position = vec2{ -500,-500 };
			
			if (player.shield > 0)
			{
				player.shield -= 20;
				player.shieldTimer = 0;
			}
			else
			{
				player.health -= 20;
				player.shieldTimer = 0;
			}
		}

	}
}

void EnemyBulletCollision(EnemyShip & enemy, Bullets & bullet)
{
	if (bullet.sig == 1)
	{
	CollisionData result =
		DynamicResolution(enemy.transform, enemy.rigidbody, enemy.collider,
			bullet.transform, bullet.rigidbody, bullet.collider);

	
		if (result.penetrationDepth >= 0)
		{
			bullet.timer = 0;
			bullet.transform.m_position = vec2{ -500,-500 };
		}
	}
}
