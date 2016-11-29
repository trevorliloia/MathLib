#include "Bullets.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "shapedraw.h"



void Bullets::buildBullet(int type, int a_signature, Transform t)
{
	transform = t;
	switch (type)
	{
	case 1:
		shot = BUSTER_BLAST;
		collider.hull.vsize = 4;
		collider.hull.vertices[0] = { 0,0 };
		collider.hull.vertices[1] = { .5f,-.8f };
		collider.hull.vertices[2] = { 0,-1.5f };
		collider.hull.vertices[3] = { -.5f,-.8f };
		bulletColor = RED;
		speed = 300;
		timer = 3.f;
		rigidbody.drag = 0;
		rigidbody.addImpulse(transform.getUp() * speed);
		break;
	case 2:
		shot = PUNCH_SHOT;
		collider.hull.vsize = 4;
		collider.hull.vertices[0] = { 0,0 };
		collider.hull.vertices[1] = { .5f,-.8f };
		collider.hull.vertices[2] = { 0,-1.5f };
		collider.hull.vertices[3] = { -.5f,-.8f };
		bulletColor = GREEN;
		speed = 300;
		timer = 3.f;
		rigidbody.drag = 0;
		rigidbody.addImpulse(transform.getUp() * speed);
		break;
	case 3:
		shot = BURST_CANNON;
		collider.hull.vsize = 4;
		collider.hull.vertices[0] = { 0,0 };
		collider.hull.vertices[1] = { .5f,-.8f };
		collider.hull.vertices[2] = { 0,-1.5f };
		collider.hull.vertices[3] = { -.5f,-.8f };
		bulletColor = BLUE;
		speed = 300;
		timer = 3.f;
		rigidbody.drag = 0;
		rigidbody.addImpulse(transform.getUp() * speed);
		break;
	case 4:
		shot = PARTICLE_BEAM;
		collider.hull.vsize = 4;
		collider.hull.vertices[0] = { 0,0 };
		collider.hull.vertices[1] = { .5f,-.8f };
		collider.hull.vertices[2] = { 0,-1.5f };
		collider.hull.vertices[3] = { -.5f,-.8f };
		bulletColor = WHITE;
		speed = 300;
		timer = 3.f;
		rigidbody.drag = 0;
		rigidbody.addImpulse(transform.getUp() * speed);
		break;
	default:
		break;
	}
	sig = a_signature;


	
}

void Bullets::update(float deltaTime, GameState & gs)
{
	timer -= deltaTime;

	if (timer < 0) return;
	//rigidbody.addForce(transform.getUp() * speed);
	rigidbody.integrate(transform, deltaTime);
}

void Bullets::draw(const mat3 & camera)
{
	if (timer < 0) return;
	//transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	drawHull(camera * transform.getGlobalTransform() * collider.hull, bulletColor);
	//rigidbody.debugDraw(camera, transform);
}
