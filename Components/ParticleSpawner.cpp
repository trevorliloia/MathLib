#include "ParticleSpawner.h"
#include "GameState.h"

ParticleSpawner::ParticleSpawner()
{
	spawnTimer = 0;
	particleCount = 0;
}

ParticleSpawner::ParticleSpawner(float a_interval, unsigned int a_max) : ParticleSpawner()
{
	spawnInterval = a_interval;
	maxParticles = a_max;
	spawnTimer = spawnInterval;
}

ParticleSpawner::~ParticleSpawner()
{
}

void ParticleSpawner::update(float deltaTime, GameState & gs)
{
	spawnTimer -= deltaTime;

	if (spawnTimer <= 0)
	{
		Particle temp;
		particleCount++;
		temp.rigidbody.addForce({ 0,500 });
		temp.lifetime = 2.5f;
		temp.transform.m_scale = { 50,50 };
		particlePool.push(temp);
		spawnTimer = spawnInterval;
	}
	for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter)
	{
		(*iter).update(deltaTime, gs);

		if ((*iter).isExpired())
		{
			particleCount--;
			iter.free();
		}
	}
}

void ParticleSpawner::draw(const mat3 & camera)
{

}
