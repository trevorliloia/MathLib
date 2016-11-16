#include "GameState.h"
#include "ObjectCollision.h"
#include "PlayerShip.h"

void GameState::init()
{
	player.rebuildShip(PlayerShip::ROBIN_HEAD, PlayerShip::ROBIN_BODY);
}

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	/*asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);
	
	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);*/
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);

	/*for (int i = 0; i < 2; ++i)
		asteroid[i].update(deltaTime, *this);
	
		
	for (int i = 0; i < 2; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);
	
	for (int i = 0; i < 2 - 1; ++i)
	for (int j = i + 1; j < 2; ++j)
		AsteroidCollision(asteroid[i], asteroid[j]);*/
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam, player.body, player.head);
	/*for (int i = 0; i < 2; ++i)
		asteroid[i].draw(cam);*/
}