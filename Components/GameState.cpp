#include "GameState.h"
#include "ObjectCollision.h"
#include "PlayerShip.h"
#include "sfwdraw.h"
#include "Walls.h"
#include "Bullets.h"
#include <iostream>

void GameState::init()
{
	player.rebuildShip(PlayerShip::ROBIN_HEAD, PlayerShip::ROBIN_BODY);
	enemy.rebuildShip(EnemyShip::CARAPACE_HORN, EnemyShip::CARAPACE_SHELL);
}

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	enemy.transform.m_position = vec2{ 400, 200 };
	enemy.transform.m_facing = 0;

	
	walls[0].center = { 0,350 };
	walls[0].size   = {  10, 350 };
	walls[0].wallTransform.m_facing = 0;

	walls[1].center = { 700,350 };
	walls[1].size = { 10, 350 };
	walls[1].wallTransform.m_facing = 0;

	walls[2].center = { 350,700 };
	walls[2].size = { 350, 10 };
	walls[2].wallTransform.m_facing = 0;

	walls[3].center = { 350,0 };
	walls[3].size = { 350, 10 };
	walls[3].wallTransform.m_facing = 0;

	walls[4].center = { 350,350 };
	walls[4].size = { 10, 250 };
	walls[4].wallTransform.m_facing = 0;

	walls[5].center = { 350,350 };
	walls[5].size = { 10, 250 };
	walls[5].wallTransform.m_facing = 1.5708f;

	for (int i = 0; i < MAX_WALLS; ++i)
	{
		walls[i].build();
	}
	

	


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
	enemy.update(deltaTime, *this);
	camera.update(deltaTime, *this);


	// loop it if there is more than one
	for (int i = 0; i < MAX_WALLS; ++i)
	{
		walls[i].update(deltaTime, *this);

		// loop it if there is more than one
		PlayerWallsCollision(player, walls[i]);
		EnemyWallsCollision(enemy, walls[i]);
	}
	

	if (sfw::getGamepadPresent(0))
	{
		printf(sfw::getGamepadName(0));
	}
	if (!(sfw::getGamepadButton(0, XBOX360_BUTTON_A) || sfw::getKey('H')))
	{
		press = false;
	}
	if ((sfw::getGamepadButton(0, XBOX360_BUTTON_A) || sfw::getKey('H')) && press == false)
	{
		press = true;
		spawnBullet(player.transform, ammotype, 1);
	}
	if (sfw::getKey(KEY_UP) || sfw::getGamepadButton(0, XBOX360_DPAD_UP))
	{
		ammotype = 1;
		ammoColor = RED;
	}
	else if (sfw::getKey(KEY_DOWN) || sfw::getGamepadButton(0, XBOX360_DPAD_DOWN))
	{
		ammotype = 2;
		ammoColor = GREEN;
	}
	else if (sfw::getKey(KEY_LEFT) || sfw::getGamepadButton(0, XBOX360_DPAD_LEFT))
	{
		ammotype = 3;
		ammoColor = BLUE;
	}
	else if (sfw::getKey(KEY_RIGHT) || sfw::getGamepadButton(0, XBOX360_DPAD_RIGHT))
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
	enemy.draw(cam, enemy.body, enemy.head);

	for (int i = 0; i < MAX_WALLS; ++i)
	{
		walls[i].draw(cam);
	}
	

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
