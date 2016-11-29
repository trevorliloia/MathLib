#include "GameState.h"
#include "ObjectCollision.h"
#include "PlayerShip.h"
#include "sfwdraw.h"
#include "Walls.h"
#include "Bullets.h"

void GameState::init()
{
	player.rebuildShip(PlayerShip::ROBIN_HEAD, PlayerShip::ROBIN_BODY);
}

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	
	walls[0].center = { 300,300 };
	walls[0].size   = {  10, 50 };
	walls[0].build();

	walls[0].wallTransform.m_facing = 45;


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


	// loop it if there is more than one
	walls[0].update(deltaTime, *this);

	// loop it if there is more than one
	PlayerWallsCollision(player, walls[0]);
	if (!sfw::getKey('H'))
	{
		press = false;
	}
	if (sfw::getKey('H') && press == false)
	{
		press = true;
		spawnBullet(player.transform, ammotype, 1);
	}
	if (sfw::getKey(KEY_UP))
	{
		ammotype = 1;
		ammoColor = RED;
	}
	else if (sfw::getKey(KEY_DOWN))
	{
		ammotype = 2;
		ammoColor = GREEN;
	}
	else if (sfw::getKey(KEY_LEFT))
	{
		ammotype = 3;
		ammoColor = BLUE;
	}
	else if (sfw::getKey(KEY_RIGHT))
	{
		ammotype = 4;
		ammoColor = WHITE;
	}
	for (int i = 0; i < MAX_BULLETS; ++i)
		bullets[i].update(deltaTime, *this);
	
		
	/*for (int i = 0; i < 2; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);
	
	for (int i = 0; i < 2 - 1; ++i)
	for (int j = i + 1; j < 2; ++j)
		AsteroidCollision(asteroid[i], asteroid[j]);*/
}

void GameState::draw()
{
	
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam, player.body, player.head);

	walls[0].draw(cam);

	for (int i = 0; i < MAX_BULLETS; ++i)
		bullets[i].draw(cam);
	/*for (int i = 0; i < 2; ++i)
		asteroid[i].draw(cam);*/
}

void GameState::spawnBullet(Transform t, int type, int sig)
{
	bullets[shots % MAX_BULLETS].buildBullet(type, sig, t);
	++shots;
}
