#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
using namespace sfw;

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 1.0f;

	speed = 100.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{

	thrust.y = value;
	/*if (getKey('W')) thrust.y = 1;
	else if (getKey('S')) thrust.y = -1;
	else thrust.y = 0;*/

}

void SpaceshipLocomotion::doTurn(float value)
{

	thrust.x = value;
	/*if (getKey('A')) thrust.x = -1;
	else if (getKey('D')) thrust.x = 1;
	else thrust.x = 0;*/
}

void SpaceshipLocomotion::update(Rigidbody & rigidbody, float delta)
{
	//doThrust();
	//doTurn();
	rigidbody.acceleration = thrust * speed;
}
