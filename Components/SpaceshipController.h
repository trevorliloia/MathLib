#pragma once
#include "SpaceshipLocomotion.h"

class SpaceshipController
{
public:
	unsigned C_L, C_R, C_U, C_D, C_B;
	SpaceshipController(unsigned aC_L = 'A', unsigned aC_R = 'D', unsigned aC_U = 'W', unsigned aC_D = 'S', unsigned aC_B = ' ');
	void update(SpaceshipLocomotion &loco);
};