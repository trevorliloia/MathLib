#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipAI.h"
#include "SpaceshipLocomotion.h"


class EnemyShip
{

public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceshipController controller;
	SpaceshipAI brain;
	SpaceshipLocomotion locomotion;

	Hull				enemyHull;
	Hull				enemyShip;
	unsigned			enemyHullColor;
	unsigned			enemyShipColor;

	enum Ships { CARAPACE_HORN };

	enum Hulls { CARAPACE_SHELL };
	Ships head;
	Hulls body;

	EnemyShip();

	void rebuildShip(Ships head, Hulls body);
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 & camera, Hulls body, Ships head);
};