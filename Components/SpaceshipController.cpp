#include "SpaceshipController.h"
#include "sfwdraw.h"
using namespace sfw;

SpaceshipController::SpaceshipController(unsigned aC_L, unsigned aC_R, unsigned aC_U, unsigned aC_D, unsigned aC_B)
{
	C_L = aC_L;
	C_R = aC_R;
	C_U = aC_U;
	C_D = aC_D;
	C_B = aC_B;
}

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	float vInput = 0.0f;

	hInput -= (getKey('D'));
	hInput += (getKey('A'));

	vInput -= (getKey('S'));
	vInput += (getKey('W'));

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
}
