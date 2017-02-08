#include "Particle.h"
#include "sfwdraw.h"
using namespace sfw;

Particle Particle::makeSimpleParticle(float lifespan, vec2 pos, vec2 scale)
{
	return Particle();
}

Particle::Particle()
{

}

Particle::Particle(Transform a_trans, Rigidbody a_rig, float a_life)
{
	transform = a_trans;
	rigidbody = a_rig;
	lifetime = a_life;
}

bool Particle::isExpired() const
{
	return lifetime <= 0;
}

void Particle::update(float deltaTime, GameState & gs)
{
	if (isExpired()) { return; }
	lifetime -= deltaTime;

	rigidbody.integrate(transform, deltaTime);
}

void Particle::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	rigidbody.debugDraw(camera, transform);
	drawCircle(transform.getGlobalPosition().x, transform.getGlobalPosition().y, 10, 12, RED);
}

void Particle::reset(float initial)
{
	lifetime = initial;
}
