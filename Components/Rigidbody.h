#pragma once
#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	float torque;
	float mass, drag;
	vec2 force, impulse;
	vec2 velocity;
	float angularVelocity;
	vec2 acceleration;
	float angularAcceleration;
	void integrate(Transform &trans, float deltaTime);

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);

	void addTorque(float torque);

	Rigidbody();

	void debugDraw(const mat3 &T, const Transform &trans);
};