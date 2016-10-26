#include "collision.h"
#include <cmath>
#include "flops.h"

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

	retval.penetrationDepth = min(Amax - Bmin, Bmax - Amin);
	//retval.collisionNormal = 
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;

	return retval;
}
