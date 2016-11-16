#include "Collider.h"
#include "shapedraw.h"
#include <cmath>
#include "vec2.h"
Collider::Collider()
{
}
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
		if (verts[i].y < tmin.y)
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

//CollisionData StaticResolution(const Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC)
//{
//	CollisionData results = ColliderCollision(AT, AC, BT, BC);
//
//	if (results.penetrationDepth >= 0)
//	{
//		vec2 MTV = results.penetrationDepth * results.collisionNormal;
//		AT.m_position -= MTV;
//		AR.velocity = reflect(AR.velocity, results.collisionNormal);
//	}
//	return CollisionData();
//}
//
//CollisionData DynamicResolution(const Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
//{
//	CollisionData results = ColliderCollision(AT, AC, BT, BC);
//	if (results.penetrationDepth >= 0)
//	{
//		vec2 MTV = results.penetrationDepth * results.collisionNormal;
//		float am = magnitude(AR.mass * AR.velocity);
//		float bm = magnitude(BR.mass * BR.velocity);
//		float cm = am + bm;
//
//		AT.m_position -= MTV * (1 - am / cm);
//		BT.m_position -= MTV * (1 - bm / cm);
//
//		vec2 A = AR.velocity;
//		float P = AR.mass;
//		vec2 X;
//
//		vec2 B = BR.velocity;
//		float Q = BR.mass;
//		vec2 Y;
//
//		float E = bounciness;
//
//		X = (A*P + B*Q + -E*(A - B)*Q) / (Q - P);
//		Y = E*(A - B) + X;
//
//		AR.velocity = -magnitude(X) * results.collisionNormal;
//		BR.velocity = magnitude(Y) * results.collisionNormal;
//		/*
//		a | a's inital velocity
//		p | a's mass
//		x | a's final velocity
//
//		b | b's inital velocity
//		q | b's mass
//		y | b's final velocity
//
//		e | coefficient restitution
//
//		a*p + b*q = x*p + y*q | conservation of momentum
//		x - y = -e(a - b)     | linear collision
//
//		x = [a*p + b*q + (-e(a - b))*q]/(q+p)
//		y = e(a - b) +  [a*p + b*q + (-e(a - b))*q]/(q+p)
//
//		*/
//	}
//
//	return results;
//}

CollisionData StaticResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
	const Transform & BT, const Collider & BC,
	float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness;
	}

	return results;
}



CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
	Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		///////////////////////////////////////////////
		/////// Correction
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		// As long as the MTV is applied, in some way,
		// You will avoid jitter

		float am = magnitude(AR.mass * AR.velocity); //  9
		float bm = magnitude(BR.mass * BR.velocity); //  1
		float cm = am + bm;							 // 10

		AT.m_position -= MTV * (1 - am / cm); // 1-9/10 : 1/10
		BT.m_position += MTV * (1 - bm / cm); // 1-1/10 : 9/10

											  //////////////////////////////////////////////////
											  /// Resolution
		vec2  A = AR.velocity;		// Velocity for A
		float P = AR.mass;			// Mass for A
		vec2  X;					// final velocity for A

		vec2  B = BR.velocity;		// Velocity for B
		float Q = BR.mass;			// mass for B
		vec2  Y;					// final velocity for Y

		float E = bounciness;		// coefficient of restitution

									//// Solve the system of linear equations!
									//A * P + B * Q = X * P + Y * Q   : conservation of momentum
									//X - Y = -E(A - B)    			  : linear collision

		X = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);
		Y = E*(A - B) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}
	return results;
}

