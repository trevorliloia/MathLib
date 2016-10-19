#pragma once
#include "Rigidbody.h"
class PlanetaryMotor
{
public:
	float m_rotationspeed = 0;
	float m_maxspeed = 1;

	void update(Rigidbody &planetRbody);
};