#include "PlanetaryMotor.h"


void PlanetaryMotor::update(Rigidbody & planetRbody)
{
	planetRbody.angularVelocity = m_rotationspeed;
	if (m_rotationspeed >= m_maxspeed)
		m_rotationspeed = m_maxspeed;
}
