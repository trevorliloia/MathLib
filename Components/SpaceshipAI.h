#pragma once
#include "SpaceshipLocomotion.h"

class SpaceshipAI
{
public:
	unsigned C_L, C_R, C_U, C_D, C_B, C_SL, C_SR;
	SpaceshipAI(unsigned aC_L = 'A', unsigned aC_R = 'D', unsigned aC_U = 'W', unsigned aC_D = 'S', unsigned aC_B = ' ', unsigned aC_SL = 'Q', unsigned aC_SR = 'E');
	void update(SpaceshipLocomotion &loco);
};