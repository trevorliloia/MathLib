#pragma once
#include "Rigidbody.h"

class SpaceshipLocomotion
{
	vec2 thrust = { 0,0 };
	float vertThrust;
	float horzThrust;
	float thrustSpeed;

	float turn;
	float maxTurn;
	float turnSpeed;

	float speed;

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	void update(Rigidbody &rigidbody, float delta);
};