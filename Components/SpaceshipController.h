#pragma once
#include "SpaceshipLocomotion.h"

class SpaceshipController
{
public:
	unsigned C_L, C_R, C_U, C_D, C_B;
	SpaceshipController(unsigned aC_L, unsigned aC_R, unsigned aC_U, unsigned aC_D, unsigned aC_B);
	void update(SpaceshipLocomotion &loco);
};