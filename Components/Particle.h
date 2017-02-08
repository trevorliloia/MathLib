#pragma once
#include "Transform.h"
#include "Rigidbody.h"

class Particle
{
public:
	Transform	transform;
	Rigidbody       rigidbody;

	
	// remaining life
	float lifetime;
	Particle();
	Particle(Transform a_trans, Rigidbody a_rig, float a_life);
	// Returns true if the particle is past its lifetime (lifetime < 0)
	bool isExpired() const;

	// Ticks down the lifetime and updates the rigidbody.
	void update(float deltaTime, class GameState &gs);

	// Draws the particle.
	void draw(const mat3 &camera);

	// Resets this particle's lifetime.
	void reset(float initial);
};