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
	retval.collisionNormal = copysignf(1, pdl - pdr);/*
	retval.result = (retval.penetrationDepth >= 0);
	retval.MTV = (retval.penetrationDepth * retval.collisionNormal);*/

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

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	
	CollisionDataSwept retval;

	CollisionData1D Xdis;
	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dB.x);

	CollisionData1D Ydis;
	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dB.y);

	if (Yres.entryTime < Xres.entryTime && !isinf(Xres.entryTime))
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;
	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
	}

	if (Yres.exitTime < Xres.exitTime || isinf(Xres.exitTime))
	{
		retval.exitTime = Yres.exitTime;
	}
	else
	{
		retval.exitTime = Xres.exitTime;
	}

	/*float tempLeftX = ((A.min().x - B.max().x) / (dB.x - dA.x));
	float tempRightX = ((B.min().x - A.max().x) / (dA.x - dB.x));

	float entryX = fminf(tempLeftX, tempRightX);
	float exitX = fmaxf(tempLeftX, tempRightX);

	retval.collisionNormal.x = copysignf(1, tempLeftX - tempRightX);

	float tempLeftY = ((A.min().y - B.max().y) / (dB.y - dA.y));
	float tempRightY = ((B.min().y - A.max().y) / (dA.y - dB.y));

	float entryY = fminf(tempLeftY, tempRightY);
	float exitY = fmaxf(tempLeftY, tempRightY);

	retval.collisionNormal.y = copysignf(1, tempLeftY - tempRightY);

	retval.entryTime = fminf(entryX, entryY);
	retval.exitTime = fmaxf(exitX, exitY);*/
	return retval;
}

CollisionData planeBoxCollision(const Plane & p, const AABB & b)
{
	CollisionData out;

	vec2 point1 = b.max();
	vec2 point2 = vec2{ b.min().x, b.max().y };
	vec2 point3 = b.min();
	vec2 point4 = vec2{ b.max().x, b.min().y };

	float p1Proj = dot(point1, p.dir);
	float p2Proj = dot(point2, p.dir);
	float p3Proj = dot(point3, p.dir);
	float p4Proj = dot(point4, p.dir);

	float minPoint = fminf(fminf(p1Proj, p2Proj), fminf(p3Proj, p4Proj));
	float maxPoint = fmaxf(fmaxf(p1Proj, p2Proj), fmaxf(p3Proj, p4Proj));

	float planeExtent = dot(p.pos, p.dir);

	float pd = planeExtent - minPoint;
	CollisionData1D stuff = collisionDetection1D(minPoint, maxPoint, planeExtent, INFINITY);
	out.penetrationDepth = pd;
	out.collisionNormal = vec2{ stuff.collisionNormal, stuff.collisionNormal };

	return out;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const AABB & B, const vec2 & Bvel)
{
	CollisionDataSwept retval;
	float pTL = dot(P.dir, vec2{ B.min().x, B.max().y });
	float pBR = dot(P.dir, vec2{ B.max().x, B.min().y });
	float pTR = dot(P.dir, B.max());
	float pBL = dot(P.dir, B.min());

	float pBmin = fminf(fminf(pTL, pTR), fminf(pBR, pBL));
	float pBmax = fmaxf(fmaxf(pTL, pTR), fmaxf(pBR, pBL));

	float pBvel = dot(P.dir, Bvel);

	float pPmax = dot(P.dir, P.pos);

	retval.entryTime = (pBmin - pPmax) / (0.f - pBvel);
	retval.exitTime = (pBmax - pPmax) / (0.f - pBvel);
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
