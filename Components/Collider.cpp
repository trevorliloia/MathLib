#include "Collider.h"
#include "shapedraw.h"
#include <cmath>
#include "vec2.h"

Collider::Collider(const vec2 *verts, int size) : hull(verts, size)
{
	vec2 tmax;
	vec2 tmin;
	tmax.x = -INFINITY;
	tmax.y = -INFINITY;
	tmin.x = INFINITY;
	tmin.y = INFINITY;

	for (int i = 0; i < size; ++i)
	{
		if (verts[i].x > tmax.x)
		{
			tmax.x = verts[i].x;
		}
		if (verts[i].y > tmax.y)
		{
			tmax.y = verts[i].y;
		}
		if (verts[i].x < tmin.x)
		{
			tmin.x = verts[i].x;
		}
		if (verts[i].y > tmin.y)
		{
			tmin.y = verts[i].y;
		}
	}
	box.pos = (tmin + tmax) / 2;
	box.he = (tmax - tmin) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	drawAABB(T * trans.getGlobalTransform() * box, 0x888888ff);
	drawHull(T * trans.getGlobalTransform() * hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData retval;
	retval = boxCollision(AT.getGlobalTransform() * AC.box, BT.getGlobalTransform() * BC.box);

	if (retval.penetrationDepth >= 0)
	{
		retval = HullCollision(AT.getGlobalTransform() * AC.hull, BT.getGlobalTransform() * BC.hull);
	}

	return retval;
}

CollisionData StaticResolution(const Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);

	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;
		AR.velocity = reflect(AR.velocity, results.collisionNormal);
	}
	return CollisionData();
}
