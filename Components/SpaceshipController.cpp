#include "SpaceshipController.h"
#include "sfwdraw.h"
using namespace sfw;

SpaceshipController::SpaceshipController(unsigned aC_L, unsigned aC_R, unsigned aC_U, unsigned aC_D, unsigned aC_B, unsigned aC_SL, unsigned aC_SR)
{
	C_L = aC_L;
	C_R = aC_R;
	C_U = aC_U;
	C_D = aC_D;
	C_B = aC_B;
	C_SL = aC_SL;
	C_SR = aC_SR;
}

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	float vInput = 0.0f;
	float strafe = 0.0f;

	strafe -= ((getKey('Q')) * 2);
	strafe += ((getKey('E')) * 2);

	hInput -= ((getKey('D')) * 1);
	hInput += ((getKey('A')) * 1);

	vInput -= ((getKey('S')) * 2.5f);
	vInput += ((getKey('W')) * 2.5f);

	float bInput = getKey(' ');
	/*if (getKey('W')) vInput = 1;
	else if (getKey('S')) vInput = -1;
	else vInput = 0;

	if (getKey('A')) hInput = -1;
	else if (getKey('D')) hInput = 1;
	else hInput = 0;*/

	loco.doStop(bInput);
	loco.doThrust(vInput);
	loco.doTurn(hInput);
	loco.doStrafe(strafe);
}
