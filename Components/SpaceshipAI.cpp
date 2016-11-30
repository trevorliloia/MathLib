#include "SpaceshipAI.h"
#include "sfwdraw.h"
#include <iostream>

using namespace sfw;

SpaceshipAI::SpaceshipAI(unsigned aC_L, unsigned aC_R, unsigned aC_U, unsigned aC_D, unsigned aC_B, unsigned aC_SL, unsigned aC_SR)
{
	C_L = aC_L;
	C_R = aC_R;
	C_U = aC_U;
	C_D = aC_D;
	C_B = aC_B;
	C_SL = aC_SL;
	C_SR = aC_SR;
}

void SpaceshipAI::update(SpaceshipLocomotion & loco, Transform player, Transform enemy)
{
	float hInput = 0.0f;
	float vInput = 0.0f;
	float strafe = 0.0f;

	
	vec2 fwd = enemy.getUp();
	vec2 dir = normal(player.getGlobalPosition() - enemy.getGlobalPosition());

	if(dot(fwd,dir) > .7f && dist(player.getGlobalPosition(), enemy.getGlobalPosition()) > 350)
	{
		vInput++;
	}
	else if(dot(fwd,dir) > .7f && dist(player.getGlobalPosition(), enemy.getGlobalPosition()) < 150)
	{
		vInput--;
	}

	hInput = -dot(perp(fwd), dir);

	/*
	if (dot(perp(fwd), dir) < 0 && dot(fwd, dir) < .97f)
		hInput+=2;
    // turn left
	if (dot(perp(fwd), dir) > 0 && dot(fwd, dir) < .97f)
		hInput-=2;
		*/
    // turn right

	if (dist(player.getGlobalPosition(), enemy.getGlobalPosition()) > 350)
	{
		vInput++;
		printf("++\n");
	}
	else if (dist(player.getGlobalPosition(), enemy.getGlobalPosition()) < 150)
	{
		vInput--;
		printf("--\n");
	}
	

	/*strafe -= ((getKey('Q')) * 2);
	strafe += ((getKey('E')) * 2);

	hInput -= ((getKey('D')) * 1);
	hInput += ((getKey('A')) * 1);

	vInput -= ((getKey('S')) * 2.5f);
	vInput += ((getKey('W')) * 2.5f);*/

	//hInput -= ((getGamepadAxis(0, XBOX360_AXIS_LSTICK_HORIZONTAL, GAMEPAD_DEADZONE_THRESHOLD)) * .75f);

	//strafe += ((getGamepadButton(0, XBOX360_BUTTON_R)) * 2.5f);
	//strafe -= ((getGamepadButton(0, XBOX360_BUTTON_L)) * 2.5f);

	//vInput -= ((getGamepadAxis(0, XBOX360_AXIS_LSTICK_VERTICAL, GAMEPAD_DEADZONE_THRESHOLD)) * 2.5f);

	float bInput = getKey(' ') + getGamepadButton(0, XBOX360_BUTTON_B);
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
