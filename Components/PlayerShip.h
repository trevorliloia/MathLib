
#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"


class PlayerShip
{	
	
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;
	
	Hull				playerHull;
	Hull				playerShip;
	unsigned			playerHullColor;
	unsigned			playerShipColor;

	enum Ships { ROBIN_HEAD, TAURUS_HEAD, PUMA_HEAD, JAWBREAKER};
	
	enum Hulls { ROBIN_BODY, TAURUS_BODY, PUMA_BODY, BODYSLAMMER};
	Ships head;
	Hulls body;

	int shield;
	int shieldTimer;
	int health;
	
	PlayerShip();

	void rebuildShip(Ships head, Hulls body);
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 & camera, Hulls body, Ships head);
};