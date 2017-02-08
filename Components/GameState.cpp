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
	option.rebuildShip(PlayerShip::ROBIN_HEAD, PlayerShip::ROBIN_BODY);
	enemy.rebuildShip(EnemyShip::CARAPACE_HORN, EnemyShip::CARAPACE_SHELL);
}

void GameState::play()
{
	//printf("%s",sfw::getGamepadName(0));

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

	spawner.spawnInterval = 1.0f / 2;
	spawner.maxParticles = 20;

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
	enemytimer-= deltaTime;
	
	// loop it if there is more than one
	for (int i = 0; i < MAX_WALLS; ++i)
	{
		walls[i].update(deltaTime, *this);

		// loop it if there is more than one
		PlayerWallsCollision(player, walls[i]);
		EnemyWallsCollision(enemy, walls[i]);
	}
	

	
		
	if (!(sfw::getGamepadButton(0, XBOX360_BUTTON_A) || sfw::getKey('H')))
	{
		press = false;
	}
	if ((sfw::getGamepadButton(0, XBOX360_BUTTON_A) || sfw::getKey('H')) && press == false)
	{
		spawnBullet(player.transform, ammotype, 1);
		press = true;
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
	vec2 fwd = enemy.transform.getUp();
	vec2 dir = normal(player.transform.getGlobalPosition() - enemy.transform.getGlobalPosition());

	if (dot(fwd, dir) > .5f && dist(player.transform.getGlobalPosition(), enemy.transform.getGlobalPosition()) < 350 && enemytimer <= 0)
	{
		spawnBullet(enemy.transform, 1, 2);
		enemytimer = 20;
	}
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		bullets[i].update(deltaTime, *this);
		PlayerBulletCollision(player, bullets[i]);
		EnemyBulletCollision(enemy, bullets[i]);
	}
	
		
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
	switch (type)
	{
	case 1:
		bullets[shots % MAX_BULLETS].buildBullet(type, sig, t);
		++shots;
		break;
	case 2:
		if (player.punchAmmo > 0 && press == false)
		{
			player.punchAmmo -= 1;
			bullets[shots % MAX_BULLETS].buildBullet(type, sig, t);
			++shots; 
		}
		break;
	case 3:
		if (player.burstAmmo > 0 && press == false)
		{
			player.burstAmmo -= 1;
			bullets[shots % MAX_BULLETS].buildBullet(type, sig, t);
			++shots;
		}
		break;
	case 4:
		if (player.beamAmmo > 0 && press == false)
		{
			player.beamAmmo -= 1;
			bullets[shots % MAX_BULLETS].buildBullet(type, sig, t);
			++shots;
		}
		break;
	default:
		break;
	}
	
}
