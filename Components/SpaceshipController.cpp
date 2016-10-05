#include "SpaceshipController.h"
#include "sfwdraw.h"
using namespace sfw;

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	vec2 tmpthrust;
	if (getKey('W')) tmpthrust.y = 1;
	else if (getKey('S')) tmpthrust.y = -1;
	else tmpthrust.y = 0;

	if (getKey('A')) tmpthrust.x = -1;
	else if (getKey('D')) tmpthrust.x = 1;
	else tmpthrust.x = 0;

	loco.doThrust(tmpthrust.y);
	loco.doTurn(tmpthrust.x);
}
