#include "Walls.h"
#include "GameState.h"

void Walls::build()
{
	wallTransform.m_position = center;
	//wallCollider.hull = wallSides;
	//wallCollider.box.pos = center;
	//wallCollider.box.he = size;
	//wallSides.vsize = 4;

	vec2 vertices[4];
	vertices[0] = {  -size.x, size.y};
	vertices[1] = { size.x, size.y };
	vertices[2] = { size.x, -size.y };
	vertices[3] = {  -size.x,-size.y };

	wallCollider = Collider(vertices, 4);
}

void Walls::update(float deltaTime, GameState &gs)
{
	//camera.update(deltaTime, gs);	
}

void Walls::draw(const mat3 &camera)
{
	//wallCollider.DebugDraw(camera, wallTransform);
	drawHull(camera * wallTransform.getGlobalTransform() * wallCollider.hull, GREEN);
}
