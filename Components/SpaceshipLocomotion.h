#pragma once
#include "Rigidbody.h"

class SpaceshipLocomotion
{
	vec2 thrust = { 0,0 };
	float vertThrust;
	float horzThrust;
	float strafeThrust;
	float thrustSpeed;
	float stopAction;
	float brakePower;
	float turn;
	float maxTurn;
	float turnSpeed;
	float brake;
	float speed;
	float maxSpeed;
public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);
	void doStrafe(float value);

	void update(Transform &trans, Rigidbody &rigidbody);
};