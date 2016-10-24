#include "Rigidbody.h"
#include "sfwdraw.h"
#include "mat3.h"
using namespace sfw;
Rigidbody::Rigidbody()
{
	mass = 1;
	force = vec2{ 0,0 };
	torque = 0;
	drag = .2f;
	velocity = vec2{ 0.0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f;
}

void Rigidbody::debugDraw(const mat3& T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	vec2 v = p + velocity;
	vec2 a = acceleration + p;
	drawLine(p.x, p.y, v.x, v.y, CYAN);
	drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}

void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	acceleration    = force / mass;
	velocity	   += acceleration * deltaTime;
	trans.m_position += velocity * deltaTime;
	force = impulse = { 0,0 };

	force = velocity*drag;

	angularAcceleration = torque / mass;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;
	trans.m_facing = trans.m_facing + angularVelocity * deltaTime;
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
