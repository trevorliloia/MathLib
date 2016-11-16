#include "ObjectCollision.h"


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