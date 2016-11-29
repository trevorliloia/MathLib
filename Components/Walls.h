#pragma once

#include "shapes.h"
#include "sfwdraw.h"
#include "shapedraw.h"
#include "Rigidbody.h"
#include "Camera.h"
#include "Collider.h"
#include "ObjectCollision.h"

struct Walls
{
public:
	//Camera camera;
	//Hull wallSides;
	Transform wallTransform;
	Collider wallCollider;
	
	vec2 center;
	vec2 size;

	void build();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};