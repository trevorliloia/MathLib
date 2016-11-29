#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
using namespace sfw;

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	strafeThrust = 0.0f;
	brakePower = 10.0f;
	stopAction = 0;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 16.0f;
	brake = 1.0f;
	speed = 100.0f;
	maxSpeed = 1000.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust += value;
}

void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust += value;
}

void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::doStrafe(float value)
{
	strafeThrust += value;
}

void SpaceshipLocomotion::update(Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addForce(perp(trans.getUp()) * speed * strafeThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);
	horzThrust = vertThrust = strafeThrust = 0;

	float CS = magnitude(rigidbody.velocity);
	rigidbody.addForce(-rigidbody.velocity * brakePower * stopAction);
	rigidbody.addForce(-(perp(trans.getUp()) * brakePower * stopAction));
	rigidbody.addTorque(-rigidbody.angularVelocity * brakePower * stopAction);
	stopAction = 0;
	//doThrust();
	//doTurn();
	//rigidbody.acceleration.x = horzThrust * speed;
	//rigidbody.acceleration.y = vertThrust * speed;

	/*if (magnitude(rigidbody.velocity) > maxSpeed)
	{

	}*/
}
