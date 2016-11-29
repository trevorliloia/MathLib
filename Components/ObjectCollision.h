#pragma once

// Avoid including things as much as possible.
#include "Asteroid.h"
#include "PlayerShip.h"

struct Walls;


void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void PlayerWallsCollision(PlayerShip &player, Walls &walls);