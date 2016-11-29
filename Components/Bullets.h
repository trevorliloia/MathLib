
#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"


class Bullets
{

public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	float speed;
	int sig;

	float timer;
	unsigned			bulletColor;

	enum Ammo { BUSTER_BLAST, PUNCH_SHOT, BURST_CANNON, PARTICLE_BEAM };
	Ammo shot;


	void buildBullet(int type, int a_sig, Transform t);
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 & camera);
};