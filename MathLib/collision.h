#pragma once


struct CollisionData1D
{
	bool result;
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV; // penDepth * collNormal
};

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax);