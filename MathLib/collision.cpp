#include "collision.h"
#include <cmath>
#include "flops.h"
#include <time.h>
#include "shapes.h"

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;
	float pdl = Bmax - Amin;
	float pdr = Amax - Bmin;
	retval.penetrationDepth = min(pdr, pdl);
	retval.collisionNormal = copysignf(1, pdl - pdr);
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;

	return retval;
}



SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	retval.entryTime = (Amin - Bmax) / (Bvel - Avel);
	retval.exitTime = (Bmin - Amax) / (Avel - Bvel);
	
	retval.collisionNormal = copysignf(1, retval.entryTime - retval.exitTime);

	return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData1D XCD = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D YCD = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);
	CollisionData retval;
	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *YCD.collisionNormal;
	}

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}

bool SweptCollisionData1D::result() const
{
	return false;
}
