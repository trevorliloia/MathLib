#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	mass = 1;
	force = vec2{ 0,0 };
	torque = 0;

	velocity = vec2{ 0.0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f;
}

void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	acceleration    = force / mass;
	velocity	   += acceleration * deltaTime;
	trans.position += velocity * deltaTime;
	force = impulse = { 0,0 };

	angularAcceleration = torque / mass;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
	torque = 0;
}

void Rigidbody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void Rigidbody::addImpulse(const vec2 & a_impulse)
{
	impulse += a_impulse;
}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}
